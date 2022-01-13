#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "types.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1600,800);
    SetuptabFloat();
    Setuptabseries();
    Updateseries();
    NeedDataUpdate=false;
    ReceivedData=false;
    for(int i=0;i<NBR_DATA;i++){
        tabplotXY[i].legend()->hide();

        QValueAxis *axisX=new QValueAxis;
        axisX->setReverse();
        axisX->setTickCount(11);
        axisX->setMin(0);
        axisX->setMax(10);
        tabplotXY[i].addAxis(axisX,Qt::AlignBottom);

        QValueAxis *axisY=new QValueAxis;
        axisY->setTickCount(11);
        axisY->setMin(-10);
        axisY->setMax(10);
        tabplotXY[i].addAxis(axisY,Qt::AlignLeft);

        tabplotXY[i].addSeries(tabSeries[i]);

        tabSeries[i]->attachAxis(axisX);
        tabSeries[i]->attachAxis(axisY);

        afftabplotXY[i].setChart(&(tabplotXY[i]));
        afftabplotXY[i].setRenderHint((QPainter::Antialiasing));
    }
    ui->verticalLayout_2->addWidget(&(afftabplotXY[0]));
    ui->verticalLayout_3->addWidget(&(afftabplotXY[1]));
    ui->verticalLayout_4->addWidget(&(afftabplotXY[2]));

    AffRobot.setContentsMargins(0,0,0,0);
    tabPosRobot.legend()->hide();
    QValueAxis *axisX=new QValueAxis;
    axisX->setTickCount(5);
    axisX->setMin(0);
    axisX->setMax(4);
    tabPosRobot.addAxis(axisX,Qt::AlignLeft);

    QValueAxis *axisY=new QValueAxis;
    axisY->setTickCount(5);
    axisY->setMin(-2);
    axisY->setMax(2);
    tabPosRobot.addAxis(axisY,Qt::AlignBottom);

    tabPosRobot.addSeries(&AffRobot.ListPoints);
    tabPosRobot.addSeries(&AffRobot.Obstacles);
    tabPosRobot.addSeries(&AffRobot.Dest);

    AffRobot.ListPoints.attachAxis(axisX);
    AffRobot.ListPoints.attachAxis(axisY);

    AffRobot.Obstacles.attachAxis(axisX);
    AffRobot.Obstacles.attachAxis(axisY);

    AffRobot.Dest.attachAxis(axisX);
    AffRobot.Dest.attachAxis(axisY);

    AffRobot.setChart(&(tabPosRobot));
    AffRobot.setRenderHint((QPainter::Antialiasing));
    ui->verticalLayout_5->addWidget(&(AffRobot));

    TimerRefreshId=startTimer(10);
    TimerRefreshPlotId=startTimer(1000.0/((float)NBR_DATA_PER_SEC));
    modesel=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetuptabFloat(){
    for(int i=0;i<NBR_DATA;i++){
        for(int j=0;j<NBR_DATA_TOTAL;j++){
            tabValues[i][j]=0;
        }
    }
}
void MainWindow::UpdatetabFloat(float nf1, float nf2, float nf3){
    for(int i=0;i<NBR_DATA;i++){
        for(int j=0;j<NBR_DATA_TOTAL-1;j++){
            tabValues[i][NBR_DATA_TOTAL-1-j]=tabValues[i][NBR_DATA_TOTAL-2-j];
        }
    }
    tabValues[0][0]=nf1;
    tabValues[1][0]=nf2;
    tabValues[2][0]=nf3;//slide all previous values by one and at the new one at the beginning
}


void MainWindow::Updateseries(){
    for(int i=0;i<NBR_DATA;i++){
        QList<QPointF> *t;
        t=new QList<QPointF>;
        for(int j=0;j<NBR_DATA_TOTAL;j++){
            *(t) << QPointF((float)(j)/NBR_DATA_PER_SEC,tabValues[i][j]);
        }
        tabSeries[i]->replace(*(t));
    }
}


void MainWindow::Setuptabseries(){
    for(int j=0;j<NBR_DATA;j++)
        tabSeries[j]=new QSplineSeries;
}

void MainWindow::SetWifimanager(wifimanager *wmanage){
    wifimanage=wmanage;
}


