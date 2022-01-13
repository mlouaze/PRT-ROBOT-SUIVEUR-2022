#include <WiFi.h>

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#include "frame.hpp"

#include "moteur.hpp"
#include "types.h"
#include "ESP32Encoder.h"

#include "calctraj.hpp"




#define REDUCTION_RATIO (53.0f)
#define NBR_FRONT (12.0f)
#define RAYON_ROUE (0.031f) //rayon de la roue en m
#define ECART_ROUE (0.098f) //distance entre la roue et le milieu du robot


const char* ssid = "Roboutchou";
const char* password =  "123456789"; // choose only numeric password

WiFiServer wifiServer(80);
WiFiClient client;
bool clientConnected = false;

// Functions prototypes
void periodicControlTask( void *pvParameters );
void periodicWifiTask( void *pvParameters );
uint16_t tsControl = 40;
uint16_t tsWifi = 200;

// Global Variables Free RTOS
const int pinControlTask  = 18;
const int pinWifiTask  = 19;

/* Com */

Frame frame_in(&client);
Frame frame_out(&client);

Moteur moteur1;
Moteur moteur2;
uint8_t motor1Enable  = 32;
uint8_t motor1Dir     = 16;
uint8_t motor1Channel = 0;
uint8_t motor2Enable  = 33;
uint8_t motor2Dir     = 17;
uint8_t motor2Channel = 1;

ESP32Encoder encoder1;
ESP32Encoder encoder2;

uint8_t S1A = 25;
uint8_t S1B = 27;
uint8_t S2A = 26;
uint8_t S2B = 14;

float deltaPos;

int TypeRequestedDatas[3];
bool DataAsked = false;

int cmdMode;

calctraj CalculateurTraj;

unsigned long prev_time = 0; //stock le temps du dernier appel de la fonction speed

void setup() {

  /*
     Communication Serie et wifi (https://techtutorialsx.com/2017/11/13/esp32-arduino-setting-a-socket-server/)
  */

  Serial.begin(115200);
  while (!Serial);
  Serial.println("Setup start");

  // Wi-Fi config
  Serial.println("\n[INFO] Configuring access point");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("[INFO] Started access point at IP ");
  Serial.println(WiFi.softAPIP());


  wifiServer.begin();

  /*
     Free RTOS (http://tvaira.free.fr/esp32/esp32-freertos.html)
  */
  pinMode(pinControlTask, OUTPUT);
  pinMode(pinWifiTask, OUTPUT);
  xTaskCreate(periodicControlTask, "periodicControlTask", 10000, NULL, 2, NULL);
  xTaskCreate(periodicWifiTask, "periodicWifiTask", 10000, NULL, 3, NULL);


  // Configure Motors
  moteur1.config(motor1Enable, motor1Channel, motor1Dir, true, 30);
  moteur2.config(motor2Enable, motor2Channel, motor2Dir, false, 30);
  moteur1.run();
  moteur2.run();

  // Configure Encoder
  // Encoders Config
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors = UP;
  // Configure encoder 1
  encoder1.attachFullQuad(S1A, S1B);
  // Configure encoder 2
  encoder2.attachFullQuad(S2B, S2A);
  // clear the encoder's raw count and set the tracked count to zero
  encoder1.clearCount();
  encoder2.clearCount();

  deltaPos = 2.0f * PI / (NBR_FRONT * REDUCTION_RATIO);

  //CalculateurTraj.ConfCalcTraj(20,true);

}

void loop() {
  delay(1000);
}

// Control variables
float pos_r = 0;
float pos_l = 0;
float speed_r = 0;
float speed_l = 0;
float speed_motor = 0;
float speed_theta = 0;
float com_r = 0 ;
float com_l = 0;

//position variables
float speed_alpha = 0;
float pos_alpha = 0;
float x_speed = 0;
float y_speed = 0;
float x_pos = 0;
float y_pos = 0;

s32 data_0;
s32 data_1;
s32 data_2;

float ref_0;
float ref_1;
float ref_2;



float KpMoteur = 0.3848;
float KiMoteur = 2.96;


float T_on;
float T_off;
float C_value;
int nbr_ticks_step = 0;

void mode_step() {
  nbr_ticks_step ++;
  float u = 0;
  if (nbr_ticks_step <= T_on * 1000 / tsControl) {
    u = C_value;
  } else if (nbr_ticks_step <= (T_on + T_off) * 1000 / tsControl) {
    u = 0;
  } else {
    nbr_ticks_step = 0;
  }
  com_r = u;
  com_l = u;
}


