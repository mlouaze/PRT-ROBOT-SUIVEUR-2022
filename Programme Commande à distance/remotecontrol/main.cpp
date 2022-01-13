#include "mainwindow.h"
#include "wifimanager.h"

using namespace std;

#include <iostream>
#include <QApplication>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QString>

#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>

#include <QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    wifimanager wifimanage;
    wifimanage.SetIP("192.168.4.1"); //Robot's IP
    w.SetWifimanager(&wifimanage);


    return a.exec();
}
