#ifndef INSTRUMENTSETTING_H
#define INSTRUMENTSETTING_H

#include <QWidget>
#include <QString>
#include <QMetaType>
//#include "mainwindow.h"
#include "keyboard.h"

namespace Ui {
class InstrumentSetting;
}

class InstrumentSetting : public QWidget
{
    Q_OBJECT

public:
    explicit InstrumentSetting(QWidget *parent = nullptr);
    ~InstrumentSetting();

    void readPara();
    void writePara();
    bool eventFilter(QObject *watched, QEvent *event);
    std::vector<QString> emitUIdata;



signals:
    void instrumentSettingBack();

private slots:
    void on_pushButton_instructInfoSet_clicked();
    //void on_pushButton_locationSet_clicked();
    void on_pushButton_saveandexit_clicked();
    void on_pushButton_saves_clicked();
    void on_pushButton_initialization_clicked();

private:
    Ui::InstrumentSetting *ui;
    void CallKeyBord(QLineEdit *curlineEdit);
    KeyBoard *keyBoard;

};

#endif // INSTRUMENTSETTING_H
