/********************************************************************************
** Form generated from reading UI file 'userloginform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGINFORM_H
#define UI_USERLOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userLoginForm
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label;
    QPushButton *pushButton_cannel;
    QLineEdit *lineEdit_usernames1;
    QLabel *label_2;
    QPushButton *pushButton_convert;
    QLineEdit *lineEdit_passwords1;
    QPushButton *pushButton_ok;
    QLabel *label_7;

    void setupUi(QWidget *userLoginForm)
    {
        if (userLoginForm->objectName().isEmpty())
            userLoginForm->setObjectName(QString::fromUtf8("userLoginForm"));
        userLoginForm->setEnabled(true);
        userLoginForm->resize(390, 480);
        groupBox = new QGroupBox(userLoginForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 200, 351, 261));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 331, 25));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 331, 25));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 331, 25));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 180, 331, 25));
        label = new QLabel(userLoginForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 81, 25));
        pushButton_cannel = new QPushButton(userLoginForm);
        pushButton_cannel->setObjectName(QString::fromUtf8("pushButton_cannel"));
        pushButton_cannel->setGeometry(QRect(140, 130, 111, 61));
        lineEdit_usernames1 = new QLineEdit(userLoginForm);
        lineEdit_usernames1->setObjectName(QString::fromUtf8("lineEdit_usernames1"));
        lineEdit_usernames1->setGeometry(QRect(120, 20, 161, 33));
        label_2 = new QLabel(userLoginForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 81, 25));
        pushButton_convert = new QPushButton(userLoginForm);
        pushButton_convert->setObjectName(QString::fromUtf8("pushButton_convert"));
        pushButton_convert->setGeometry(QRect(20, 130, 111, 61));
        lineEdit_passwords1 = new QLineEdit(userLoginForm);
        lineEdit_passwords1->setObjectName(QString::fromUtf8("lineEdit_passwords1"));
        lineEdit_passwords1->setGeometry(QRect(120, 70, 161, 33));
        pushButton_ok = new QPushButton(userLoginForm);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(260, 130, 111, 61));
        label_7 = new QLabel(userLoginForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 20, 81, 81));

        retranslateUi(userLoginForm);

        QMetaObject::connectSlotsByName(userLoginForm);
    } // setupUi

    void retranslateUi(QWidget *userLoginForm)
    {
        userLoginForm->setWindowTitle(QCoreApplication::translate("userLoginForm", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("userLoginForm", "\346\263\250\346\204\217\344\272\213\351\241\271\357\274\201", nullptr));
        label_3->setText(QCoreApplication::translate("userLoginForm", "1.\350\213\245\350\246\201\346\233\264\346\215\242\345\275\223\345\211\215\347\224\250\346\210\267\357\274\214\350\257\267\346\214\211\342\200\234\345\210\207\346\215\242\347\224\250\346\210\267\342\200\234\346\214\211", nullptr));
        label_4->setText(QCoreApplication::translate("userLoginForm", "\351\222\256\357\274\214\344\275\277\350\203\275\347\224\250\346\210\267\345\220\215\346\226\207\346\234\254\346\241\206\357\274\214\351\200\211\346\213\251\346\210\226\350\276\223\345\205\245\346\226\260\347\232\204\347\224\250", nullptr));
        label_5->setText(QCoreApplication::translate("userLoginForm", "\346\210\267\345\220\215\347\247\260\343\200\202", nullptr));
        label_6->setText(QCoreApplication::translate("userLoginForm", "2.\345\257\206\347\240\201\351\224\231\350\257\2573\346\254\241\357\274\214\345\260\206\344\274\232\351\224\201\346\255\273\350\256\276\347\275\256\346\214\211\351\224\25630\345\210\206\351\222\237\343\200\202", nullptr));
        label->setText(QCoreApplication::translate("userLoginForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pushButton_cannel->setText(QCoreApplication::translate("userLoginForm", "\345\217\226\346\266\210/C", nullptr));
        label_2->setText(QCoreApplication::translate("userLoginForm", "\345\257\206    \347\240\201\357\274\232", nullptr));
        pushButton_convert->setText(QCoreApplication::translate("userLoginForm", "\345\210\207\346\215\242\347\224\250\346\210\267", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("userLoginForm", "\347\241\256\350\256\244/OK", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class userLoginForm: public Ui_userLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGINFORM_H
