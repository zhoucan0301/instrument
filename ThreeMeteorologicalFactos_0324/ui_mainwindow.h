/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *customPlot;
    QLabel *timeLabel;
    QPushButton *faultDiagnosisBtn;
    QPushButton *networkSettingBtn;
    QLabel *netmaskLabel;
    QLabel *gatewayLabel;
    QPushButton *userSettingBtn;
    QPushButton *terminalsettingBtn;
    QPushButton *pushButton_printf;
    QPushButton *instrumentSettingBtn;
    QWidget *widget;
    QLabel *label_INSNAME;
    QLabel *IDLabel;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *widget_3;
    QLabel *longitudeLabel;
    QLabel *altitudeLabel;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *dateLabel;
    QLabel *latitudeLabel;
    QLabel *label_10;
    QLabel *stationLabel;
    QLabel *IPLabel;
    QLabel *codeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 0));
        MainWindow->setAcceptDrops(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 190, 651, 251));
        timeLabel = new QLabel(customPlot);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(270, 0, 101, 41));
        faultDiagnosisBtn = new QPushButton(centralwidget);
        faultDiagnosisBtn->setObjectName(QString::fromUtf8("faultDiagnosisBtn"));
        faultDiagnosisBtn->setGeometry(QRect(530, 80, 131, 101));
        networkSettingBtn = new QPushButton(centralwidget);
        networkSettingBtn->setObjectName(QString::fromUtf8("networkSettingBtn"));
        networkSettingBtn->setGeometry(QRect(670, 210, 131, 71));
        netmaskLabel = new QLabel(centralwidget);
        netmaskLabel->setObjectName(QString::fromUtf8("netmaskLabel"));
        netmaskLabel->setGeometry(QRect(540, 40, 141, 21));
        gatewayLabel = new QLabel(centralwidget);
        gatewayLabel->setObjectName(QString::fromUtf8("gatewayLabel"));
        gatewayLabel->setGeometry(QRect(540, 60, 141, 16));
        userSettingBtn = new QPushButton(centralwidget);
        userSettingBtn->setObjectName(QString::fromUtf8("userSettingBtn"));
        userSettingBtn->setGeometry(QRect(670, 370, 131, 71));
        terminalsettingBtn = new QPushButton(centralwidget);
        terminalsettingBtn->setObjectName(QString::fromUtf8("terminalsettingBtn"));
        terminalsettingBtn->setGeometry(QRect(670, 130, 131, 71));
        pushButton_printf = new QPushButton(centralwidget);
        pushButton_printf->setObjectName(QString::fromUtf8("pushButton_printf"));
        pushButton_printf->setGeometry(QRect(670, 50, 131, 71));
        instrumentSettingBtn = new QPushButton(centralwidget);
        instrumentSettingBtn->setObjectName(QString::fromUtf8("instrumentSettingBtn"));
        instrumentSettingBtn->setGeometry(QRect(670, 290, 131, 71));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, 0, 801, 41));
        label_INSNAME = new QLabel(widget);
        label_INSNAME->setObjectName(QString::fromUtf8("label_INSNAME"));
        label_INSNAME->setGeometry(QRect(10, 8, 431, 41));
        IDLabel = new QLabel(widget);
        IDLabel->setObjectName(QString::fromUtf8("IDLabel"));
        IDLabel->setGeometry(QRect(588, 0, 231, 41));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 79, 511, 101));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(227, 40, 91, 51));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 40, 91, 51));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 10, 141, 25));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 10, 51, 25));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 10, 51, 25));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(171, 40, 51, 25));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 40, 31, 25));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(450, 40, 51, 25));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(65, 40, 91, 51));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 10, 21, 21));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(310, 10, 21, 21));
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(widget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(440, 10, 21, 21));
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(320, 70, 31, 25));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 449, 801, 31));
        longitudeLabel = new QLabel(widget_3);
        longitudeLabel->setObjectName(QString::fromUtf8("longitudeLabel"));
        longitudeLabel->setGeometry(QRect(60, 0, 101, 31));
        altitudeLabel = new QLabel(widget_3);
        altitudeLabel->setObjectName(QString::fromUtf8("altitudeLabel"));
        altitudeLabel->setGeometry(QRect(330, 0, 101, 31));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(670, 0, 181, 31));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 51, 31));
        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(290, 0, 41, 31));
        dateLabel = new QLabel(widget_3);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(540, 0, 111, 31));
        latitudeLabel = new QLabel(widget_3);
        latitudeLabel->setObjectName(QString::fromUtf8("latitudeLabel"));
        latitudeLabel->setGeometry(QRect(161, 0, 111, 31));
        label_12->raise();
        altitudeLabel->raise();
        label_11->raise();
        label_13->raise();
        dateLabel->raise();
        latitudeLabel->raise();
        longitudeLabel->raise();
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 50, 66, 21));
        stationLabel = new QLabel(centralwidget);
        stationLabel->setObjectName(QString::fromUtf8("stationLabel"));
        stationLabel->setGeometry(QRect(60, 50, 71, 21));
        IPLabel = new QLabel(centralwidget);
        IPLabel->setObjectName(QString::fromUtf8("IPLabel"));
        IPLabel->setGeometry(QRect(360, 50, 182, 21));
        codeLabel = new QLabel(centralwidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        codeLabel->setGeometry(QRect(130, 50, 91, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">00\357\274\23200</span></p></body></html>", nullptr));
        faultDiagnosisBtn->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\345\222\214\345\270\256\345\212\251\n"
"Fault/Help", nullptr));
        networkSettingBtn->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256\n"