float motor_speed_command = 0;//notre commande de vitesse moyenne
float angle_command = 0;

float r_speed_error; //difference entre vitesse commandée et réelle du moteur droit
float l_speed_error;  //idem gauche

float sum_r_speed_error; //somme de l'erreur de vitesse du moteur droit, utile pour son PI
float sum_l_speed_error; //idem pour le gauche

float kpalpha=0.0892;
float kialpha=3.7403;

float erreur_alpha = 0;
float erreur_alpha_prim = 0;
float erreur_alpha_prec = 0;
float sum_erreur_alpha_prim = 0;
float com_alpha = 0;

void mode_cl() {

  erreur_alpha=(angle_command-pos_alpha);
  erreur_alpha_prim=(erreur_alpha-erreur_alpha_prec)/(tsControl * 0.001);
  
  sum_erreur_alpha_prim+= tsControl * 0.001 * erreur_alpha_prim;

  com_alpha = kpalpha * erreur_alpha_prim + kialpha * sum_erreur_alpha_prim;

  float r_speed_Command = motor_speed_command + com_alpha;
  float l_speed_Command = motor_speed_command - com_alpha;

  r_speed_error = r_speed_Command - speed_r;
  l_speed_error = l_speed_Command - speed_l;

  sum_r_speed_error += tsControl * 0.001 * r_speed_error;
  sum_l_speed_error += tsControl * 0.001 * l_speed_error;

  com_r = KpMoteur * r_speed_error + KiMoteur * sum_r_speed_error;
  com_l = KpMoteur * l_speed_error + KiMoteur * sum_l_speed_error;

  erreur_alpha_prec=erreur_alpha;
}

void mode_pointfollow() {
  if(!CalculateurTraj.TrajEffectuee){
    CalculateurTraj.RecupCommandes(motor_speed_command, angle_command, x_pos, y_pos, pos_alpha);
    
    erreur_alpha=(angle_command-pos_alpha);
    erreur_alpha_prim=(erreur_alpha-erreur_alpha_prec)/(tsControl * 0.001);
    
    sum_erreur_alpha_prim+= tsControl * 0.001 * erreur_alpha_prim;
  
    com_alpha = kpalpha * erreur_alpha_prim + kialpha * sum_erreur_alpha_prim;
  
    float r_speed_Command = motor_speed_command + com_alpha;
    float l_speed_Command = motor_speed_command - com_alpha;
  
    r_speed_error = r_speed_Command - speed_r;
    l_speed_error = l_speed_Command - speed_l;
  
    sum_r_speed_error += tsControl * 0.001 * r_speed_error;
    sum_l_speed_error += tsControl * 0.001 * l_speed_error;
  
    com_r = KpMoteur * r_speed_error + KiMoteur * sum_r_speed_error;
    com_l = KpMoteur * l_speed_error + KiMoteur * sum_l_speed_error;
  
    erreur_alpha_prec=erreur_alpha;
  }
  else{
      com_r=0;
      com_l=0;
  }
}


/*

   Periodic Control Task

*/
void periodicControlTask( void *pvParameters )
{
  const char *pcTaskName = "Periodic Control Task";
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();

  for ( ;; )
  {

    digitalWrite(pinControlTask, HIGH);

    // update pos and speed

    majVitPos();

    // Update Control

    switch (cmdMode) {
      case MODE_OFF :
        com_r = 0;
        com_l = 0;
        break;
      case MODE_STEP :
        mode_step();
        break;
      case MODE_CL :
        mode_cl();
        break;
      case MODE_SENDTRACK :
        com_r = 0;
        com_l = 0;
        break;
      case MODE_POINTFOLLOW :
        mode_pointfollow();
        break;
    }

    // Write outputs
    
    moteur1.commande(-com_r);
    moteur2.commande(-com_l);



    digitalWrite(pinControlTask, LOW);
    long mprev = millis();
    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(tsControl) );
    long time1 = millis() - mprev;
    //Serial.println(time1);

  }
}


