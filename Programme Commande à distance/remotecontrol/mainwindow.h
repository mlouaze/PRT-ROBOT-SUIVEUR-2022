#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wifimanager.h"
#include <QMainWindow>
#include <QChart>
#include <QTimer>
#include <QtCharts>
#include "graphviewer.h"
#include "robotposviewer.h"

#define NBR_DATA 3//number of data that we will plot
#define NBR_SEC_ENR 10//nbr of second that we plot
#define NBR_DATA_PER_SEC 5//nbr of data plotted in 1 second
#define NBR_DATA_SEND_PER_SEC 5 //nbr of data send by the robot each second
#define NBR_DATA_TOTAL NBR_DATA_PER_SEC*NBR_SEC_ENR//total number of data

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QChart tabplotXY[NBR_DATA];                         //QChart of the received data
    GraphViewer afftabplotXY[NBR_DATA];                 //graphviewer of the received which is going to display them
    float tabValues[NBR_DATA][NBR_DATA_TOTAL];          //array of all received value
    float futurevalue[NBR_DATA];                        //array of the 3 last received values
    int nbrrecvalue;                                    //nbr of received value since last graph update
    QSplineSeries *tabSeries[NBR_DATA];                 //series of the data
    bool NeedDataUpdate;
    bool ReceivedData;                                  //indicate if we received some datas since last update

    QChart tabPosRobot;                                 //Qchart of the robot position
    RobotPosviewer AffRobot;                            //Robotposviewer which is going to display the trajectory/obstacles


    int TimerRefreshId;                                 //timer for the update of the received value
    int TimerRefreshPlotId;                             //timer for refreshing the plot
    wifimanager *wifimanage;                            //wifimanage that makes communication between the remote control and the robot
    int modesel;

    void SetWifimanager(wifimanager *wmanage);

    void timerEvent(QTimerEvent *event);

    void SetuptabFloat();                               //setup tabvalues
    void UpdatetabFloat(float nf1, float nf2, float nf3);//update the received value
    void Setuptabseries();                              //setup the series
    void Updateseries();                                //update the series with the new value
    void ManageNewMsg();                                //manage the received message from robot
    void UpdateDest();                                  //update the destination for the obstacle mode

private slots:

    void on_connectbutton_clicked();

    void on_uploadfromrobotbutton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_getdatabutton_clicked();

    void on_downloadfromrobotbutton_clicked();

    void on_startpointrecordbutton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_sendtrackbutton_clicked();

    void on_startobstaclerecordbutton_clicked();

    void on_stopobstaclerecordbutton_clicked();

    void on_XdesValue_editingFinished();

    void on_Ydesvalue_editingFinished();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