"Network", nullptr));
        netmaskLabel->setText(QCoreApplication::translate("MainWindow", "255.255.255.0", nullptr));
        gatewayLabel->setText(QCoreApplication::translate("MainWindow", "192.168.10.1", nullptr));
        userSettingBtn->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\350\256\276\347\275\256\n"
"Account", nullptr));
        terminalsettingBtn->setText(QCoreApplication::translate("MainWindow", "\344\273\252\345\231\250\345\217\202\346\225\260\n"
"Ins para", nullptr));
        pushButton_printf->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\345\261\217\345\271\225\n"
"Print Screen", nullptr));
        instrumentSettingBtn->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\253\257\350\256\276\347\275\256\n"
"Terminal", nullptr));
        label_INSNAME->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\260\224\350\261\241\344\270\211\350\246\201\347\264\240\344\273\252\357\274\232MPT-I</p></body></html>", nullptr));
        IDLabel->setText(QCoreApplication::translate("MainWindow", "ID\357\274\232X91XDQYQ1401", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "845.6", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\260\224\346\270\251", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\260\224\345\216\213", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\233\250\351\207\217", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "25.6", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Hg", nullptr));
        longitudeLabel->setText(QCoreApplication::translate("MainWindow", "E103\302\26057\342\200\26245\342\200\263\357\274\214", nullptr));
        altitudeLabel->setText(QCoreApplication::translate("MainWindow", "1500m", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Error_C:000000", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\273\217\347\272\254\345\272\246\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\265\267\346\213\224\357\274\232", nullptr));
        dateLabel->setText(QCoreApplication::translate("MainWindow", "2022-1-1", nullptr));
        latitudeLabel->setText(QCoreApplication::translate("MainWindow", "N36\302\26018\342\200\26257\342\200\263", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\217\260\347\253\231\357\274\232", nullptr));
        stationLabel->setText(QCoreApplication::translate("MainWindow", "\346\230\214\345\271\263\345\217\260", nullptr));
        IPLabel->setText(QCoreApplication::translate("MainWindow", "IP\357\274\232192.168.10.50", nullptr));
        codeLabel->setText(QCoreApplication::translate("MainWindow", "\357\274\21011001\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