/*

   Periodic Wifi Task

*/
void periodicWifiTask( void *pvParameters )
{
  bool retval;
  const char *pcTaskName = "Periodic Wifi Task";
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  client = wifiServer.available();
  Serial.println("Client disconnected");

  int x;
  int countFrame;

  for ( ;; )
  {
    digitalWrite(pinWifiTask, HIGH);
    if (client.connected()) {
      if (!clientConnected)
        Serial.println("Client connected");
      clientConnected = true;
      //Receive Frame in
      retval = frame_in.recev_frame();
      if (retval) {
        TreatCommandFromPC();
      }
      

    }
    else {
      client.stop();
      if (clientConnected)
        Serial.println("Client disconnected");
      clientConnected = false;
      client = wifiServer.available();
    }

    

    if (clientConnected && DataAsked) {
      sendDataToPC();
    }



    digitalWrite(pinWifiTask, LOW);
    vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS(tsWifi) ); // every 100 ms
  }
}

void TreatCommandFromPC() {//execute les commandes recues
  switch (frame_in.get_Cmd()) {
    case CMD_MODE_OFF:
      cmdMode = MODE_OFF;
      ResetVitPos();
      Serial.println(" MODE OFF\n");
      break;
    case CMD_MODE_SELDATA:
      for (int i = 0; i < SIZE_TAB_DATA; i++) {
        TypeRequestedDatas[i] = (int)(0.001 * (float) frame_in.get_data(i));
      }
      DataAsked = true;
      Serial.println(" MODE SELDATA\n");
      break;
    case CMD_MODE_PARAM:
      //
      if (0.001 * (float) frame_in.get_data(0) == 0) {
        KpMoteur = 0.001 * (float) frame_in.get_data(1);
        KiMoteur = 0.001 * (float) frame_in.get_data(2);

        frame_out.set_Cmd(CMD_MODE_SENDINFO);
        frame_out.set_Data(0, 0);
        frame_out.set_Data(cmdMode * 1000, 1);
        frame_out.set_Data(1 * 1000, 2);
        frame_out.set_checksum();
        frame_out.send_frame();
      }
      if (0.001 * (float) frame_in.get_data(0) == 1) {
        frame_out.set_Cmd(CMD_MODE_PARAM);
        frame_out.set_Data(0, 0);
        frame_out.set_Data(KpMoteur * 1000, 1);
        frame_out.set_Data(KiMoteur * 1000, 2);
        frame_out.set_checksum();
        Serial.println("frame envoyée :");
        frame_out.print();
        frame_out.send_frame();
      }
      Serial.println(" MODE PARAM\n");
      break;

    case CMD_MODE_STEP:
      cmdMode = MODE_STEP;
      ResetVitPos();
      C_value = 0.001 * (float) frame_in.get_data(0);
      T_on = 0.001 * (float) frame_in.get_data(1);
      T_off = 0.001 * (float) frame_in.get_data(2);
      Serial.println(" MODE STEP\n");
      sendReceptToPC();
      break;

    case CMD_MODE_CL:
      cmdMode = MODE_CL;
      motor_speed_command = 0.001 * (float) frame_in.get_data(0);
      angle_command = 0.001 * (float) frame_in.get_data(1);
      Serial.println(" MODE CLOSED LOOP\n");
      sendReceptToPC();
      break;

    case CMD_MODE_SENDTRACK:
      cmdMode = MODE_SENDTRACK;
      if ((0.001 * (float) frame_in.get_data(0)) == 0) {
        CalculateurTraj.clear();
        bool rep = false;
        if ((0.001 * (float) frame_in.get_data(2)) == 1) {
          rep = true;
        }
        CalculateurTraj.ConfCalcTraj((int)(0.001 * (float) frame_in.get_data(1)), rep);
        Serial.println(" INFO BASE RECUE\n");
      }
      if ((0.001 * (float) frame_in.get_data(0)) == 1) {
        CalculateurTraj.AjouterPoint((0.001 * (float) frame_in.get_data(1)), (0.001 * (float) frame_in.get_data(2)));
        Serial.println(" POINT AJOUTE\n");
      }
      if ((0.001 * (float) frame_in.get_data(0)) == 2) {
        bool CalcPret = CalculateurTraj.InitCalcTraj((0.001 * (float) frame_in.get_data(1)), (0.001 * (float) frame_in.get_data(2)));
        Serial.println(" INFO FIN RECUE\n");
        if (CalcPret)
          sendReceptToPC();
          Serial.println(" PRET A PARTIR\n");
      }
      Serial.println(" MODE SENDTRACK\n");
      break;

      case CMD_MODE_POINTFOLLOW:
        cmdMode = MODE_POINTFOLLOW;
        ResetVitPos();
        
        int nb=(int)(0.5* 2.0 * ECART_ROUE / RAYON_ROUE* CalculateurTraj.AngleInit / deltaPos);
        encoder1.setCount(-nb);
        encoder2.setCount(nb);
        majVitPos();
        
        Serial.println(encoder2.getCount());
        Serial.println(" MODE POINT FOLLOW\n");
        sendReceptToPC();
        break;
      
  }
  ref_0 = 0.001 * (float) frame_in.get_data(0);
  ref_1 = 0.001 * (float) frame_in.get_data(1);
  ref_2 = 0.001 * (float) frame_in.get_data(2);
  Serial.println("ref " + String(ref_0) + " " + String(ref_1) + " " + String(ref_2));
  frame_in.clear();
}

