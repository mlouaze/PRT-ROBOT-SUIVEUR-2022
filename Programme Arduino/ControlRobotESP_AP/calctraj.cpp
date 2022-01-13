#include "calctraj.hpp"

calctraj::calctraj(){
}

void calctraj::clear(){
  NbrPoints=0;
  Repeat=0;
  VitComm=0;
  PointActuel=0;
  PointCible=1;
  TabPosRempli=false;
  TrajOK=false;
  TrajEffectuee=false;
}

void calctraj::ConfCalcTraj(const int &nb, const bool &rep){
  NbrPoints=nb;
  PosX=new float[NbrPoints];
  PosY=new float[NbrPoints];
  Repeat=rep;
}

void calctraj::AjouterPoint(const float &Px,const float &Py){
  PosX[PointActuel]=Px;
  PosY[PointActuel]=Py;
  PointActuel++;
  if(PointActuel==NbrPoints)
    TabPosRempli=true;
}

bool calctraj::InitCalcTraj(const float &vit, const float &angle){
  AngleInit=angle;
  VitComm=vit;
  TrajOK=TabPosRempli;
  return TabPosRempli;
}

void calctraj::RecupCommandes(float &CommVitesse, float &CommAngle, const float &Px, const float &Py, const float &Alpha){
  if(!TrajEffectuee&&TrajOK){
    float deltaX=PosX[PointCible]-Px;
    float deltaY=PosY[PointCible]-Py;
    float Angle=atan2(deltaY,deltaX);
    if(Angle>3.14){
      Angle-=2*3.14;
    }
    if(Angle<-3.14){
      Angle+=2*3.14;
    }
    
    if(Alpha-Angle>3.1415){
      Angle+=2*3.14;
    }
    if(Angle-Alpha>3.1415){
      Angle-=2*3.14;
    }
    
    CommAngle=Angle;
    CommVitesse=VitComm;

    if((deltaX*deltaX+deltaY*deltaY)<pow(DISTANCE_MIN,2)){
      Serial.println("je suis arrivé");
      PointCible++;
      if(PointCible==NbrPoints){
        if(Repeat){
          PointCible=1;
        }else{
          TrajEffectuee=true;
        }
      }
    }
  }else{
    CommVitesse=0;
  }
}
