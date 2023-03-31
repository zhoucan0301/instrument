#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

#include "qcustomplot.h"
#include "axistag.h"
#include "networksetting.h"
#include "instrumentsetting.h"
#include "usersetting.h"
#include "userloginform.h"
#include "saveform.h"

extern int i;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //设置qcustomplot画图属性，实时
    void setupRealtimeDataDemo(QCustomPlot *customPlot);

signals:
    void newday();

public slots:
    void chageLabelText();

private:
    Ui::MainWindow *ui;

    /* QList int类型容器 */
    QList<float> atdata, apdata, rgdata;
    QHostAddress IPaddress;

    QSerialPort *serialport;
    AxisTag *mTag1;
    AxisTag *mTag2;
    AxisTag *mTag3;
    NetworkSetting* networkSetting;
    InstrumentSetting* instrumentSetting;
    UserSetting* userSetting;
    saveForm* saveform;
    /* tcp服务器 */
    QTcpServer *tcpServer;
    /* 通信套接字 */
    QTcpSocket *tcpSocket;


    void serialportInit();
    void setupPlot();    
    void styleInit();

    void apDataRequest();
    void rainsensorTimeset();
    void rgDataRequest();
    void showIpInfo();
    void showNetmaskInfo();
private slots:
    void receiveSetInstrumentData(QString data);
    void receiveSetStationData(QString data);
    void timerUpdate();
    void newTxt();
    void analyzeData();
    void clientConnected();

    void on_pushButton_printf_clicked();

public:

    QCustomPlot *customPlot;

    bool Light;
    void TimeUpdate();

    void DaylightModeSetting();
    void NightModeSetting();
    void changeDispalyMode();

};
#endif // MAINWINDOW_H