void sendReceptToPC() { //annonce au PC qu'on a bien recu la commande et qu'on va l'effecuter
  frame_out.clear();
  frame_out.set_Cmd(CMD_MODE_SENDINFO);
  frame_out.set_Data(0, 0);
  frame_out.set_Data(cmdMode * 1000, 1);
  frame_out.set_Data(0, 2);
  frame_out.set_checksum();
  frame_out.send_frame();
}

void sendDataToPC() {//envoie au PC les données demandées
  frame_out.clear();
  frame_out.set_Cmd(MODE_SENDDATA);
  for (int i = 0; i < 3; i++) {
    switch (TypeRequestedDatas[i]) {
      case RIGHT_POS:
        frame_out.set_Data(pos_r * 1000, i);
        break;
      case LEFT_POS:
        frame_out.set_Data(pos_l * 1000, i);
        break;
      case RIGHT_SPEED:
        frame_out.set_Data(speed_r * 1000, i);
        break;
      case LEFT_SPEED:
        frame_out.set_Data(speed_l * 1000, i);
        break;
      case MOTOR_SPEED:
        frame_out.set_Data(speed_motor * 1000, i);
        break;
      case THETA_SPEED:
        frame_out.set_Data(speed_theta * 1000, i);
        break;
      case ALPHA_SPEED:
        frame_out.set_Data(speed_alpha * 1000, i);
        break;
      case ALPHA_POS:
        frame_out.set_Data(pos_alpha * 1000, i);
        break;
      case X_SPEED:
        frame_out.set_Data(x_speed * 1000, i);
        break;
      case Y_SPEED:
        frame_out.set_Data(y_speed * 1000, i);
        break;
      case X_POS:
        frame_out.set_Data(x_pos * 1000, i);
        break;
      case Y_POS:
        frame_out.set_Data(y_pos * 1000, i);
        break;
    }
  }
  frame_out.set_checksum();
  frame_out.send_frame();
  Serial.println("envoye");
}



void majVitPos() {
  pos_r = -deltaPos * encoder1.getCount();
  pos_l = -deltaPos * encoder2.getCount();
  speed_r = -deltaPos * 1000.0 / (float) tsControl  * encoder1.getDt();
  speed_l = -deltaPos * 1000.0 / (float) tsControl * encoder2.getDt();  
  speed_theta = (speed_r - speed_l);
  speed_motor= (speed_r + speed_l)*0.5;

  
  speed_alpha = (speed_r - speed_l) * RAYON_ROUE / (2.0 * ECART_ROUE);
  pos_alpha = (pos_r - pos_l) * RAYON_ROUE / (2.0 * ECART_ROUE);
  if(pos_alpha>3.14){
      pos_alpha-=2*3.14;
    }
    if(pos_alpha<-3.14){
      pos_alpha+=2*3.14;
    }
  x_speed = speed_motor * RAYON_ROUE * cos(pos_alpha);
  y_speed = speed_motor * RAYON_ROUE * sin(pos_alpha);

  x_pos += x_speed * tsControl * 0.001;
  y_pos += y_speed * tsControl * 0.001;
}

void ResetVitPos() {
  encoder1.clearCount();
  encoder2.clearCount();
  pos_r = 0;
  pos_l = 0;
  speed_r = 0;
  speed_l = 0;
  speed_motor = 0;
  speed_theta = 0;
  com_r = 0 ;
  com_l = 0;

  //position variables
  speed_alpha = 0;
  pos_alpha = 0;
  x_speed = 0;
  y_speed = 0;
  x_pos = 0;
  y_pos = 0;
}