void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==TimerRefreshId){
      wifimanage->UpdateAllStatus();
      if(wifimanage->FlagIsConnectedToRobotStatus){
          if(wifimanage->IsConnectedToRobotStatus){
              ui->textBrowser->append("The robot is connected via wifi");
              ui->statusvalue->setText("status : connected");
          }
          else{
              ui->textBrowser->append("You aren't connected to the robot via wifi");
              ui->statusvalue->setText("status : disconnected");
          }
      }
      wifimanage->FlagIsConnectedToRobotStatus=false;
      if(wifimanage->FlagIsConnectedViaTCP){
          if(wifimanage->IsConnectedViaTCP){
              ui->textBrowser->append("The robot is connected via TCP");
              ui->statusvalue->setText("status : connected & TCP ok");
          }
          else{
              ui->textBrowser->append("The robot isn't connected via TCP");
          }
          wifimanage->FlagIsConnectedViaTCP=false;
      }

      if(wifimanage->FlagNewinformation){
          ManageNewMsg();
          //ui->textBrowser->append("something is received");
      }
    }
    if((event->timerId()==TimerRefreshPlotId)&&NeedDataUpdate){
        if(ReceivedData==false){
            UpdatetabFloat(tabValues[0][0],tabValues[1][0],tabValues[2][0]);
            //ui->textBrowser->append("Missing datas");
            Updateseries();
        }else{
            for(int i=0;i<NBR_DATA;i++){
                futurevalue[i]/=(float)nbrrecvalue;
            }
            UpdatetabFloat(futurevalue[0],futurevalue[1],futurevalue[2]);
            futurevalue[0]=0;
            futurevalue[1]=0;
            futurevalue[2]=0;
            Updateseries();
            nbrrecvalue=0;
            ui->textBrowser->append("received values");
        }
        ReceivedData=false;
    }
}

void MainWindow::ManageNewMsg(){
    switch (wifimanage->CMD){
        case MODE_PARAM:{
            ui->textBrowser->append("Ki and Kp value downloaded from robot");
            ui->Kpvalue->setText(QString::number(wifimanage->tabf[1]));
            ui->Kivalue->setText(QString::number(wifimanage->tabf[2]));
        }break;

        case MODE_SENDDATA:{
            ReceivedData=true;
            nbrrecvalue++;
            futurevalue[0]+=wifimanage->tabf[0];
            futurevalue[1]+=wifimanage->tabf[1];
            futurevalue[2]+=wifimanage->tabf[2];
            //ui->textBrowser->append("received data");
        }break;

        case MODE_SENDINFO:{
            ui->textBrowser->append("Command received");

            switch ((int)(wifimanage->tabf[1])){

            case MODE_OFF:{
                ui->robotstatus->setText("Robot : Idle Mode");
            }break;

            case MODE_STEP:{
                ui->robotstatus->setText("Robot : Step Mode");
            }break;

            case MODE_CL:{
                ui->robotstatus->setText("Robot : Closed Loop Mode");
            }break;

            case MODE_POINTFOLLOW:{
                ui->robotstatus->setText("Robot : Point Follow Mode");
            }break;
            }

            if(wifimanage->tabf[2]==1)
                ui->textBrowser->append("KP and KI updated");
            if(wifimanage->tabf[2]==2)
                ui->textBrowser->append("Selected record data updated");
        }break;

    default:
        ui->textBrowser->append("Weird data received (unvalid CMD)");

    }
    //ui->textBrowser->append("Received data : "+QString::number(wifimanage->tabf[0])+", "+QString::number(wifimanage->tabf[1])+", "+QString::number(wifimanage->tabf[2])+", ");
    wifimanage->FlagNewinformation=false;
}

void MainWindow::on_connectbutton_clicked()
{
    wifimanage->StartTCPConnexion();

}



void MainWindow::on_uploadfromrobotbutton_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        ui->textBrowser->append("sending the parameters...");
        float Kpvalue =(ui->Kpvalue->text()).toFloat();
        float Kivalue =(ui->Kivalue->text()).toFloat();
        float tabfloat[3];
        tabfloat[0]=0;  //on est en mode envoie
        tabfloat[1]=Kpvalue;
        tabfloat[2]=Kivalue;
        wifimanage->WriteTCP(MODE_PARAM,tabfloat);
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    modesel=ui->tabWidget->currentIndex();
}

