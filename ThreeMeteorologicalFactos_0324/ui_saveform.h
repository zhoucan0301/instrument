/********************************************************************************
** Form generated from reading UI file 'saveform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFORM_H
#define UI_SAVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saveForm
{
public:
    QPushButton *pushButton_return;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_30;
    QRadioButton *radioButton_60;
    QRadioButton *radioButton_120;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_CO2;
    QLineEdit *lineEdit_Tem;
    QCheckBox *checkBox_SuctionPump;
    QLineEdit *lineEdit_SuctionPump;
    QLabel *label_7;
    QPushButton *pushButton_CO2;
    QPushButton *pushButton_Tem;
    QPushButton *pushButton_SuctionPump;
    QPushButton *pushButton_save;
    QPushButton *pushButton_keyboard;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_3;

    void setupUi(QWidget *saveForm)
    {
        if (saveForm->objectName().isEmpty())
            saveForm->setObjectName(QString::fromUtf8("saveForm"));
        saveForm->resize(800, 480);
        pushButton_return = new QPushButton(saveForm);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(650, 180, 130, 61));
        widget = new QWidget(saveForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 28));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 441, 25));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 0, 221, 25));
        groupBox = new QGroupBox(saveForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 621, 61));
        radioButton_1 = new QRadioButton(groupBox);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setGeometry(QRect(10, 20, 111, 31));
        radioButton_1->setStyleSheet(QString::fromUtf8("QRadioButton::indicator{width: 25px;\n"
"height: 25px;}"));
        radioButton_30 = new QRadioButton(groupBox);
        radioButton_30->setObjectName(QString::fromUtf8("radioButton_30"));
        radioButton_30->setGeometry(QRect(120, 20, 162, 31));
        radioButton_30->setStyleSheet(QString::fromUtf8("QRadioButton::indicator{width: 25px;\n"
"height: 25px;}"));
        radioButton_60 = new QRadioButton(groupBox);
        radioButton_60->setObjectName(QString::fromUtf8("radioButton_60"));
        radioButton_60->setGeometry(QRect(280, 20, 162, 31));
        radioButton_60->setStyleSheet(QString::fromUtf8("QRadioButton::indicator{width: 25px;\n"
"height: 25px;}"));
        radioButton_120 = new QRadioButton(groupBox);
        radioButton_120->setObjectName(QString::fromUtf8("radioButton_120"));
        radioButton_120->setGeometry(QRect(450, 20, 171, 31));
        radioButton_120->setStyleSheet(QString::fromUtf8("QRadioButton::indicator{width: 25px;\n"
"height: 25px;}"));
        groupBox_2 = new QGroupBox(saveForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 621, 141));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 211, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 211, 31));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 100, 171, 31));
        lineEdit_CO2 = new QLineEdit(groupBox_2);
        lineEdit_CO2->setObjectName(QString::fromUtf8("lineEdit_CO2"));
        lineEdit_CO2->setGeometry(QRect(170, 20, 301, 33));
        lineEdit_Tem = new QLineEdit(groupBox_2);
        lineEdit_Tem->setObjectName(QString::fromUtf8("lineEdit_Tem"));
        lineEdit_Tem->setGeometry(QRect(170, 60, 301, 33));
        checkBox_SuctionPump = new QCheckBox(groupBox_2);
        checkBox_SuctionPump->setObjectName(QString::fromUtf8("checkBox_SuctionPump"));
        checkBox_SuctionPump->setGeometry(QRect(10, 100, 134, 31));
        checkBox_SuctionPump->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"width: 30px;\n"
"height: 30px;\n"
"}"));
        lineEdit_SuctionPump = new QLineEdit(groupBox_2);
        lineEdit_SuctionPump->setObjectName(QString::fromUtf8("lineEdit_SuctionPump"));
        lineEdit_SuctionPump->setGeometry(QRect(300, 100, 101, 33));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 100, 71, 31));
        pushButton_CO2 = new QPushButton(groupBox_2);
        pushButton_CO2->setObjectName(QString::fromUtf8("pushButton_CO2"));
        pushButton_CO2->setGeometry(QRect(500, 20, 91, 36));
        pushButton_Tem = new QPushButton(groupBox_2);
        pushButton_Tem->setObjectName(QString::fromUtf8("pushButton_Tem"));
        pushButton_Tem->setGeometry(QRect(500, 60, 91, 36));
        pushButton_SuctionPump = new QPushButton(groupBox_2);
        pushButton_SuctionPump->setObjectName(QString::fromUtf8("pushButton_SuctionPump"));
        pushButton_SuctionPump->setGeometry(QRect(500, 100, 91, 36));
        pushButton_save = new QPushButton(saveForm);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(650, 110, 130, 61));
        pushButton_keyboard = new QPushButton(saveForm);
        pushButton_keyboard->setObjectName(QString::fromUtf8("pushButton_keyboard"));
        pushButton_keyboard->setGeometry(QRect(650, 40, 130, 61));
        groupBox_3 = new QGroupBox(saveForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 250, 781, 221));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 581, 25));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 70, 571, 25));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 100, 531, 25));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 20, 211, 191));

        retranslateUi(saveForm);

        QMetaObject::connectSlotsByName(saveForm);
    } // setupUi

    void retranslateUi(QWidget *saveForm)
    {
        saveForm->setWindowTitle(QCoreApplication::translate("saveForm", "Form", nullptr));
        pushButton_return->setText(QCoreApplication::translate("saveForm", "\351\200\200\345\207\272/Return", nullptr));
        label->setText(QCoreApplication::translate("saveForm", "\345\234\260\351\234\207\345\211\215\345\205\206\344\272\214\346\260\247\345\214\226\347\242\263\345\234\250\347\272\277\345\210\206\346\236\220\344\273\252\342\200\224\342\200\224\344\273\252\345\231\250\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("saveForm", "ID\357\274\232X91XDQYQ1402", nullptr));
        groupBox->setTitle(QCoreApplication::translate("saveForm", "\346\225\260\346\215\256\345\210\267\346\226\260\347\216\207\351\200\211\346\213\251", nullptr));
        radioButton_1->setText(QCoreApplication::translate("saveForm", "1Hz/1s", nullptr));
        radioButton_30->setText(QCoreApplication::translate("saveForm", "0.03Hz/30s", nullptr));
        radioButton_60->setText(QCoreApplication::translate("saveForm", "0.017Hz/60s", nullptr));
        radioButton_120->setText(QCoreApplication::translate("saveForm", "0.008Hz/120s", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("saveForm", "\344\273\252\345\231\250\347\241\254\344\273\266\344\277\241\346\201\257\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("saveForm", "\344\272\214\346\260\247\345\214\226\347\242\263\344\274\240\346\204\237\345\231\250\345\234\260\345\235\200:", nullptr));
        label_5->setText(QCoreApplication::translate("saveForm", "\346\270\251  \346\271\277  \345\272\246\344\274\240\346\204\237\345\231\250\345\234\260\345\235\200:", nullptr));
        label_6->setText(QCoreApplication::translate("saveForm", "\345\220\270\346\260\224\346\263\265\346\265\201\351\207\217\350\256\276\347\275\256:", nullptr));
        checkBox_SuctionPump->setText(QCoreApplication::translate("saveForm", "\345\274\200\345\220\270\346\260\224\346\263\265", nullptr));
        label_7->setText(QCoreApplication::translate("saveForm", "L/min", nullptr));
        pushButton_CO2->setText(QCoreApplication::translate("saveForm", "\350\256\276\347\275\256", nullptr));
        pushButton_Tem->setText(QCoreApplication::translate("saveForm", "\350\256\276\347\275\256", nullptr));
        pushButton_SuctionPump->setText(QCoreApplication::translate("saveForm", "\350\256\276\347\275\256", nullptr));
        pushButton_save->setText(QCoreApplication::translate("saveForm", "\344\277\235\345\255\230/Save", nullptr));
        pushButton_keyboard->setText(QCoreApplication::translate("saveForm", "\350\275\257\344\273\266\347\233\230/KeyB", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("saveForm", "\345\217\202\346\225\260\345\241\253\345\206\231\350\257\264\346\230\216", nullptr));
        label_8->setText(QCoreApplication::translate("saveForm", "1.\346\225\260\346\215\256\345\210\267\346\226\260\347\216\207\346\230\257\346\214\207\350\257\273\345\217\226\344\274\240\346\204\237\345\231\250\347\232\204\351\200\237\347\216\207\344\270\216\347\225\214\351\235\242\346\225\260\346\215\256\346\230\276\347\244\272\347\232\204\351\200\237\347\216\207\343\200\202", nullptr));
        label_9->setText(QCoreApplication::translate("saveForm", "2.\344\274\240\346\204\237\345\231\250\345\234\260\345\235\200\346\230\2578\344\270\252\345\255\227\350\212\202\347\232\20416\350\277\233\345\210\266\346\225\260\343\200\202", nullptr));
        label_10->setText(QCoreApplication::translate("saveForm", "3.\345\220\270\346\260\224\346\263\265\345\274\200\345\220\257\344\273\245\345\220\216\357\274\214\345\217\257\344\273\245\346\211\213\345\212\250\350\256\276\347\275\256\345\220\270\346\260\224\346\263\265\347\232\204\346\265\201\351\207\217\343\200\202", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class saveForm: public Ui_saveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFORM_H
