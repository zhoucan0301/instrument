/********************************************************************************
** Form generated from reading UI file 'networksetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSETTING_H
#define UI_NETWORKSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkSetting
{
public:
    QGroupBox *groupBox_networkset;
    QLabel *label_ip;
    QLabel *label_networkChild;
    QLabel *label_gateway;
    QLineEdit *lineEdit_IPAddress;
    QLineEdit *lineEdit_subnetMask;
    QLineEdit *lineEdit_gateway;
    QPushButton *pushButton_saveandexit;
    QPushButton *pushButton_initialization;
    QPushButton *pushButton_networkSet;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLineEdit *lineEdit_udpAddress;
    QLineEdit *lineEdit_udpPort;
    QLineEdit *lineEdit_middlewarePort;
    QLabel *label_4;
    QLineEdit *lineEdit_middlewareIP;
    QLineEdit *lineEdit_TimerPort;
    QLabel *label_5;
    QLineEdit *lineEdit_TimerIP;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_IPv6Address;
    QLineEdit *lineEdit_IPv4Gateway;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_IPv6length;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_IPv4;
    QCheckBox *checkBox_IPv6;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit_Info;
    QPushButton *pushButton_del;
    QPushButton *pushButton_C;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_A;
    QPushButton *pushButton_B;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_D;
    QPushButton *pushButton_5;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_E;
    QPushButton *pushButton_2;
    QPushButton *pushButton_doubledian;
    QPushButton *pushButton_dian;
    QPushButton *pushButton_F;
    QPushButton *pushButton_0;

    void setupUi(QWidget *NetworkSetting)
    {
        if (NetworkSetting->objectName().isEmpty())
            NetworkSetting->setObjectName(QString::fromUtf8("NetworkSetting"));
        NetworkSetting->resize(800, 480);
        groupBox_networkset = new QGroupBox(NetworkSetting);
        groupBox_networkset->setObjectName(QString::fromUtf8("groupBox_networkset"));
        groupBox_networkset->setGeometry(QRect(10, 30, 271, 141));
        label_ip = new QLabel(groupBox_networkset);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(10, 20, 98, 31));
        label_networkChild = new QLabel(groupBox_networkset);
        label_networkChild->setObjectName(QString::fromUtf8("label_networkChild"));
        label_networkChild->setGeometry(QRect(10, 60, 98, 31));
        label_gateway = new QLabel(groupBox_networkset);
        label_gateway->setObjectName(QString::fromUtf8("label_gateway"));
        label_gateway->setGeometry(QRect(10, 100, 98, 31));
        lineEdit_IPAddress = new QLineEdit(groupBox_networkset);
        lineEdit_IPAddress->setObjectName(QString::fromUtf8("lineEdit_IPAddress"));
        lineEdit_IPAddress->setGeometry(QRect(90, 20, 171, 33));
        lineEdit_subnetMask = new QLineEdit(groupBox_networkset);
        lineEdit_subnetMask->setObjectName(QString::fromUtf8("lineEdit_subnetMask"));
        lineEdit_subnetMask->setGeometry(QRect(90, 60, 171, 33));
        lineEdit_gateway = new QLineEdit(groupBox_networkset);
        lineEdit_gateway->setObjectName(QString::fromUtf8("lineEdit_gateway"));
        lineEdit_gateway->setGeometry(QRect(90, 100, 171, 33));
        pushButton_saveandexit = new QPushButton(NetworkSetting);
        pushButton_saveandexit->setObjectName(QString::fromUtf8("pushButton_saveandexit"));
        pushButton_saveandexit->setGeometry(QRect(650, 210, 141, 71));
        pushButton_initialization = new QPushButton(NetworkSetting);
        pushButton_initialization->setObjectName(QString::fromUtf8("pushButton_initialization"));
        pushButton_initialization->setGeometry(QRect(650, 30, 141, 71));
        pushButton_networkSet = new QPushButton(NetworkSetting);
        pushButton_networkSet->setObjectName(QString::fromUtf8("pushButton_networkSet"));
        pushButton_networkSet->setGeometry(QRect(650, 120, 141, 71));
        widget = new QWidget(NetworkSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 28));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 421, 25));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 0, 221, 25));
        groupBox = new QGroupBox(NetworkSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(290, 30, 351, 141));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 111, 31));
        lineEdit_udpAddress = new QLineEdit(groupBox);
        lineEdit_udpAddress->setObjectName(QString::fromUtf8("lineEdit_udpAddress"));
        lineEdit_udpAddress->setGeometry(QRect(110, 20, 151, 33));
        lineEdit_udpPort = new QLineEdit(groupBox);
        lineEdit_udpPort->setObjectName(QString::fromUtf8("lineEdit_udpPort"));
        lineEdit_udpPort->setGeometry(QRect(270, 20, 71, 33));
        lineEdit_middlewarePort = new QLineEdit(groupBox);
        lineEdit_middlewarePort->setObjectName(QString::fromUtf8("lineEdit_middlewarePort"));
        lineEdit_middlewarePort->setGeometry(QRect(270, 60, 71, 33));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 121, 31));
        lineEdit_middlewareIP = new QLineEdit(groupBox);
        lineEdit_middlewareIP->setObjectName(QString::fromUtf8("lineEdit_middlewareIP"));
        lineEdit_middlewareIP->setGeometry(QRect(110, 60, 151, 33));
        lineEdit_TimerPort = new QLineEdit(groupBox);
        lineEdit_TimerPort->setObjectName(QString::fromUtf8("lineEdit_TimerPort"));
        lineEdit_TimerPort->setGeometry(QRect(270, 100, 71, 33));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 121, 31));
        lineEdit_TimerIP = new QLineEdit(groupBox);
        lineEdit_TimerIP->setObjectName(QString::fromUtf8("lineEdit_TimerIP"));
        lineEdit_TimerIP->setGeometry(QRect(110, 100, 151, 33));
        groupBox_2 = new QGroupBox(NetworkSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 180, 491, 101));
        lineEdit_IPv6Address = new QLineEdit(groupBox_2);
        lineEdit_IPv6Address->setObjectName(QString::fromUtf8("lineEdit_IPv6Address"));
        lineEdit_IPv6Address->setGeometry(QRect(90, 20, 391, 33));
        lineEdit_IPv4Gateway = new QLineEdit(groupBox_2);
        lineEdit_IPv4Gateway->setObjectName(QString::fromUtf8("lineEdit_IPv4Gateway"));
        lineEdit_IPv4Gateway->setGeometry(QRect(90, 60, 261, 33));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 98, 31));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 98, 31));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 60, 51, 31));
        lineEdit_IPv6length = new QLineEdit(groupBox_2);
        lineEdit_IPv6length->setObjectName(QString::fromUtf8("lineEdit_IPv6length"));
        lineEdit_IPv6length->setGeometry(QRect(390, 60, 91, 33));
        groupBox_3 = new QGroupBox(NetworkSetting);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 180, 131, 101));
        checkBox_IPv4 = new QCheckBox(groupBox_3);
        checkBox_IPv4->setObjectName(QString::fromUtf8("checkBox_IPv4"));
        checkBox_IPv4->setGeometry(QRect(30, 20, 91, 31));
        checkBox_IPv4->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"width: 30px;\n"
"height: 30px;\n"
"}"));
        checkBox_IPv6 = new QCheckBox(groupBox_3);
        checkBox_IPv6->setObjectName(QString::fromUtf8("checkBox_IPv6"));
        checkBox_IPv6->setGeometry(QRect(30, 60, 91, 31));
        checkBox_IPv6->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"width: 30px;\n"
"height: 30px;\n"
"}"));
        groupBox_4 = new QGroupBox(NetworkSetting);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(510, 285, 281, 191));
        textEdit_Info = new QTextEdit(groupBox_4);
        textEdit_Info->setObjectName(QString::fromUtf8("textEdit_Info"));
        textEdit_Info->setGeometry(QRect(0, 18, 280, 170));
        textEdit_Info->setLineWrapColumnOrWidth(2);
        textEdit_Info->setReadOnly(true);
        textEdit_Info->setTabStopWidth(100);
        pushButton_del = new QPushButton(NetworkSetting);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(10, 290, 91, 41));
        pushButton_C = new QPushButton(NetworkSetting);
        pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
        pushButton_C->setGeometry(QRect(110, 290, 91, 41));
        pushButton_7 = new QPushButton(NetworkSetting);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(210, 290, 91, 41));
        pushButton_8 = new QPushButton(NetworkSetting);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(310, 290, 91, 41));
        pushButton_9 = new QPushButton(NetworkSetting);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(410, 290, 91, 41));
        pushButton_OK = new QPushButton(NetworkSetting);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(10, 340, 91, 41));
        pushButton_A = new QPushButton(NetworkSetting);
        pushButton_A->setObjectName(QString::fromUtf8("pushButton_A"));
        pushButton_A->setGeometry(QRect(10, 390, 91, 41));
        pushButton_B = new QPushButton(NetworkSetting);
        pushButton_B->setObjectName(QString::fromUtf8("pushButton_B"));
        pushButton_B->setGeometry(QRect(10, 440, 91, 41));
        pushButton_4 = new QPushButton(NetworkSetting);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 340, 91, 41));
        pushButton_6 = new QPushButton(NetworkSetting);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(410, 340, 91, 41));
        pushButton_D = new QPushButton(NetworkSetting);
        pushButton_D->setObjectName(QString::fromUtf8("pushButton_D"));
        pushButton_D->setGeometry(QRect(110, 340, 91, 41));
        pushButton_5 = new QPushButton(NetworkSetting);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 340, 91, 41));
        pushButton_1 = new QPushButton(NetworkSetting);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(210, 390, 91, 41));
        pushButton_3 = new QPushButton(NetworkSetting);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 390, 91, 41));
        pushButton_E = new QPushButton(NetworkSetting);
        pushButton_E->setObjectName(QString::fromUtf8("pushButton_E"));
        pushButton_E->setGeometry(QRect(110, 390, 91, 41));
        pushButton_2 = new QPushButton(NetworkSetting);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 390, 91, 41));
        pushButton_doubledian = new QPushButton(NetworkSetting);
        pushButton_doubledian->setObjectName(QString::fromUtf8("pushButton_doubledian"));
        pushButton_doubledian->setGeometry(QRect(210, 440, 91, 41));
        pushButton_dian = new QPushButton(NetworkSetting);
        pushButton_dian->setObjectName(QString::fromUtf8("pushButton_dian"));
        pushButton_dian->setGeometry(QRect(410, 440, 91, 41));
        pushButton_F = new QPushButton(NetworkSetting);
        pushButton_F->setObjectName(QString::fromUtf8("pushButton_F"));
        pushButton_F->setGeometry(QRect(110, 440, 91, 41));
        pushButton_0 = new QPushButton(NetworkSetting);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(310, 440, 91, 41));

        retranslateUi(NetworkSetting);

        QMetaObject::connectSlotsByName(NetworkSetting);
    } // setupUi

    void retranslateUi(QWidget *NetworkSetting)
    {
        NetworkSetting->setWindowTitle(QCoreApplication::translate("NetworkSetting", "Form", nullptr));
        groupBox_networkset->setTitle(QCoreApplication::translate("NetworkSetting", "\347\275\221\347\273\234\345\234\260\345\235\200", nullptr));
        label_ip->setText(QCoreApplication::translate("NetworkSetting", "IP  \345\234\260   \345\235\200:", nullptr));
        label_networkChild->setText(QCoreApplication::translate("NetworkSetting", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
        label_gateway->setText(QCoreApplication::translate("NetworkSetting", "\347\275\221        \345\205\263:", nullptr));
        pushButton_saveandexit->setText(QCoreApplication::translate("NetworkSetting", "\351\200\200\345\207\272/Return", nullptr));
        pushButton_initialization->setText(QCoreApplication::translate("NetworkSetting", "\347\274\272\347\234\201/Default", nullptr));
        pushButton_networkSet->setText(QCoreApplication::translate("NetworkSetting", "\344\277\256\346\224\271/Modify", nullptr));
        label->setText(QCoreApplication::translate("NetworkSetting", "\345\234\260\351\234\207\345\211\215\345\205\206\344\272\214\346\260\247\345\214\226\347\242\263\345\234\250\347\272\277\345\210\206\346\236\220\344\273\252\342\200\224\342\200\224\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("NetworkSetting", "ID\357\274\232X91XDQYQ1402", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NetworkSetting", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200IPv4", nullptr));
        label_3->setText(QCoreApplication::translate("NetworkSetting", "UDP/\347\253\257  \345\217\243:", nullptr));
        label_4->setText(QCoreApplication::translate("NetworkSetting", "\344\270\255\351\227\264\344\273\266\345\234\260\345\235\200:", nullptr));
        label_5->setText(QCoreApplication::translate("NetworkSetting", "\346\227\266\351\227\264\346\234\215\345\212\241\345\231\250:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("NetworkSetting", "\346\234\254\346\234\272\345\234\260\345\235\200IPv6", nullptr));
        label_6->setText(QCoreApplication::translate("NetworkSetting", "IPv6\345\234\260\345\235\200:", nullptr));
        label_7->setText(QCoreApplication::translate("NetworkSetting", "IPv6\347\275\221\345\205\263:", nullptr));
        label_8->setText(QCoreApplication::translate("NetworkSetting", "\351\225\277\345\272\246:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("NetworkSetting", "IP\345\215\217\350\256\256", nullptr));
        checkBox_IPv4->setText(QCoreApplication::translate("NetworkSetting", "IPv4", nullptr));
        checkBox_IPv6->setText(QCoreApplication::translate("NetworkSetting", "IPv6", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("NetworkSetting", "\350\256\276\347\275\256\350\257\264\346\230\216", nullptr));
        pushButton_del->setText(QCoreApplication::translate("NetworkSetting", "Delete", nullptr));
        pushButton_C->setText(QCoreApplication::translate("NetworkSetting", "C", nullptr));
        pushButton_7->setText(QCoreApplication::translate("NetworkSetting", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("NetworkSetting", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("NetworkSetting", "9", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("NetworkSetting", "OK", nullptr));
        pushButton_A->setText(QCoreApplication::translate("NetworkSetting", "A", nullptr));
        pushButton_B->setText(QCoreApplication::translate("NetworkSetting", "B", nullptr));
        pushButton_4->setText(QCoreApplication::translate("NetworkSetting", "4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("NetworkSetting", "6", nullptr));
        pushButton_D->setText(QCoreApplication::translate("NetworkSetting", "D", nullptr));
        pushButton_5->setText(QCoreApplication::translate("NetworkSetting", "5", nullptr));
        pushButton_1->setText(QCoreApplication::translate("NetworkSetting", "1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("NetworkSetting", "3", nullptr));
        pushButton_E->setText(QCoreApplication::translate("NetworkSetting", "E", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NetworkSetting", "2", nullptr));
        pushButton_doubledian->setText(QCoreApplication::translate("NetworkSetting", ":", nullptr));
        pushButton_dian->setText(QCoreApplication::translate("NetworkSetting", ".", nullptr));
        pushButton_F->setText(QCoreApplication::translate("NetworkSetting", "F", nullptr));
        pushButton_0->setText(QCoreApplication::translate("NetworkSetting", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkSetting: public Ui_NetworkSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETTING_H
