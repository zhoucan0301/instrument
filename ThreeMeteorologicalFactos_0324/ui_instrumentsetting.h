/********************************************************************************
** Form generated from reading UI file 'instrumentsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTSETTING_H
#define UI_INSTRUMENTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstrumentSetting
{
public:
    QGroupBox *groupBox_instructInfo;
    QLabel *label_instructID;
    QLabel *label_number;
    QLabel *label_name;
    QLineEdit *lineEdit_instructID;
    QLineEdit *lineEdit_number;
    QLineEdit *lineEdit_name;
    QGroupBox *groupBox_location;
    QLineEdit *lineEdit_longitude;
    QLabel *label_longitude;
    QLabel *label_c;
    QLabel *label_dimension;
    QLineEdit *lineEdit_dimension;
    QLineEdit *lineEdit_altitude;
    QLabel *label;
    QCheckBox *checkBox_GPS;
    QCheckBox *checkBox_NTP;
    QLabel *label_date;
    QLineEdit *lineEdit_date;
    QLabel *label_time;
    QLineEdit *lineEdit_time;
    QPushButton *pushButton_initialization;
    QPushButton *pushButton_saveandexit;
    QPushButton *pushButton_instructInfoSet;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *InstrumentSetting)
    {
        if (InstrumentSetting->objectName().isEmpty())
            InstrumentSetting->setObjectName(QString::fromUtf8("InstrumentSetting"));
        InstrumentSetting->resize(800, 480);
        groupBox_instructInfo = new QGroupBox(InstrumentSetting);
        groupBox_instructInfo->setObjectName(QString::fromUtf8("groupBox_instructInfo"));
        groupBox_instructInfo->setGeometry(QRect(10, 30, 621, 106));
        label_instructID = new QLabel(groupBox_instructInfo);
        label_instructID->setObjectName(QString::fromUtf8("label_instructID"));
        label_instructID->setGeometry(QRect(20, 20, 101, 31));
        label_number = new QLabel(groupBox_instructInfo);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setGeometry(QRect(340, 20, 98, 31));
        label_name = new QLabel(groupBox_instructInfo);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(20, 60, 98, 31));
        lineEdit_instructID = new QLineEdit(groupBox_instructInfo);
        lineEdit_instructID->setObjectName(QString::fromUtf8("lineEdit_instructID"));
        lineEdit_instructID->setGeometry(QRect(100, 20, 171, 33));
        lineEdit_number = new QLineEdit(groupBox_instructInfo);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));
        lineEdit_number->setGeometry(QRect(420, 20, 181, 33));
        lineEdit_name = new QLineEdit(groupBox_instructInfo);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(100, 60, 501, 33));
        groupBox_location = new QGroupBox(InstrumentSetting);
        groupBox_location->setObjectName(QString::fromUtf8("groupBox_location"));
        groupBox_location->setGeometry(QRect(10, 140, 621, 106));
        lineEdit_longitude = new QLineEdit(groupBox_location);
        lineEdit_longitude->setObjectName(QString::fromUtf8("lineEdit_longitude"));
        lineEdit_longitude->setGeometry(QRect(60, 20, 121, 33));
        label_longitude = new QLabel(groupBox_location);
        label_longitude->setObjectName(QString::fromUtf8("label_longitude"));
        label_longitude->setGeometry(QRect(20, 20, 61, 31));
        label_c = new QLabel(groupBox_location);
        label_c->setObjectName(QString::fromUtf8("label_c"));
        label_c->setGeometry(QRect(360, 20, 61, 31));
        label_dimension = new QLabel(groupBox_location);
        label_dimension->setObjectName(QString::fromUtf8("label_dimension"));
        label_dimension->setGeometry(QRect(190, 20, 61, 31));
        lineEdit_dimension = new QLineEdit(groupBox_location);
        lineEdit_dimension->setObjectName(QString::fromUtf8("lineEdit_dimension"));
        lineEdit_dimension->setGeometry(QRect(230, 20, 121, 33));
        lineEdit_altitude = new QLineEdit(groupBox_location);
        lineEdit_altitude->setObjectName(QString::fromUtf8("lineEdit_altitude"));
        lineEdit_altitude->setGeometry(QRect(400, 20, 81, 33));
        label = new QLabel(groupBox_location);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(490, 20, 31, 31));
        checkBox_GPS = new QCheckBox(groupBox_location);
        checkBox_GPS->setObjectName(QString::fromUtf8("checkBox_GPS"));
        checkBox_GPS->setGeometry(QRect(530, 20, 81, 31));
        checkBox_GPS->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"width: 30px;\n"
"height: 30px;\n"
"}"));
        checkBox_GPS->setIconSize(QSize(50, 50));
        checkBox_NTP = new QCheckBox(groupBox_location);
        checkBox_NTP->setObjectName(QString::fromUtf8("checkBox_NTP"));
        checkBox_NTP->setGeometry(QRect(530, 60, 81, 31));
        checkBox_NTP->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"width: 30px;\n"
"height: 30px;\n"
"}"));
        checkBox_NTP->setIconSize(QSize(30, 30));
        label_date = new QLabel(groupBox_location);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(20, 60, 51, 31));
        lineEdit_date = new QLineEdit(groupBox_location);
        lineEdit_date->setObjectName(QString::fromUtf8("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(60, 60, 121, 33));
        label_time = new QLabel(groupBox_location);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(190, 60, 51, 31));
        lineEdit_time = new QLineEdit(groupBox_location);
        lineEdit_time->setObjectName(QString::fromUtf8("lineEdit_time"));
        lineEdit_time->setGeometry(QRect(230, 60, 121, 33));
        pushButton_initialization = new QPushButton(InstrumentSetting);
        pushButton_initialization->setObjectName(QString::fromUtf8("pushButton_initialization"));
        pushButton_initialization->setGeometry(QRect(650, 40, 130, 61));
        pushButton_saveandexit = new QPushButton(InstrumentSetting);
        pushButton_saveandexit->setObjectName(QString::fromUtf8("pushButton_saveandexit"));
        pushButton_saveandexit->setGeometry(QRect(650, 180, 130, 61));
        pushButton_instructInfoSet = new QPushButton(InstrumentSetting);
        pushButton_instructInfoSet->setObjectName(QString::fromUtf8("pushButton_instructInfoSet"));
        pushButton_instructInfoSet->setGeometry(QRect(650, 110, 130, 61));
        widget = new QWidget(InstrumentSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 28));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 491, 25));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(640, 0, 231, 25));
        groupBox = new QGroupBox(InstrumentSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 250, 771, 221));
        groupBox->setCheckable(false);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 591, 25));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 591, 25));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 90, 591, 25));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 120, 581, 25));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 150, 581, 25));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 180, 581, 25));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(576, 26, 191, 191));

        retranslateUi(InstrumentSetting);

        QMetaObject::connectSlotsByName(InstrumentSetting);
    } // setupUi

    void retranslateUi(QWidget *InstrumentSetting)
    {
        InstrumentSetting->setWindowTitle(QCoreApplication::translate("InstrumentSetting", "Form", nullptr));
        groupBox_instructInfo->setTitle(QCoreApplication::translate("InstrumentSetting", "\344\273\252\345\231\250\344\277\241\346\201\257", nullptr));
        label_instructID->setText(QCoreApplication::translate("InstrumentSetting", "\344\273\252   \345\231\250 ID:", nullptr));
        label_number->setText(QCoreApplication::translate("InstrumentSetting", "\345\217\260\347\253\231\344\273\243\347\240\201:", nullptr));
        label_name->setText(QCoreApplication::translate("InstrumentSetting", "\345\217\260\347\253\231\345\220\215\347\247\260:", nullptr));
        groupBox_location->setTitle(QCoreApplication::translate("InstrumentSetting", "\344\275\215\347\275\256/\346\227\266\351\227\264", nullptr));
        label_longitude->setText(QCoreApplication::translate("InstrumentSetting", "\347\273\217\345\272\246:", nullptr));
        label_c->setText(QCoreApplication::translate("InstrumentSetting", "\351\253\230\347\250\213:", nullptr));
        label_dimension->setText(QCoreApplication::translate("InstrumentSetting", "\347\272\254\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("InstrumentSetting", "\347\261\263", nullptr));
        checkBox_GPS->setText(QCoreApplication::translate("InstrumentSetting", "GPS", nullptr));
        checkBox_NTP->setText(QCoreApplication::translate("InstrumentSetting", "NTP", nullptr));
        label_date->setText(QCoreApplication::translate("InstrumentSetting", "\346\227\245\346\234\237:", nullptr));
        label_time->setText(QCoreApplication::translate("InstrumentSetting", "\346\227\266\351\227\264:", nullptr));
        pushButton_initialization->setText(QCoreApplication::translate("InstrumentSetting", "\350\275\257\344\273\266\347\233\230/KeyB", nullptr));
        pushButton_saveandexit->setText(QCoreApplication::translate("InstrumentSetting", "\351\200\200\345\207\272/Return", nullptr));
        pushButton_instructInfoSet->setText(QCoreApplication::translate("InstrumentSetting", "\344\277\235\345\255\230/Save", nullptr));
        label_2->setText(QCoreApplication::translate("InstrumentSetting", "\345\234\260\351\234\207\345\211\215\345\205\206\344\272\214\346\260\247\345\214\226\347\242\263\345\234\250\347\272\277\345\210\206\346\236\220\344\273\252\342\200\224\342\200\224\347\273\210\347\253\257\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("InstrumentSetting", "ID\357\274\232X91XDQYQ1402", nullptr));
        groupBox->setTitle(QCoreApplication::translate("InstrumentSetting", "\345\217\202\346\225\260\345\241\253\345\206\231\350\257\264\346\230\216", nullptr));
        label_4->setText(QCoreApplication::translate("InstrumentSetting", "1.\344\273\252\345\231\250ID\346\230\257\346\214\207\346\234\254\344\273\252\345\231\250\347\232\204ID \344\273\243\345\217\267\357\274\214\344\273\205\346\224\257\346\214\201\350\276\223\345\205\245\346\225\260\345\255\227\345\222\214\350\213\261\346\226\207\345\255\227\346\257\215.", nullptr));
        label_5->setText(QCoreApplication::translate("InstrumentSetting", "2.\345\217\260\347\253\231\344\273\243\347\240\201\346\230\257\346\214\207\345\275\223\345\211\215\344\273\252\345\231\250\347\232\204\346\211\200\345\234\250\347\232\204\345\217\260\347\253\231\344\273\243\347\240\201.", nullptr));
        label_6->setText(QCoreApplication::translate("InstrumentSetting", "3.GPS\345\244\215\351\200\211\346\241\206\346\230\257\346\214\207\351\200\232\350\277\207GPS\346\250\241\345\235\227\350\207\252\345\212\250\350\216\267\345\217\226\344\273\252\345\231\250\346\211\200\345\244\204\344\275\215\347\275\256\347\232\204\345\205\267\344\275\223\344\277\241\346\201\257\343\200\202\350\276\223\345\205\245\346\241\206", nullptr));
        label_7->setText(QCoreApplication::translate("InstrumentSetting", "\346\240\274\345\274\217\344\270\272\357\274\232\347\273\217\345\272\246/\347\272\254\345\272\246\357\274\232Xddd\302\260mm\342\200\231ss\342\200\231    \346\265\267\346\213\224\357\274\232x", nullptr));
        label_8->setText(QCoreApplication::translate("InstrumentSetting", "4.NTP\345\244\215\351\200\211\346\241\206\346\230\257\346\214\207\351\200\232\350\277\207\346\227\266\351\227\264\346\234\215\345\212\241\345\231\250\346\233\264\346\226\260\346\227\266\351\227\264\343\200\202\350\276\223\345\205\245\346\241\206\346\240\274\345\274\217\344\270\272\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("InstrumentSetting", "<html><head/><body><p>\346\227\245\346\234\237\357\274\232\345\271\264-\346\234\210-\346\227\245\357\274\233            \346\227\266\351\227\264\357\274\232\346\227\266-\345\210\206-\347\247\222\357\274\233</p></body></html>", nullptr));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InstrumentSetting: public Ui_InstrumentSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTSETTING_H
