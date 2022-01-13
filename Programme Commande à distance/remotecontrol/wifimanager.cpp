#include "wifimanager.h"
#include "types.h"

wifimanager::wifimanager()
{
    IsConnectedToRobotStatus=false;
    FlagIsConnectedToRobotStatus=true;
    IsConnectedViaTCP=false;
    FlagIsConnectedViaTCP=true;
    FlagNewinformation=false;

}

void wifimanager::UpdateConnectedToRobotStatus(){
    QList<QNetworkConfiguration> netcfgList;
    netcfgList = ncm.allConfigurations(QNetworkConfiguration::Active);
    QStringList WiFisList;
    WiFisList.clear();
    bool IsConnected=false;
    for (auto &x : netcfgList)
    {
        if (x.bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            if(x.name() == "Roboutchou")
                IsConnected=true;
        }
    }
    this->FlagIsConnectedToRobotStatus|=(IsConnected!=this->IsConnectedToRobotStatus);
    this->IsConnectedToRobotStatus=IsConnected;

    if(FlagIsConnectedToRobotStatus&&IsConnectedToRobotStatus)
        SetupTCPConnexion();
}

void wifimanager::UpdateAllStatus(){
    this->UpdateConnectedToRobotStatus();
}

void wifimanager::SetIP(QString IP2){
    this->IP=IP2;
    this->port=80;
}
void wifimanager::SetupTCPConnexion(){
    QObject::connect(&soc,SIGNAL(connected()),this,SLOT(ToggleOnTCPConnectedStatus()));
    QObject::connect(&soc,SIGNAL(disconnected()),this,SLOT(ToggleOffTCPConnectedStatus()));
    QObject::connect(&soc,SIGNAL(readyRead()),this,SLOT(ReadTCP()));


}

void wifimanager::StartTCPConnexion(){
    if(IsConnectedToRobotStatus&&!IsConnectedViaTCP){
        soc.connectToHost(IP,port);
    }
}

void wifimanager::ReadTCP(){
    if(!FlagNewinformation){
        while(soc.bytesAvailable()>=16){
            QByteArray b=soc.read(1);
            if(b[0]==0xFF){
                receivedMsg.clear();
                receivedMsg[0]=0xFF;
                receivedMsg+=soc.read(15);
                DecodeMsg();
            }
        }
    }
}

void wifimanager::DecodeMsg(){
    if(receivedMsg.length()==16){
        Marker=receivedMsg[0];
        ID=receivedMsg[1];
        CMD=receivedMsg[2];
        qint32 tabs[3];
        for(int i=0;i<3;i++){
            char data[sizeof(qint32)];
            data[0]=receivedMsg[3+4*i];
            data[1]=receivedMsg[4+4*i];
            data[2]=receivedMsg[5+4*i];
            data[3]=receivedMsg[6+4*i];
            memcpy(&tabs[i], data, sizeof tabs[i]);
            tabf[i]=(float)(tabs[i])*0.001;
        }
        char ChecksumReceived=receivedMsg[15];
        receivedMsg[15]=0x00;
        char CalculatedChecksum=CalcChecksum(receivedMsg);
        if(ChecksumReceived==CalculatedChecksum)
            FlagNewinformation=true;
    }

}

void wifimanager::WriteTCP(char CMD, float Datafl[]){
    QByteArray ba;
    ba.resize(16);
    ba[0] = 0xFF;
    ba[1] = 0x01;
    ba[2] = CMD;
    int size=3;
    qint32 tabs[3];
    for(int i=0;i<size;i++){
        tabs[i]=(qint32)(Datafl[i]*1000);
        char data[sizeof(qint32)];
        memcpy(data, &tabs[i], sizeof tabs[i]);
        for(int j=0;j<4;j++){
            ba[3+4*i+j]=data[j];
        }
    }
    ba[15]=CalcChecksum(ba);
    soc.write(ba);

}

char wifimanager::CalcChecksum(QByteArray b){
    char Checksum=0;
    b[15]=0;
    for(int i=0;i<b.length();i++){
        Checksum+=(char)b[i];
    }
    return Checksum;
}

void wifimanager::ToggleOnTCPConnectedStatus(){
    FlagIsConnectedViaTCP=!IsConnectedViaTCP;
    IsConnectedViaTCP=true;
}

void wifimanager::ToggleOffTCPConnectedStatus(){
    FlagIsConnectedViaTCP=IsConnectedViaTCP;
    IsConnectedViaTCP=false;;
}