void MainWindow::on_pushButton_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        float tabfloat[3];
        switch (modesel){
            case MODE_PARAM:{
                ui->textBrowser->append("This mode only set the parameters");
            }break;
            case MODE_STEP:{
                NeedDataUpdate=true;
                ui->textBrowser->append("sending the step command...");
                float command =(ui->labelcommand->text()).toFloat();
                float ton =(ui->labelton->text()).toFloat();
                float toff=(ui->labeltoff->text()).toFloat();
                tabfloat[0]=command;
                tabfloat[1]=ton;
                tabfloat[2]=toff;
                wifimanage->WriteTCP(MODE_STEP,tabfloat);
            }break;
            case MODE_CL:{
                ui->textBrowser->append("sending the closed loop command...");
                NeedDataUpdate=true;
                float speedcomm =(ui->speeccommandvalue->text()).toFloat();
                float anglecomm =(ui->anglecommandvalue->text()).toFloat();
                tabfloat[0]=speedcomm;
                tabfloat[1]=anglecomm;
                tabfloat[2]=0;
                wifimanage->WriteTCP(MODE_CL,tabfloat);
            }break;
            case MODE_POINTFOLLOW:{
                ui->textBrowser->append("sending the point following command...");
                NeedDataUpdate=true;
                tabfloat[0]=0;
                tabfloat[1]=0;
                tabfloat[2]=0;
                wifimanage->WriteTCP(MODE_POINTFOLLOW,tabfloat);
            }break;
            case MODE_OBSTACLE:{
                if(ui->comboBoxmode->currentIndex()==0){
                    ui->textBrowser->append("sending the obstacle command...");
                    NeedDataUpdate=true;
                    tabfloat[0]=0;
                    tabfloat[1]=0;
                    tabfloat[2]=0;
                    wifimanage->WriteTCP(MODE_POINTFOLLOW,tabfloat);
                }else{
                    //local mode computing command
                }
            }break;
        }
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        NeedDataUpdate=false;
        ui->textBrowser->append("sending the stop command...");
        float tabfloat[3];
        tabfloat[0]=0;
        tabfloat[1]=0;
        tabfloat[2]=0;
        wifimanage->WriteTCP(MODE_OFF,tabfloat);
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }
}

void MainWindow::on_getdatabutton_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        ui->textBrowser->append("Sending the command to change requested data to robot");
        ui->tabWidget_2->setTabText(0,ui->selectdata1->currentText());
        ui->tabWidget_2->setTabText(1,ui->selectdata2->currentText());
        ui->tabWidget_2->setTabText(2,ui->selectdata3->currentText());
        float tf[3];
        tf[0]=float(ui->selectdata1->currentIndex());
        tf[1]=float(ui->selectdata2->currentIndex());
        tf[2]=float(ui->selectdata3->currentIndex());
        wifimanage->WriteTCP(MODE_SELDATA,tf);
        SetuptabFloat();
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }
}

void MainWindow::on_downloadfromrobotbutton_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        ui->textBrowser->append("Getting the parameters...");
        float tabfloat[3];
        tabfloat[0]=1;  //on est en mode demande d'envoie
        tabfloat[1]=0;
        tabfloat[2]=0;
        wifimanage->WriteTCP(MODE_PARAM,tabfloat);
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
        }
}



void MainWindow::on_startpointrecordbutton_clicked()
{
    AffRobot.Dest.setVisible(false);
    ui->sendtrackbutton->setEnabled(false);
    AffRobot.ListPoints.clear();
    AffRobot.Obstacles.clear();
    AffRobot.Radius.clear();
    QPointF Point0=QPointF(0.0,0.0);
    AffRobot.ListPoints<<Point0;
    AffRobot.SelectPointsMode=true;
    AffRobot.Mode=1;
    ui->textBrowser->append("Starting track record");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->append("Ending track record");
    AffRobot.SelectPointsMode=false;
    if(AffRobot.ListPoints.count()>=2){
        ui->sendtrackbutton->setEnabled(true);
    }
}



void MainWindow::on_pushButton_5_clicked()
{
    AffRobot.ListPoints.clear();
    float l=ui->lvalue->text().toFloat();
    float L=ui->Lvalue->text().toFloat();
    float mindis=0.5;
    int nbrpoint=(int)(2*3.14*(l+L)*0.5/mindis);
    QPointF tabPoint[nbrpoint];
    for(int i=0;i<nbrpoint+1;i++){
        float x=l/2*(sin(2*3.14*float(i)/float(nbrpoint)));
        float y=L/2*(1-cos(2*3.14*float(i)/float(nbrpoint)));
        tabPoint[i]=QPointF(x,y);
        AffRobot.ListPoints<<tabPoint[i];
    }
    ui->sendtrackbutton->setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    float l=ui->lvalue->text().toFloat();
    float L=ui->Lvalue->text().toFloat();
    float curbradius=0.1;
    AffRobot.ListPoints.clear();
    QPointF Point0=QPointF(0.0,0.0);
    AffRobot.ListPoints<<Point0;
    float x=0;
    float y=0;
    x=l/2-curbradius;
    y=0;
    AffRobot.ListPoints<<QPointF(x,y);
    x=l/2;
    y=curbradius;
    AffRobot.ListPoints<<QPointF(x,y);
    x=l/2;
    y=L-curbradius;
    AffRobot.ListPoints<<QPointF(x,y);
    x=l/2-curbradius;
    y=L;
    AffRobot.ListPoints<<QPointF(x,y);
    x=-l/2+curbradius;
    y=L;
    AffRobot.ListPoints<<QPointF(x,y);
    x=-l/2;
    y=L-curbradius;
    AffRobot.ListPoints<<QPointF(x,y);
    x=-l/2;
    y=curbradius;
    AffRobot.ListPoints<<QPointF(x,y);
    x=-l/2+curbradius;
    y=0;
    AffRobot.ListPoints<<QPointF(x,y);
    x=0;
    y=0;
    AffRobot.ListPoints<<QPointF(x,y);
}

