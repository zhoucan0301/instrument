/********************************************************************************
** Form generated from reading UI file 'usersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTING_H
#define UI_USERSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSetting
{
public:
    QGroupBox *groupBox_1;
    QLabel *label_name;
    QLabel *label_password;
    QLabel *label_repassword;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_repassword;
    QPushButton *pushButton_usersetHelp;
    QPushButton *pushButton_userseting;
    QLineEdit *lineEdit_number;
    QLabel *label_number;
    QComboBox *comboBox_username;
    QPushButton *pushButton_initialization;
    QPushButton *pushButton_saveandexit;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_save;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *UserSetting)
    {
        if (UserSetting->objectName().isEmpty())
            UserSetting->setObjectName(QString::fromUtf8("UserSetting"));
        UserSetting->resize(800, 480);
        groupBox_1 = new QGroupBox(UserSetting);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setGeometry(QRect(10, 40, 601, 191));
        label_name = new QLabel(groupBox_1);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 20, 98, 31));
        label_password = new QLabel(groupBox_1);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(10, 60, 98, 31));
        label_repassword = new QLabel(groupBox_1);
        label_repassword->setObjectName(QString::fromUtf8("label_repassword"));
        label_repassword->setGeometry(QRect(10, 100, 98, 31));
        lineEdit_password = new QLineEdit(groupBox_1);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(90, 60, 261, 33));
        lineEdit_repassword = new QLineEdit(groupBox_1);
        lineEdit_repassword->setObjectName(QString::fromUtf8("lineEdit_repassword"));
        lineEdit_repassword->setGeometry(QRect(90, 100, 261, 33));
        pushButton_usersetHelp = new QPushButton(groupBox_1);
        pushButton_usersetHelp->setObjectName(QString::fromUtf8("pushButton_usersetHelp"));
        pushButton_usersetHelp->setGeometry(QRect(410, 20, 130, 71));
        pushButton_userseting = new QPushButton(groupBox_1);
        pushButton_userseting->setObjectName(QString::fromUtf8("pushButton_userseting"));
        pushButton_userseting->setGeometry(QRect(410, 100, 130, 71));
        lineEdit_number = new QLineEdit(groupBox_1);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));
        lineEdit_number->setGeometry(QRect(90, 140, 261, 33));
        label_number = new QLabel(groupBox_1);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setGeometry(QRect(10, 140, 121, 31));
        comboBox_username = new QComboBox(groupBox_1);
        comboBox_username->setObjectName(QString::fromUtf8("comboBox_username"));
        comboBox_username->setGeometry(QRect(90, 20, 261, 33));
        pushButton_initialization = new QPushButton(UserSetting);
        pushButton_initialization->setObjectName(QString::fromUtf8("pushButton_initialization"));
        pushButton_initialization->setGeometry(QRect(640, 40, 130, 51));
        pushButton_saveandexit = new QPushButton(UserSetting);
        pushButton_saveandexit->setObjectName(QString::fromUtf8("pushButton_saveandexit"));
        pushButton_saveandexit->setGeometry(QRect(640, 180, 130, 51));
        widget = new QWidget(UserSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 31));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 441, 25));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 0, 221, 25));
        pushButton_save = new QPushButton(UserSetting);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(640, 110, 130, 51));
        groupBox = new QGroupBox(UserSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 240, 781, 231));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 551, 25));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 591, 25));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 90, 581, 25));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 120, 621, 25));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 150, 601, 25));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(560, 20, 211, 201));

        retranslateUi(UserSetting);

        QMetaObject::connectSlotsByName(UserSetting);
    } // setupUi

    void retranslateUi(QWidget *UserSetting)
    {
        UserSetting->setWindowTitle(QCoreApplication::translate("UserSetting", "Form", nullptr));
        groupBox_1->setTitle(QCoreApplication::translate("UserSetting", "\347\224\250\346\210\267\350\256\276\347\275\256", nullptr));
        label_name->setText(QCoreApplication::translate("UserSetting", "\347\224\250   \346\210\267  \345\220\215:", nullptr));
        label_password->setText(QCoreApplication::translate("UserSetting", "\345\257\206         \347\240\201:", nullptr));
        label_repassword->setText(QCoreApplication::translate("UserSetting", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        pushButton_usersetHelp->setText(QCoreApplication::translate("UserSetting", "\346\226\260\345\242\236/Add", nullptr));
        pushButton_userseting->setText(QCoreApplication::translate("UserSetting", "\345\210\240\351\231\244/Del\n"
"\344\277\256\346\224\271/Edit", nullptr));
        label_number->setText(QCoreApplication::translate("UserSetting", "\346\216\210   \346\235\203  \347\240\201:", nullptr));
        pushButton_initialization->setText(QCoreApplication::translate("UserSetting", "\350\275\257\344\273\266\347\233\230/KeyB", nullptr));
        pushButton_saveandexit->setText(QCoreApplication::translate("UserSetting", "\351\200\200\345\207\272/Return", nullptr));
        label->setText(QCoreApplication::translate("UserSetting", "\345\234\260\351\234\207\345\211\215\345\205\206\344\272\214\346\260\247\345\214\226\347\242\263\345\234\250\347\272\277\345\210\206\346\236\220\344\273\252\342\200\224\342\200\224\347\224\250\346\210\267\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("UserSetting", "ID\357\274\232X91XDQYQ1402", nullptr));
        pushButton_save->setText(QCoreApplication::translate("UserSetting", "\344\277\235\345\255\230/Save", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserSetting", "\345\241\253\345\206\231\350\257\264\346\230\216", nullptr));
        label_3->setText(QCoreApplication::translate("UserSetting", "1.\347\224\250\346\210\267\345\220\215\345\217\257\350\276\223\345\205\245\350\213\261\346\226\207\357\274\214\345\255\227\347\254\246\346\225\260\351\207\217\345\260\217\344\272\21612\357\274\233", nullptr));
        label_4->setText(QCoreApplication::translate("UserSetting", "2.\345\257\206\347\240\201\345\217\212\347\241\256\350\256\244\345\257\206\347\240\201\347\224\261\346\225\260\345\255\227\345\222\214\345\244\247\345\260\217\345\206\231\345\255\227\346\257\215\347\273\204\346\210\220\357\274\214\345\255\227\347\254\246\350\214\203\345\233\2646~20\343\200\202", nullptr));
        label_5->setText(QCoreApplication::translate("UserSetting", "3.\350\256\276\347\275\256\345\217\257\347\241\256\350\256\244\347\224\250\346\210\267\344\277\241\346\201\257\357\274\214\350\277\233\350\241\214\346\225\260\346\215\256\346\227\245\345\277\227\347\232\204\350\256\260\345\275\225\343\200\202", nullptr));
        label_6->setText(QCoreApplication::translate("UserSetting", "4.\345\210\235\345\247\213\345\214\226\345\217\257\346\270\205\351\231\244\345\275\223\345\211\215\347\224\250\346\210\267\344\277\241\346\201\257\357\274\214\350\277\233\350\241\214\346\226\260\347\224\250\346\210\267\347\232\204\347\231\273\345\275\225\344\270\216\346\226\260\347\232\204\346\225\260\346\215\256\346\227\245\345\277\227\347\232\204\350\256\260\345\275\225\343\200\202", nullptr));
        label_8->setText(QCoreApplication::translate("UserSetting", "5.\344\273\205\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230\345\217\257\346\226\260\345\242\236\343\200\201\345\210\240\351\231\244\347\224\250\346\210\267\343\200\201\346\216\210\346\235\203\347\240\201\357\274\214\345\205\266\345\256\203\344\273\205\344\277\256\346\224\271\345\257\206\347\240\201\343\200\202", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserSetting: public Ui_UserSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTING_H
