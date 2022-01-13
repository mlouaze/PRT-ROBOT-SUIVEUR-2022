/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Kpvalue;
    QLineEdit *Kivalue;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *downloadfromrobotbutton;
    QPushButton *uploadfromrobotbutton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *selectdata1;
    QComboBox *selectdata2;
    QComboBox *selectdata3;
    QPushButton *getdatabutton;
    QWidget *tab_3;
    QLabel *label_9;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QLabel *label_12;
    QLineEdit *labelcommand;
    QLineEdit *labelton;
    QLabel *label_13;
    QLineEdit *labeltoff;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *anglecommandvalue;
    QLineEdit *speeccommandvalue;
    QLabel *label_7;
    QWidget *tab_5;
    QPushButton *sendtrackbutton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *Lvalue;
    QLineEdit *lvalue;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *startpointrecordbutton;
    QPushButton *pushButton_4;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QComboBox *poscombobox;
    QLabel *label_2;
    QLineEdit *speedvalue;
    QLabel *label_14;
    QPushButton *enablerepeatbutton;
    QWidget *tab_6;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QPushButton *startobstaclerecordbutton;
    QPushButton *stopobstaclerecordbutton;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLineEdit *speedvalue_2;
    QComboBox *poscombobox_2;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *XdesValue;
    QLineEdit *Ydesvalue;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_17;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_20;
    QComboBox *comboBoxmode;
    QPushButton *connectbutton;
    QLabel *statusvalue;
    QLabel *robotstatus;
    QTabWidget *tabWidget_2;
    QWidget *tabdata1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *tabdata2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *tabdata3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 800);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 550, 891, 191));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(480, 440, 421, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);

        horizontalLayout->addWidget(pushButton_3);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(480, 90, 421, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 131, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        Kpvalue = new QLineEdit(gridLayoutWidget);
        Kpvalue->setObjectName(QString::fromUtf8("Kpvalue"));

        gridLayout->addWidget(Kpvalue, 0, 1, 1, 1);

        Kivalue = new QLineEdit(gridLayoutWidget);
        Kivalue->setObjectName(QString::fromUtf8("Kivalue"));

        gridLayout->addWidget(Kivalue, 1, 1, 1, 1);

        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(180, 30, 221, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        downloadfromrobotbutton = new QPushButton(verticalLayoutWidget);
        downloadfromrobotbutton->setObjectName(QString::fromUtf8("downloadfromrobotbutton"));

        verticalLayout->addWidget(downloadfromrobotbutton);

        uploadfromrobotbutton = new QPushButton(verticalLayoutWidget);
        uploadfromrobotbutton->setObjectName(QString::fromUtf8("uploadfromrobotbutton"));

        verticalLayout->addWidget(uploadfromrobotbutton);

        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 190, 416, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectdata1 = new QComboBox(horizontalLayoutWidget_2);
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->addItem(QString());
        selectdata1->setObjectName(QString::fromUtf8("selectdata1"));

        horizontalLayout_2->addWidget(selectdata1);

        selectdata2 = new QComboBox(horizontalLayoutWidget_2);
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->addItem(QString());
        selectdata2->setObjectName(QString::fromUtf8("selectdata2"));

        horizontalLayout_2->addWidget(selectdata2);

        selectdata3 = new QComboBox(horizontalLayoutWidget_2);
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->addItem(QString());
        selectdata3->setObjectName(QString::fromUtf8("selectdata3"));

        horizontalLayout_2->addWidget(selectdata3);

        getdatabutton = new QPushButton(tab);
        getdatabutton->setObjectName(QString::fromUtf8("getdatabutton"));
        getdatabutton->setGeometry(QRect(20, 230, 381, 31));
        getdatabutton->setCheckable(false);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 200, 411, 61));
        label_9->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_4 = new QWidget(tab_3);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 10, 381, 181));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 0, 1, 1);

        labelcommand = new QLineEdit(gridLayoutWidget_4);
        labelcommand->setObjectName(QString::fromUtf8("labelcommand"));

        gridLayout_4->addWidget(labelcommand, 0, 1, 1, 1);

        labelton = new QLineEdit(gridLayoutWidget_4);
        labelton->setObjectName(QString::fromUtf8("labelton"));

        gridLayout_4->addWidget(labelton, 1, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 2, 0, 1, 1);

        labeltoff = new QLineEdit(gridLayoutWidget_4);
        labeltoff->setObjectName(QString::fromUtf8("labeltoff"));

        gridLayout_4->addWidget(labeltoff, 2, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 381, 101));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        anglecommandvalue = new QLineEdit(gridLayoutWidget_2);
        anglecommandvalue->setObjectName(QString::fromUtf8("anglecommandvalue"));

        gridLayout_2->addWidget(anglecommandvalue, 1, 1, 1, 1);

        speeccommandvalue = new QLineEdit(gridLayoutWidget_2);
        speeccommandvalue->setObjectName(QString::fromUtf8("speeccommandvalue"));

        gridLayout_2->addWidget(speeccommandvalue, 0, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 160, 321, 41));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        sendtrackbutton = new QPushButton(tab_5);
        sendtrackbutton->setObjectName(QString::fromUtf8("sendtrackbutton"));
        sendtrackbutton->setEnabled(false);
        sendtrackbutton->setGeometry(QRect(280, 210, 131, 71));
        sendtrackbutton->setCheckable(false);
        sendtrackbutton->setAutoDefault(false);
        gridLayoutWidget_3 = new QWidget(tab_5);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(30, 130, 81, 71));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        Lvalue = new QLineEdit(gridLayoutWidget_3);
        Lvalue->setObjectName(QString::fromUtf8("Lvalue"));

        gridLayout_3->addWidget(Lvalue, 0, 1, 1, 1);

        lvalue = new QLineEdit(gridLayoutWidget_3);
        lvalue->setObjectName(QString::fromUtf8("lvalue"));

        gridLayout_3->addWidget(lvalue, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 130, 81, 71));
        pushButton_6 = new QPushButton(tab_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(310, 130, 81, 71));
        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 220, 261, 61));
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_6 = new QWidget(tab_5);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 10, 160, 111));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        startpointrecordbutton = new QPushButton(verticalLayoutWidget_6);
        startpointrecordbutton->setObjectName(QString::fromUtf8("startpointrecordbutton"));

        verticalLayout_6->addWidget(startpointrecordbutton);

        pushButton_4 = new QPushButton(verticalLayoutWidget_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_6->addWidget(pushButton_4);

        gridLayoutWidget_5 = new QWidget(tab_5);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(180, 10, 231, 106));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        poscombobox = new QComboBox(gridLayoutWidget_5);
        poscombobox->addItem(QString());
        poscombobox->addItem(QString());
        poscombobox->addItem(QString());
        poscombobox->setObjectName(QString::fromUtf8("poscombobox"));

        gridLayout_5->addWidget(poscombobox, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        speedvalue = new QLineEdit(gridLayoutWidget_5);
        speedvalue->setObjectName(QString::fromUtf8("speedvalue"));

        gridLayout_5->addWidget(speedvalue, 0, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 1, 0, 1, 1);

        enablerepeatbutton = new QPushButton(gridLayoutWidget_5);
        enablerepeatbutton->setObjectName(QString::fromUtf8("enablerepeatbutton"));
        enablerepeatbutton->setCheckable(true);
        enablerepeatbutton->setChecked(true);

        gridLayout_5->addWidget(enablerepeatbutton, 2, 0, 1, 2);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayoutWidget_7 = new QWidget(tab_6);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(10, 10, 161, 111));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        startobstaclerecordbutton = new QPushButton(verticalLayoutWidget_7);
        startobstaclerecordbutton->setObjectName(QString::fromUtf8("startobstaclerecordbutton"));

        verticalLayout_7->addWidget(startobstaclerecordbutton);

        stopobstaclerecordbutton = new QPushButton(verticalLayoutWidget_7);
        stopobstaclerecordbutton->setObjectName(QString::fromUtf8("stopobstaclerecordbutton"));

        verticalLayout_7->addWidget(stopobstaclerecordbutton);

        gridLayoutWidget_6 = new QWidget(tab_6);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(180, 10, 221, 120));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        speedvalue_2 = new QLineEdit(gridLayoutWidget_6);
        speedvalue_2->setObjectName(QString::fromUtf8("speedvalue_2"));

        gridLayout_6->addWidget(speedvalue_2, 0, 1, 1, 1);

        poscombobox_2 = new QComboBox(gridLayoutWidget_6);
        poscombobox_2->addItem(QString());
        poscombobox_2->addItem(QString());
        poscombobox_2->addItem(QString());
        poscombobox_2->setObjectName(QString::fromUtf8("poscombobox_2"));

        gridLayout_6->addWidget(poscombobox_2, 1, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 1, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 0, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 3, 0, 1, 1);

        XdesValue = new QLineEdit(gridLayoutWidget_6);
        XdesValue->setObjectName(QString::fromUtf8("XdesValue"));

        gridLayout_6->addWidget(XdesValue, 2, 1, 1, 1);

        Ydesvalue = new QLineEdit(gridLayoutWidget_6);
        Ydesvalue->setObjectName(QString::fromUtf8("Ydesvalue"));

        gridLayout_6->addWidget(Ydesvalue, 3, 1, 1, 1);

        horizontalLayoutWidget_3 = new QWidget(tab_6);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 140, 391, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout_3->addWidget(pushButton_9);

        label_17 = new QLabel(tab_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 190, 361, 71));
        label_17->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_4 = new QWidget(tab_6);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(30, 270, 361, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(horizontalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_4->addWidget(label_20);

        comboBoxmode = new QComboBox(horizontalLayoutWidget_4);
        comboBoxmode->addItem(QString());
        comboBoxmode->addItem(QString());
        comboBoxmode->setObjectName(QString::fromUtf8("comboBoxmode"));

        horizontalLayout_4->addWidget(comboBoxmode);

        tabWidget->addTab(tab_6, QString());
        connectbutton = new QPushButton(centralwidget);
        connectbutton->setObjectName(QString::fromUtf8("connectbutton"));
        connectbutton->setGeometry(QRect(30, 10, 161, 71));
        statusvalue = new QLabel(centralwidget);
        statusvalue->setObjectName(QString::fromUtf8("statusvalue"));
        statusvalue->setGeometry(QRect(210, 10, 241, 31));
        robotstatus = new QLabel(centralwidget);
        robotstatus->setObjectName(QString::fromUtf8("robotstatus"));
        robotstatus->setGeometry(QRect(210, 40, 171, 31));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(920, 10, 671, 721));
        tabdata1 = new QWidget();
        tabdata1->setObjectName(QString::fromUtf8("tabdata1"));
        verticalLayoutWidget_2 = new QWidget(tabdata1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 651, 671));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget_2->addTab(tabdata1, QString());
        tabdata2 = new QWidget();
        tabdata2->setObjectName(QString::fromUtf8("tabdata2"));
        verticalLayoutWidget_3 = new QWidget(tabdata2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 651, 671));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget_2->addTab(tabdata2, QString());
        tabdata3 = new QWidget();
        tabdata3->setObjectName(QString::fromUtf8("tabdata3"));
        verticalLayoutWidget_4 = new QWidget(tabdata3);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 651, 671));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget_2->addTab(tabdata3, QString());
        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 90, 461, 451));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        textBrowser->raise();
        horizontalLayoutWidget->raise();
        tabWidget->raise();
        statusvalue->raise();
        robotstatus->raise();
        tabWidget_2->raise();
        verticalLayoutWidget_5->raise();
        connectbutton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);
        poscombobox->setCurrentIndex(0);
        poscombobox_2->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        pushButton->setText(QCoreApplication::translate("MainWindow", "\n"
" GO \n"
"", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\n"
" STOP \n"
"", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        Kpvalue->setText(QCoreApplication::translate("MainWindow", "0.3848", nullptr));
        Kivalue->setText(QCoreApplication::translate("MainWindow", "2.9598", nullptr));
        downloadfromrobotbutton->setText(QCoreApplication::translate("MainWindow", "Download from Robot", nullptr));
        uploadfromrobotbutton->setText(QCoreApplication::translate("MainWindow", "Upload to Robot", nullptr));
        selectdata1->setItemText(0, QCoreApplication::translate("MainWindow", "RIGHT_POS", nullptr));
        selectdata1->setItemText(1, QCoreApplication::translate("MainWindow", "LEFT_POS", nullptr));
        selectdata1->setItemText(2, QCoreApplication::translate("MainWindow", "RIGHT_SPEED", nullptr));
        selectdata1->setItemText(3, QCoreApplication::translate("MainWindow", "LEFT_SPEED", nullptr));
        selectdata1->setItemText(4, QCoreApplication::translate("MainWindow", "MOTORS_SPEED", nullptr));
        selectdata1->setItemText(5, QCoreApplication::translate("MainWindow", "THETA_SPEED", nullptr));
        selectdata1->setItemText(6, QCoreApplication::translate("MainWindow", "ALPHA_SPEED", nullptr));
        selectdata1->setItemText(7, QCoreApplication::translate("MainWindow", "ALPHA_POS", nullptr));
        selectdata1->setItemText(8, QCoreApplication::translate("MainWindow", "X_SPEED", nullptr));
        selectdata1->setItemText(9, QCoreApplication::translate("MainWindow", "Y_SPEED", nullptr));
        selectdata1->setItemText(10, QCoreApplication::translate("MainWindow", "X_POS", nullptr));
        selectdata1->setItemText(11, QCoreApplication::translate("MainWindow", "Y_POS", nullptr));

        selectdata2->setItemText(0, QCoreApplication::translate("MainWindow", "RIGHT_POS", nullptr));
        selectdata2->setItemText(1, QCoreApplication::translate("MainWindow", "LEFT_POS", nullptr));
        selectdata2->setItemText(2, QCoreApplication::translate("MainWindow", "RIGHT_SPEED", nullptr));
        selectdata2->setItemText(3, QCoreApplication::translate("MainWindow", "LEFT_SPEED", nullptr));
        selectdata2->setItemText(4, QCoreApplication::translate("MainWindow", "MOTORS_SPEED", nullptr));
        selectdata2->setItemText(5, QCoreApplication::translate("MainWindow", "THETA_SPEED", nullptr));
        selectdata2->setItemText(6, QCoreApplication::translate("MainWindow", "ALPHA_SPEED", nullptr));
        selectdata2->setItemText(7, QCoreApplication::translate("MainWindow", "ALPHA_POS", nullptr));
        selectdata2->setItemText(8, QCoreApplication::translate("MainWindow", "X_SPEED", nullptr));
        selectdata2->setItemText(9, QCoreApplication::translate("MainWindow", "Y_SPEED", nullptr));
        selectdata2->setItemText(10, QCoreApplication::translate("MainWindow", "X_POS", nullptr));
        selectdata2->setItemText(11, QCoreApplication::translate("MainWindow", "Y_POS", nullptr));

        selectdata3->setItemText(0, QCoreApplication::translate("MainWindow", "RIGHT_POS", nullptr));
        selectdata3->setItemText(1, QCoreApplication::translate("MainWindow", "LEFT_POS", nullptr));
        selectdata3->setItemText(2, QCoreApplication::translate("MainWindow", "RIGHT_SPEED", nullptr));
        selectdata3->setItemText(3, QCoreApplication::translate("MainWindow", "LEFT_SPEED", nullptr));
        selectdata3->setItemText(4, QCoreApplication::translate("MainWindow", "MOTORS_SPEED", nullptr));
        selectdata3->setItemText(5, QCoreApplication::translate("MainWindow", "THETA_SPEED", nullptr));
        selectdata3->setItemText(6, QCoreApplication::translate("MainWindow", "ALPHA_SPEED", nullptr));
        selectdata3->setItemText(7, QCoreApplication::translate("MainWindow", "ALPHA_POS", nullptr));
        selectdata3->setItemText(8, QCoreApplication::translate("MainWindow", "X_SPEED", nullptr));
        selectdata3->setItemText(9, QCoreApplication::translate("MainWindow", "Y_SPEED", nullptr));
        selectdata3->setItemText(10, QCoreApplication::translate("MainWindow", "X_POS", nullptr));
        selectdata3->setItemText(11, QCoreApplication::translate("MainWindow", "Y_POS", nullptr));

        getdatabutton->setText(QCoreApplication::translate("MainWindow", "Get those datas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "The command will be applied to both motors for Ton \n"
" seconds, then stopped for Toff seconds and then repeated", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Command", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Ton", nullptr));
        labelcommand->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        labelton->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Toff", nullptr));
        labeltoff->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Step", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Speed command", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Angle command", nullptr));
        anglecommandvalue->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        speeccommandvalue->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Those commands should be expressed in rad/s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Closed loop", nullptr));
        sendtrackbutton->setText(QCoreApplication::translate("MainWindow", "Send track", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "L=", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "l=", nullptr));
        Lvalue->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        lvalue->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Create \n"
" Ellipse", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Create \n"
" Rectangle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "You first need to record a track  \n"
" or make an ellipse or rectangle \n"
" then send it then the robot can play it", nullptr));
        startpointrecordbutton->setText(QCoreApplication::translate("MainWindow", "Start recording \n"
"track ", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Stop Recording \n"
" Track", nullptr));
        poscombobox->setItemText(0, QCoreApplication::translate("MainWindow", "Vertical Up", nullptr));
        poscombobox->setItemText(1, QCoreApplication::translate("MainWindow", "Horizontal R", nullptr));
        poscombobox->setItemText(2, QCoreApplication::translate("MainWindow", "Horizontal L", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        speedvalue->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Initial Position", nullptr));
        enablerepeatbutton->setText(QCoreApplication::translate("MainWindow", "Repeat when \n"
"completed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Points following", nullptr));
        startobstaclerecordbutton->setText(QCoreApplication::translate("MainWindow", "Start recording \n"
" obstacles", nullptr));
        stopobstaclerecordbutton->setText(QCoreApplication::translate("MainWindow", "Stop recording \n"
" obstacles", nullptr));
        speedvalue_2->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        poscombobox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Vertical Up", nullptr));
        poscombobox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Horizontal R", nullptr));
        poscombobox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Horizontal L", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Initial Position", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "X Destination", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Y Destination", nullptr));
        XdesValue->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        Ydesvalue->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Send calculated trajectory", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Send obstacles", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "You can either create the map with all the obstacles,\n"
" calculate the trajectory in the computer and send \n"
"or only send the map to the robot and let it calculate \n"
"the trajectory by himself (not implemented)", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        comboBoxmode->setItemText(0, QCoreApplication::translate("MainWindow", "PC computing", nullptr));
        comboBoxmode->setItemText(1, QCoreApplication::translate("MainWindow", "Local computing", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Obstacles", nullptr));
        connectbutton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        statusvalue->setText(QCoreApplication::translate("MainWindow", "Status : disconnected", nullptr));
        robotstatus->setText(QCoreApplication::translate("MainWindow", "Robot : Idle mode", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabdata1), QCoreApplication::translate("MainWindow", "data 1", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabdata2), QCoreApplication::translate("MainWindow", "data 2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabdata3), QCoreApplication::translate("MainWindow", "data 3", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