void MainWindow::on_sendtrackbutton_clicked()
{
    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        if(AffRobot.ListPoints.count()>=2){
            char CMD=MODE_SENDTRACK;
            float tf[3];

            tf[0]=0;
            tf[1]=AffRobot.ListPoints.count();
            if(ui->sendtrackbutton->isChecked())
                tf[2]=1;
            else
                tf[2]=0;
            wifimanage->WriteTCP(CMD,tf);

            tf[0]=1;
            for(int i=0;i<AffRobot.ListPoints.count();i++){
                tf[1]=(float)(AffRobot.ListPoints.points().at(i).x());
                tf[2]=(float)(AffRobot.ListPoints.points().at(i).y());
                wifimanage->WriteTCP(CMD,tf);
            }

            tf[0]=2;
            tf[1]=ui->speedvalue->text().toFloat();
            float startangle=0;
            if(ui->poscombobox->currentIndex()==0){
                startangle=3.14/2;
            }
            if(ui->poscombobox->currentIndex()==1){
                startangle=0;
            }
            if(ui->poscombobox->currentIndex()==2){
                startangle=3.14;
            }
            tf[2]=startangle;
            wifimanage->WriteTCP(CMD,tf);
        }
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }

}

void MainWindow::on_startobstaclerecordbutton_clicked()
{
    AffRobot.Dest.setVisible(true);
    ui->sendtrackbutton->setEnabled(false);
    AffRobot.ListPoints.clear();
    AffRobot.Obstacles.clear();
    AffRobot.Radius.clear();
    QPointF Point0=QPointF(0.0,0.0);
    AffRobot.ListPoints<<Point0;
    AffRobot.SelectPointsMode=true;
    AffRobot.Mode=2;
    AffRobot.viewport()->repaint();
    ui->textBrowser->append("Starting obstacle record");
}


void MainWindow::on_stopobstaclerecordbutton_clicked()
{
    ui->textBrowser->append("Ending obstacles record");
    AffRobot.SelectPointsMode=false;
}


void MainWindow::on_XdesValue_editingFinished()
{
    UpdateDest();
}

void MainWindow::on_Ydesvalue_editingFinished()
{
    UpdateDest();
}


void MainWindow::UpdateDest(){
    float Xdes=(ui->XdesValue->text()).toFloat();
    float Ydes=(ui->Ydesvalue->text()).toFloat();

    QPointF dest(Xdes,Ydes);
    this->AffRobot.Dest.replace(0,dest);


}

void MainWindow::on_pushButton_8_clicked()
{
    AffRobot.CalculTrajectoire();

    if(wifimanage->IsConnectedViaTCP&&wifimanage->IsConnectedToRobotStatus){
        if(AffRobot.ListPoints.count()>=2){
            char CMD=MODE_SENDTRACK;
            float tf[3];

            tf[0]=0;
            tf[1]=AffRobot.ListPoints.count();
            tf[2]=0;
            wifimanage->WriteTCP(CMD,tf);

            tf[0]=1;
            for(int i=0;i<AffRobot.ListPoints.count();i++){
                tf[1]=(float)(AffRobot.ListPoints.points().at(i).x());
                tf[2]=(float)(AffRobot.ListPoints.points().at(i).y());
                wifimanage->WriteTCP(CMD,tf);
            }

            tf[0]=2;
            tf[1]=ui->speedvalue_2->text().toFloat();
            float startangle = 0;
            if(ui->poscombobox_2->currentIndex()==0){
                startangle=3.14/2;
            }
            if(ui->poscombobox_2->currentIndex()==1){
                startangle=0;
            }
            if(ui->poscombobox_2->currentIndex()==2){
                startangle=3.14;
            }
            tf[2]=startangle;
            wifimanage->WriteTCP(CMD,tf);
        }
    }else{
        ui->textBrowser->append("You aren't connected to the robot!");
    }
}
