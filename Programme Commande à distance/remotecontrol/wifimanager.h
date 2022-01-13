#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <iostream>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpSocket>
#include <QString>
#include <QObject>
#include <QByteArray>

class wifimanager : public QObject
{
Q_OBJECT
public:
    wifimanager();
    QNetworkConfiguration netcfg;
    QNetworkConfigurationManager ncm;
    QString IP;                         //IP of the robot
    int port;                           //port of the connexion (80)
    QTcpSocket soc;                     //TCP socket that makes the communication
    QByteArray receivedMsg;             //Bytearray of the last received message
    QByteArray DataAvailable;           //Bytearray of the
    char Marker;                        //marker of the message
    char ID;                            //ID of the message
    char CMD;                           //CMD of the message
    float tabf[3];                      //data stored in the message

    bool FlagNewinformation;            //flag that indicate that a new information arrived
    bool IsConnectedToRobotStatus;      //indicate if the application is connected to the robot
    bool FlagIsConnectedToRobotStatus;  //flag of previous
    bool IsConnectedViaTCP;             //indicate that the TCP connexion is OK
    bool FlagIsConnectedViaTCP;         //flag of previous


    void UpdateConnectedToRobotStatus();


    void SetIP(QString IP2);
    void SetupTCPConnexion();
    void StartTCPConnexion();


    void UpdateAllStatus();

    void WriteTCP(char CMD, float Datafl[]);    //send the message to the robot
    void DecodeMsg();                           //decode the received message
    char CalcChecksum(QByteArray b);            //calculate the needed checksum

    public slots:
    void ToggleOnTCPConnectedStatus();
    void ToggleOffTCPConnectedStatus();
    void ReadTCP();                             //communication slots
};

#endif // WIFIMANAGER_H
