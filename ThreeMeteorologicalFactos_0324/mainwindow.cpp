#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcustomplot.h>
#include "axistag.h"
#include <QPen>
#include <QTime>
#include <QDir>
#include <QTextStream>
#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QDebug>
#include <QFont>
#include <QNetworkInterface>
#include <QTimer>
#include <unistd.h>

#include "instrumentsetting.h"

/* 定义全局变量 */
int i;
QString strID,strLocation,strCodeLoca,strIP,strNetworkChild,strGateway,strLongitude,strLatitude,strAltitude;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    /* 实例化子界面 */
    networkSetting = new NetworkSetting;
    instrumentSetting = new InstrumentSetting;
    userSetting = new UserSetting;
    saveform = new saveForm;
    /* 实例化 tcp 服务器与 tcp 套接字 */
    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    /* 串口初始化 */
    serialportInit();
//    setupPlot();
//    /* 主界面标签初始化 */
//    styleInit();

    //sleep(2);
    /* 主界面时间刷新 */
    timer->start(1000);

    /* 子界面返回跳转 */
    connect(instrumentSetting,&InstrumentSetting::instrumentSettingBack,this,&MainWindow::chageLabelText);
    connect(instrumentSetting,&InstrumentSetting::instrumentSettingBack,[=](){
        instrumentSetting->hide();
        this->show();
       // &MainWindow::chageLabelText;
    });

    connect(networkSetting,&NetworkSetting::networkSettingBack,[=](){
        networkSetting->hide();
        this->show();
    });
//    connect(userSetting,&UserSetting::UserSettingBack,[=](){
//        userSetting->hide();
//        this->show();
//    });
    connect(saveform,&saveForm::saveformback,[=](){
        saveform->hide();
        this->show();
    });
    /* 主界面点击按钮跳转 */
//    connect(ui->instrumentSettingBtn,&QPushButton::clicked,[=](){
//        this->hide();
//        instrumentSetting->show();
//    });
//    connect(ui->networkSettingBtn,&QPushButton::clicked,[=](){
//        this->hide();
//        networkSetting->show();
//    });
    connect(ui->userSettingBtn,&QPushButton::clicked,[=](){
        this->hide();
        userSetting->show();
    });


//    setupRealtimeDataDemo(ui->customPlot);
//    ui->customPlot->replot();

    /* 将重新设置的时间同步到雨量传感器 */
//    connect(userSetting, &UserSetting::timeSet,[=](){
//        /* 雨量传感器时间设置 */
//        rainsensorTimeset();
//    });
    /* 在仪器设置界面将设置信息同步到主界面相应标签 */
    connect(instrumentSetting, SIGNAL(setinstrument(QString)), this, SLOT(receiveSetInstrumentData(QString)));
    connect(instrumentSetting, SIGNAL(setstation(QString)), this, SLOT(receiveSetStationData(QString)));
    /* 网络设置界面设置信息并同步到主界面 */
    connect(networkSetting, &NetworkSetting::setNet,[=](){
        showIpInfo();
        showNetmaskInfo();
        tcpServer->listen(QHostAddress(ui->IPLabel->text()), 8086);
    });

  // NightModeSetting();
  DaylightModeSetting();
    
    connect(ui->pushButton_printf,SIGNAL(clicked()),this,SLOT(on_pushButton_printf_clicked()),Qt::UniqueConnection);

    /* 主界面时间更新 */
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    /* 每天新建文件 */
    connect(this, SIGNAL(newday()), this, SLOT(newTxt()));
    /* TCP */
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    //ui->widget_19->setStyleSheet("background-color: rgb(43, 55, 75)");
     //ui->widget_20->setStyleSheet("background-color: rgb(180, 199, 231)");
    QFont font ( "Microsoft YaHei", 25, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->label_3->setFont(font);
    ui->timeLabel->setAlignment(Qt::AlignLeft);



    //定义一个查询窗口（用户登陆界面）
    userLoginForm *s1 = new userLoginForm();
    connect(ui->instrumentSettingBtn,&QPushButton::clicked,[=](){
            //当前窗口隐藏
            //this->hide();
            //查询窗口显示
            s1->show();
            s1->UIcount = 1;
            });
    connect(ui->networkSettingBtn,&QPushButton::clicked,[=](){
            s1->show();
            s1->UIcount = 2;
            });
    connect(ui->terminalsettingBtn,&QPushButton::clicked,[=](){
            s1->show();
            s1->UIcount = 3;
            });
//    connect(ui->userSettingBtn,&QPushButton::clicked,[=](){
//            s1->show();
//            s1->UIcount = 4;
//            });
//    connect(ui->return_saveForm,&QPushButton::clicked,[=](){
//            s1->show();
//            s1->UIcount = 5;
//            });
    //监测查询窗口s的回退信号
    connect(s1,&userLoginForm::back,[=](){
            //隐藏查询窗口
            s1->hide();
            //显示当前窗口
            this->show();

           });



}


MainWindow::~MainWindow()
{
    delete ui;
}


/* 数据曲线设置 */
void MainWindow::setupPlot()
{

    /* 将曲线区域背景色设为透明 */
    ui->customPlot->setBackground(Qt::transparent);
    ui->customPlot->setStyleSheet("background: transparent;");

    if(ui->customPlot->legend->itemCount()==0){

    /* 温度曲线属性设置 */
    ui->customPlot->addGraph();//添加一条曲线
    QPen pen;

    pen.setWidth(1);//设置画笔线条宽度
    pen.setColor(Qt::red);
    ui->customPlot->graph(0)->setPen(pen);//设置画笔颜色
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20))); //设置曲线画刷背景
    ui->customPlot->graph(0)->setName("气温");
    ui->customPlot->graph(0)->setAntialiasedFill(false);
    ui->customPlot->graph(0)->setLineStyle((QCPGraph::LineStyle)1);//曲线画笔
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));//曲线形状

    /* 气压曲线属性设置 */
    ui->customPlot->addGraph();//添加一条曲线
    pen.setColor(Qt::blue);
    ui->customPlot->graph(1)->setPen(pen);//设置画笔颜色
    ui->customPlot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20))); //设置曲线画刷背景
    ui->customPlot->graph(1)->setName("气压");
    ui->customPlot->graph(1)->setAntialiasedFill(false);
    ui->customPlot->graph(1)->setLineStyle((QCPGraph::LineStyle)1);//曲线画笔
    ui->customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));//曲线形状

    /* 雨量曲线属性设置 */
    ui->customPlot->addGraph();//添加一条曲线
    pen.setColor(Qt::green);
    ui->customPlot->graph(2)->setPen(pen);//设置画笔颜色
    ui->customPlot->graph(2)->setBrush(QBrush(QColor(0, 255, 0, 20))); //设置曲线画刷背景
    ui->customPlot->graph(2)->setName("雨量");
    ui->customPlot->graph(2)->setAntialiasedFill(false);
    ui->customPlot->graph(2)->setLineStyle((QCPGraph::LineStyle)1);//曲线画笔
    ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,5));//曲线形状

    //设置图表
    ui->customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(80);//设置yAxis2右边距离

   // ui->customPlot->xAxis->setLabel(QStringLiteral("时间/min"));//设置x坐标轴名称
    ui->customPlot->xAxis->setLabelColor(QColor(20,20,20));//设置x坐标轴名称颜色
    ui->customPlot->xAxis->ticker()->setTickCount(12);//设置刻度间距
    ui->customPlot->xAxis->setRange(0,60);//设定x轴的范围

    ui->customPlot->yAxis->setVisible(true);
    ui->customPlot->yAxis2->setVisible(true);
    //ui->widget->yAxis->setLabel(QStringLiteral("PH & TDS"));//设置y坐标轴名称
    ui->customPlot->yAxis->setTickLabels(true);//显示刻度值
    ui->customPlot->yAxis->setLabelColor(QColor(20,20,20));//设置y坐标轴名称颜色
    ui->customPlot->yAxis->ticker()->setTickCount(11);//设置刻度间距
    ui->customPlot->yAxis->setRange(-20,1200);//设定y轴范围
    ui->customPlot->yAxis->ticker()->setTickOrigin(-20);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setLabelColor(QColor(20,20,20));//设置y坐标轴名称颜色
    ui->customPlot->yAxis2->ticker()->setTickCount(11);//设置刻度间距
    ui->customPlot->yAxis2->setRange(-20,1200);//设定y轴范围
    ui->customPlot->yAxis2->ticker()->setTickOrigin(-20);



    //ui->widget->axisRect()->setupFullAxesBox(true);//设置缩放，拖拽，设置图表的分类图标显示位置
    //ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom| QCP::iSelectAxes);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop | Qt::AlignRight);//图例显示位置右上

    ui->customPlot->legend->setVisible(true);//显示图例
  //  qDebug()<<ui->customPlot->legend->itemCount();



    mTag1 = new AxisTag(ui->customPlot->graph(0)->valueAxis());
    mTag1->setPen(ui->customPlot->graph(0)->pen());
    mTag2 = new AxisTag(ui->customPlot->graph(1)->valueAxis());
    mTag2->setPen(ui->customPlot->graph(1)->pen());
    mTag3 = new AxisTag(ui->customPlot->graph(2)->valueAxis());
    mTag3->setPen(ui->customPlot->graph(2)->pen());
  }

   ui->customPlot->legend->setBrush(QBrush(QColor(255, 255, 255, 0)));

}


void MainWindow::NightModeSetting()
{

    /* 主界面标签初始化 */
    styleInit();


    QPalette pe1;
    pe1.setColor(QPalette::ButtonText,QColor(105, 105, 105));
    //ui->return_saveForm->setPalette(pe1);
    ui->centralwidget->setStyleSheet("QWidget{background: black;}");


//    ui->faultDiagnosisBtn->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->networkSettingBtn->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->instrumentSettingBtn->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->pushButton_printf->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->userSettingBtn->setStyleSheet("background-color: rgb(43, 55, 75)");
   // ui->return_saveForm->setStyleSheet("background-color: rgb(38, 38, 38)");
    ui->terminalsettingBtn->setStyleSheet("background-color: rgb(43, 55, 75)");
    //ui->faultDiagnosisBtn->setStyleSheet("color: rgb(255, 255, 255)");
    ui->widget->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->widget_2->setStyleSheet("background-color: rgb(38, 38, 38)");
    ui->faultDiagnosisBtn->setStyleSheet("background-color: rgb(38, 38, 38)");
    ui->widget_3->setStyleSheet("background-color: rgb(82, 82, 82)");

//    ui->customPlot->setBackground(QBrush(Qt::black));
//    ui->customPlot->setStyleSheet("QWidget{background: black;}");
//    ui->customPlot->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
//    ui->customPlot->setStyleSheet(QString::fromUtf8("#customPlot{border:3px solid red}"));


    //设置label字体
    QFont xFont = ui->customPlot->xAxis->labelFont();
    xFont.setPixelSize(20);
    ui->customPlot ->xAxis->setLabelFont(xFont);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot->legend->setBrush(QColor(255,255,255));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    ui->customPlot->legend->setTextColor(QColor(201, 201, 201, 201));

    ui->customPlot->xAxis->setTickLabelColor(QColor(180, 199, 231));
    ui->customPlot->yAxis->setTickLabelColor(QColor(180, 199, 231));
    //设置坐标轴颜色
    ui->customPlot->xAxis->setBasePen(QPen(QColor(180, 199, 231)));
    ui->customPlot->xAxis->setTickPen(QPen(QColor(180, 199, 231)));
    ui->customPlot->xAxis->setSubTickPen(QPen(QColor(180, 199, 231)));
    ui->customPlot->yAxis->setBasePen(QPen(QColor(180, 199, 231)));
    ui->customPlot->yAxis->setTickPen(QPen(QColor(180, 199, 231)));
    ui->customPlot->yAxis->setSubTickPen(QPen(QColor(180, 199, 231)));

//    for(i=0;i<3;i++){
//       ui->customPlot->graph(i)->setBrush(QBrush(QColor(255, 255, 255, 0))); ;
//    }
    setupPlot();
    ui->customPlot->replot();

    QFont font ( "Microsoft YaHei", 25, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->label->setFont(font);
    ui->label_14->setFont(font);
    ui->label_3->setFont(font);
    ui->label_14->setStyleSheet("color:rgb(189, 214, 238);");
    ui->label->setStyleSheet("color:rgb(247, 202, 172);");
    ui->label_3->setStyleSheet("color:rgb(226, 239, 217);");
    ui->label_14->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    QFont font1 ( "宋体", 15, 50);
    ui->label_INSNAME->setFont(font1);
    ui->IDLabel->setFont(font1);
    ui->label_INSNAME->setStyleSheet("color:rgb(201, 201, 201);");
    ui->IDLabel->setStyleSheet("color:rgb(100, 149, 237);");

    ui->label_10->setFont(font1);
    ui->stationLabel->setFont(font1);
    ui->codeLabel->setFont(font1);
    ui->IPLabel->setFont(font1);
    ui->label_10->setStyleSheet("color:rgb(201, 201, 201);");
    ui->stationLabel->setStyleSheet("color:rgb(100, 149, 237);");
    ui->codeLabel->setStyleSheet("color:rgb(100, 149, 237);");
    ui->IPLabel->setStyleSheet("color:rgb(100, 149, 237);");

    QFont font2 ( "宋体", 10, 50);
    ui->netmaskLabel->setFont(font2);
    ui->gatewayLabel->setFont(font2);
  //  ui->label_18->setFont(font2);
    ui->netmaskLabel->setStyleSheet("color:rgb(43, 55, 75);");
    ui->gatewayLabel->setStyleSheet("color:rgb(43, 55, 75);");
   // ui->label_18->setStyleSheet("color:rgb(180, 199, 231);");

    ui->label_6->setFont(font1);
    ui->label_5->setFont(font1);
    ui->label_4->setFont(font1);
    ui->timeLabel->setFont(font1);
    ui->label_6->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_5->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_4->setStyleSheet("color:rgb(201, 201, 201);");
    ui->timeLabel->setStyleSheet("color:rgb(65, 105, 225);");
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_7->setStyleSheet("color:rgb(105, 105, 105);");
    ui->label_8->setStyleSheet("color:rgb(105, 105, 105);");
    ui->label_9->setStyleSheet("color:rgb(105, 105, 105);");
    //ui->return_saveForm->setStyleSheet("color:rgb(105, 105, 105);");

    QFont font3 ( "宋体", 12, 50);
    ui->label_13->setFont(font3);
    ui->label_12->setFont(font3);
    ui->longitudeLabel->setFont(font3);
    ui->latitudeLabel->setFont(font3);
    ui->altitudeLabel->setFont(font3);
    ui->dateLabel->setFont(font3);
    ui->label_11->setFont(font3);
    ui->label_13->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_12->setStyleSheet("color:rgb(201, 201, 201);");

    ui->longitudeLabel->setStyleSheet("color:rgb(180, 199, 231);");
    ui->latitudeLabel->setStyleSheet("color:rgb(180, 199, 231);");
    ui->altitudeLabel->setStyleSheet("color:rgb(180, 199, 231);");
    ui->dateLabel->setStyleSheet("color:rgb(180, 199, 231);");
    ui->label_11->setStyleSheet("color:rgb(180, 199, 231);");

    Light=false;
    qDebug()<<ui->customPlot->xAxis->labelColor();
    qDebug()<<ui->customPlot->xAxis->tickLabelColor();




    QPalette pe10;
    pe10.setColor(QPalette::ButtonText,QColor(201, 201, 201));
    ui->faultDiagnosisBtn->setPalette(pe10);
    ui->networkSettingBtn->setPalette(pe10);
    ui->pushButton_printf->setPalette(pe10);
    ui->instrumentSettingBtn->setPalette(pe10);
    ui->userSettingBtn->setPalette(pe10);
    ui->terminalsettingBtn->setPalette(pe10);


}


void MainWindow::DaylightModeSetting()
{
    setupPlot();
    /* 主界面标签初始化 */
    styleInit();

    ui->centralwidget->setStyleSheet("background-color: rgb(222, 220, 220)");
 //   ui->return_saveForm->setStyleSheet("background-color: rgb(255, 255, 255)");

    ui->faultDiagnosisBtn->setStyleSheet("background-color: rgb(222, 220, 220)");
    ui->networkSettingBtn->setStyleSheet("background-color: rgb(222, 220, 220)");
    ui->instrumentSettingBtn->setStyleSheet("background-color: rgb(222, 220, 220)");
    ui->pushButton_printf->setStyleSheet("background-color: rgb(222, 220, 220)");
    ui->userSettingBtn->setStyleSheet("background-color: rgb(222, 220, 220)");
    //ui->return_saveForm->setStyleSheet("background-color: rgb(38, 38, 38)");
    ui->terminalsettingBtn->setStyleSheet("background-color: rgb(222, 220, 220)");
    //ui->faultDiagnosisBtn->setStyleSheet("color: rgb(255, 255, 255)");
    QPalette pe10;
    pe10.setColor(QPalette::ButtonText,QColor(0, 0, 0));
    ui->faultDiagnosisBtn->setPalette(pe10);
    ui->networkSettingBtn->setPalette(pe10);
    ui->pushButton_printf->setPalette(pe10);
    ui->instrumentSettingBtn->setPalette(pe10);
    ui->userSettingBtn->setPalette(pe10);
    ui->terminalsettingBtn->setPalette(pe10);

    QPalette pe1;
    pe1.setColor(QPalette::ButtonText,QColor(0, 0, 0));
   // ui->return_saveForm->setPalette(pe1);
    ui->widget->setStyleSheet("background-color: rgb(74, 44, 252)");
    ui->widget_2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->widget_3->setStyleSheet("background-color: rgb(255, 255, 255)");


//    ui->customPlot->setStyleSheet("QWidget{background: white;}");
//    ui->customPlot->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
//    ui->customPlot->setStyleSheet(QString::fromUtf8("#customPlot{border:3px solid red}"));

    ui->customPlot->xAxis->setTickLabelColor(QColor(0, 0, 0));
    ui->customPlot->yAxis->setTickLabelColor(QColor(0, 0, 0));
    //设置坐标轴颜色
    ui->customPlot->xAxis->setBasePen(QPen(QColor(0, 0, 0)));
    ui->customPlot->xAxis->setTickPen(QPen(QColor(0, 0, 0)));
    ui->customPlot->xAxis->setSubTickPen(QPen(QColor(0, 0, 0)));
    //设置label字体
    ui->customPlot->yAxis->setBasePen(QPen(Qt::black));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::black));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::black));
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot->legend->setBrush(QColor(255,255,255,0));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    ui->customPlot->legend->setTextColor(QColor(0, 0, 0, 255));
    ui->customPlot->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->customPlot->setBackground(QBrush(Qt::white));

    ui->customPlot->replot();

    QFont font ( "Microsoft YaHei", 25, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->label->setFont(font);
    ui->label_14->setFont(font);
    ui->label_3->setFont(font);
    ui->label_14->setStyleSheet("color:rgb(74, 44, 252);");
    ui->label->setStyleSheet("color:rgb(190, 143, 0);");
    ui->label_3->setStyleSheet("color:rgb(83, 129, 53);");
    ui->label_14->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    QFont font1 ( "宋体", 15, 50);
    ui->label_INSNAME->setFont(font1);
    ui->IDLabel->setFont(font1);
    ui->label_INSNAME->setStyleSheet("color:rgb(201, 201, 201);");
    ui->IDLabel->setStyleSheet("color:rgb(180, 180, 180);");

    ui->label_10->setFont(font1);
    ui->stationLabel->setFont(font1);
    ui->codeLabel->setFont(font1);
    ui->IPLabel->setFont(font1);
    ui->label_10->setStyleSheet("color:rgb(0, 0, 0);");
    ui->stationLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->codeLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->IPLabel->setStyleSheet("color:rgb(74, 44, 252);");

    QFont font2 ( "宋体", 10, 50);
    ui->netmaskLabel->setFont(font2);
    ui->gatewayLabel->setFont(font2);
   // ui->label_18->setFont(font2);
    ui->netmaskLabel->setStyleSheet("color:rgb(43, 55, 75);");
    ui->gatewayLabel->setStyleSheet("color:rgb(43, 55, 75);");
  //  ui->label_18->setStyleSheet("color:rgb(0, 0, 0);");

    ui->label_6->setFont(font1);
    ui->label_5->setFont(font1);
    ui->label_4->setFont(font1);
    ui->timeLabel->setFont(font1);
    ui->label_6->setStyleSheet("color:rgb(0, 0, 0);");
    ui->label_5->setStyleSheet("color:rgb(0, 0, 0);");
    ui->label_4->setStyleSheet("color:rgb(0, 0, 0);");
    ui->timeLabel->setStyleSheet("color:rgb(65, 105, 225);");
    ui->timeLabel->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_7->setStyleSheet("color:rgb(105, 105, 105);");
    ui->label_8->setStyleSheet("color:rgb(105, 105, 105);");
    ui->label_9->setStyleSheet("color:rgb(105, 105, 105);");
    //ui->return_saveForm->setStyleSheet("color:rgb(105, 105, 105);");

    QFont font3 ( "宋体", 12, 50);
    ui->label_13->setFont(font3);
    ui->label_12->setFont(font3);
    ui->longitudeLabel->setFont(font3);
    ui->latitudeLabel->setFont(font3);
    ui->altitudeLabel->setFont(font3);
    ui->dateLabel->setFont(font3);
    ui->label_11->setFont(font3);
    ui->label_13->setStyleSheet("color:rgb(0, 0, 0);");
    ui->label_12->setStyleSheet("color:rgb(0, 0, 0);");

    ui->longitudeLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->latitudeLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->altitudeLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->dateLabel->setStyleSheet("color:rgb(74, 44, 252);");
    ui->label_11->setStyleSheet("color:rgb(74, 44, 252);");

    Light=true;
}



/* 串口初始化 */
void MainWindow::serialportInit()
{
    serialport = new QSerialPort();

    serialport->setPortName("ttymxc2"); //设置串口号
    serialport->setBaudRate(QSerialPort::Baud9600); //设置波特
    serialport->setDataBits(QSerialPort::Data8); //设置数据位数
    serialport->setParity(QSerialPort::NoParity);//设置奇偶校验
    serialport->setStopBits(QSerialPort::OneStop);//设置停止位
    serialport->setFlowControl(QSerialPort::NoFlowControl);//非流控制

    if (!serialport->open(QIODevice::ReadWrite))
    {QMessageBox::about(NULL, "错误",
                        "串口无法打开！可能串口已经被占用！");}
    else {
        connect(serialport, SIGNAL(readyRead()),
                this, SLOT(analyzeData()));
    }
}

/* 气压数据请求 */
void MainWindow::apDataRequest()
{
    QByteArray apdataRequest;
    apdataRequest.append('\x02');
    apdataRequest.append('\x03');
    apdataRequest.append('\x00');
    apdataRequest.append('\x00');
    apdataRequest.append('\x00');
    apdataRequest.append('\x01');
    apdataRequest.append('\x84');
    apdataRequest.append('\x39');

    serialport->write(apdataRequest);
}

/* 将系统时间同步到雨量计 */
void MainWindow::rainsensorTimeset()
{
    QByteArray arr;
    QString temp1;
    int temp2;

    QDateTime time = QDateTime::currentDateTime();
    QString presentTime = time.toString("yyyy/MM/dd/hh/mm");
    /* 雨量计下载时间指令：55+0A+10+年+月+日+时+分+00+Xor */
    arr[0]=0x55;
    arr[1]=0x0A;
    arr[2]=0x10;
    /* 以"/"为标准进行分隔,保留第0个到第0个字符串 */
    temp1 = presentTime.section("/",0,0);
    /* 将字符串转换为10进制数 */
    temp2 = (temp1.toInt(nullptr,10)-2000);
    arr[3] = temp2;
    temp1 = presentTime.section("/",1,1);
    temp2 = temp1.toInt(nullptr,10);
    arr[4] = temp2;
    temp1 = presentTime.section("/",2,2);
    temp2 = temp1.toInt(nullptr,10);
    arr[5] = temp2;
    temp1 = presentTime.section("/",3,3);
    temp2 = temp1.toInt(nullptr,10);
    arr[6] = temp2;
    temp1 = presentTime.section("/",4,4);
    temp2 = temp1.toInt(nullptr,10);
    arr[7] = temp2;
    arr[8] = 0x00;
    arr[9] = arr[0]^arr[1]^arr[2]^arr[3]^arr[4]^arr[5]^arr[6]^arr[7]^arr[8];
    serialport->write(arr);
}

/* 雨量数据请求 */
void MainWindow::rgDataRequest()
{
    QByteArray rgdataRequest;
    QString temp1;
    int temp2;
    /* 雨量计分钟数据请求指令：55+0A+05+年+月+日+时+小时数+00+Xor */
    QDateTime time = QDateTime::currentDateTime();
    QString presentTime = time.toString("yyyy/MM/dd/hh");
    rgdataRequest[0] = 0x55;
    rgdataRequest[1] = 0x0A;
    rgdataRequest[2] = 0x05;

    temp1 = presentTime.section("/",0,0);
    temp2 = (temp1.toInt(nullptr,10)-2000);
    rgdataRequest[3] = temp2;
    temp1 = presentTime.section("/",1,1);
    temp2 = temp1.toInt(nullptr,10);
    rgdataRequest[4] = temp2;
    temp1 = presentTime.section("/",2,2);
    temp2 = temp1.toInt(nullptr,10);
    rgdataRequest[5] = temp2;
    temp1 = presentTime.section("/",3,3);
    temp2 = temp1.toInt(nullptr,10);
    rgdataRequest[6] = temp2;

    rgdataRequest[7] = 0x01;
    rgdataRequest[8] = 0x00;
    rgdataRequest[9] = rgdataRequest[0]^rgdataRequest[1]^rgdataRequest[2]^rgdataRequest[3]^rgdataRequest[4]^rgdataRequest[5]^rgdataRequest[6]^rgdataRequest[7]^rgdataRequest[8];

    serialport->write(rgdataRequest);
}

/* 主界面标签样式设置 */
void MainWindow::styleInit()
{
    QFont font ;
    font.setFamily("宋体");
    /* 大小 */
    font.setPixelSize(18);

    ui->IDLabel->setFont(font);
    ui->stationLabel->setFont(font);
    ui->codeLabel->setFont(font);
    ui->IPLabel->setFont(font);
    ui->netmaskLabel->setFont(font);
    ui->gatewayLabel->setFont(font);
    ui->longitudeLabel->setFont(font);
    ui->latitudeLabel->setFont(font);
    ui->altitudeLabel->setFont(font);

     ui->timeLabel->setGeometry(280,0,101,41);
    //QFont font1 ( "宋体", 15, 50);
     //  ui->label_2->setFont(font1);
      // ui->label_2->setStyleSheet("color:rgb(201, 201, 201);");

    QFont font1 ( "Microsoft YaHei", 25, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->label->setFont(font1);
    ui->label_14->setFont(font1);
    ui->label_3->setFont(font1);
    ui->label_14->setStyleSheet("color:rgb(189, 214, 238);");
    ui->label->setStyleSheet("color:rgb(247, 202, 172);");
    ui->label_3->setStyleSheet("color:rgb(226, 239, 217);");
    ui->label_14->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);

    ui->IDLabel->setAlignment(Qt::AlignCenter);
    ui->stationLabel->setAlignment(Qt::AlignVCenter);
    ui->codeLabel->setAlignment(Qt::AlignCenter);
    ui->IPLabel->setAlignment(Qt::AlignCenter);
    ui->netmaskLabel->setAlignment(Qt::AlignLeft);
    ui->gatewayLabel->setAlignment(Qt::AlignLeft);
    ui->longitudeLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->latitudeLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->altitudeLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    ui->IDLabel->setStyleSheet("color:rgb(128,0,0)");
    ui->stationLabel->setStyleSheet("color:rgb(128,0,0)");
    ui->codeLabel->setStyleSheet("color:rgb(128,0,0)");
    ui->IPLabel->setStyleSheet("color:rgb(0,64,128)");
    ui->netmaskLabel->setStyleSheet("color:rgb(0,64,128)");
    ui->gatewayLabel->setStyleSheet("color:rgb(0,64,128)");
    ui->longitudeLabel->setStyleSheet("color:rgb(0,128,0)");
    ui->latitudeLabel->setStyleSheet("color:rgb(0,128,0)");
    ui->altitudeLabel->setStyleSheet("color:rgb(0,128,0)");
}


void MainWindow::showIpInfo()
{
    /* 通过QHostInfo的localHostName函数获取主机名称 */
    QString str,str1;

    /* 获取所有的网络接口，
     * QNetworkInterface类提供主机的IP地址和网络接口的列表 */
    QList<QNetworkInterface> list            = QNetworkInterface::allInterfaces();

    /* 遍历list */
    foreach (QNetworkInterface interface, list) {
        /* QNetworkAddressEntry类存储IP地址子网掩码和广播地址 */
        QList<QNetworkAddressEntry> entryList
                = interface.addressEntries();

        /* 遍历entryList */
        if(interface.name()=="eth0"){
            foreach (QNetworkAddressEntry entry, entryList) {
                /* 过滤IPv6地址，只留下IPv4 */
                if (entry.ip().protocol() ==
                        QAbstractSocket::IPv4Protocol) {
                    str = entry.ip().toString();
                    break;
                }
            }
        }
    }

    /* 网络信息显示到IPLabel */
    ui->IPLabel->setText(str);

    /* gateway信息显示 */
    str = str.left(str.size()-2);
    str1 = str + "1";
    ui->gatewayLabel->setText(str1);
}

void MainWindow::showNetmaskInfo()
{
    /* 通过QHostInfo的localHostName函数获取主机名称 */
    QString str;

    /* 获取所有的网络接口，
     * QNetworkInterface类提供主机的IP地址和网络接口的列表 */
    QList<QNetworkInterface> list
            = QNetworkInterface::allInterfaces();

    /* 遍历list */
    foreach (QNetworkInterface interface, list) {
        /* QNetworkAddressEntry类存储IP地址子网掩码和广播地址 */
        QList<QNetworkAddressEntry> entryList
                = interface.addressEntries();

        /* 遍历entryList */
         if(interface.name()=="eth0"){
            foreach (QNetworkAddressEntry entry, entryList) {
                /* 过滤IPv6地址，只留下IPv4 */
                if (entry.ip().protocol() ==
                        QAbstractSocket::IPv4Protocol) {
                    str= entry.netmask().toString();
                    break;
                }
            }
        }
    }

    ui->netmaskLabel->setText(str);
}

void MainWindow::analyzeData()
{   
    /* 获取系统时间 */
    QDateTime time = QDateTime::currentDateTime();
    QString presentTime = time.toString("yyyyMMdd");
    QString strAll;
    /* 定义数据保存路径 */
    QString filePath = "/instrument/meteorological/"+presentTime+".txt";
    /* 读出数据文件所有内容 */
    QFile readFile(filePath);
    if(readFile.open((QIODevice::ReadOnly | QIODevice::Text)))
    {
        /* 在构造 QTextStream 类的对象时，需要传递一个 QFile 类的对象 */
        QTextStream stream(&readFile);
        /* 读出全部文本内容 */
        strAll=stream.readAll();
    }
    readFile.close();

    QFile writeFile(filePath);
    /* 定义temp为串口读取的所有数据 */
    QByteArray temp = serialport->readAll();
    qDebug()<<"temp:"<<temp;
    float sensorData=0.0;
    if(!temp.isEmpty())
    {
        /* 气温数据解析，设置气温变送器每60秒发送一次数据 */
        if(0x01 == temp[0])
        {
            sensorData = ((qint16)temp[3]<<8 | temp[4])/10.00;
            qDebug()<<"atSensorData:"<<sensorData;
            /* 温度传感器数据写到当天的文本 */
            if(writeFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream stream(&writeFile);
                stream << strAll << QString::number(sensorData) << " ";
            }
            writeFile.close();

            /* TCP发送温度数据字符串 */
            if(tcpSocket->state() == tcpSocket->ConnectedState) {
                /* 发送消息 */
                tcpSocket->write(QString::number(sensorData).toUtf8().data());
            }

            /* 把数据显示到曲线 */
            atdata.append(sensorData);
            /* 当储存数据的个数大于最大值时，把第一个数据删除 */
            while (atdata.size() > 61) {
                ui->customPlot->graph(0)->data()->remove(atdata.first());
                /* 移除data中第一个数据 */
                atdata.removeFirst();
            }
            /*清除曲线数据*/
            ui->customPlot->graph(0)->data().data()->clear();
            /* 添加点i表示第i个点的x轴的位置 */
            for (int i = 0; i < atdata.size(); ++i) {
                ui->customPlot->graph(0)->addData(i,atdata.at(i));
            }

            /* 气压数据请求 */
            apDataRequest();
         /* 气压数据解析 */
        }else if(0x02 == temp[0]){
            sensorData = ((quint16)temp[3]<<8 | temp[4])/10.00;
            qDebug()<<"apSensorData:"<<sensorData;
            if(writeFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream stream(&writeFile);
                stream << strAll << QString::number(sensorData) << " ";
            }
            writeFile.close();

            if(tcpSocket->state() == tcpSocket->ConnectedState) {
                /* 发送消息 */
                tcpSocket->write(QString::number(sensorData).toUtf8().data());
            }

            apdata.append(sensorData);
            /* 当储存数据的个数大于最大值时，把第一个数据删除 */
            while (apdata.size() > 61) {
                ui->customPlot->graph(1)->data()->remove(apdata.first());
                /* 移除data中第一个数据 */
                apdata.removeFirst();
            }
            /*清除曲线数据*/
            ui->customPlot->graph(1)->data().data()->clear();
            /* 添加点i 表示第i个点的x轴的位置 */
            for (int i = 0; i < apdata.size(); ++i) {
                ui->customPlot->graph(1)->addData(i,apdata.at(i));
            }

            /* 雨量数据请求 */
            rgDataRequest();
         /* 雨量数据解析 */
        }else if(0x05 == temp[2]){
            QTime time = QTime::currentTime();
            int minute = time.minute();

            sensorData = ((quint16)(temp.at(7+minute*2)) <<8 | (temp.at(8+minute*2)))/100.00;
            qDebug()<<"rgSensorData:"<<sensorData;
            if(writeFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream stream(&writeFile);
                stream << strAll << QString::number(sensorData) << " " << endl;
            }
            writeFile.close();
            if(tcpSocket->state() == tcpSocket->ConnectedState) {
                /* 发送消息 */
                tcpSocket->write(QString::number(sensorData).toUtf8().data());
            }
            rgdata.append(sensorData);
            /* 当储存数据的个数大于最大值时，把第一个数据删除 */
            while (rgdata.size() > 61) {
                ui->customPlot->graph(2)->data()->remove(rgdata.first());
                /* 移除data中第一个数据 */
                rgdata.removeFirst();
            }
            /*清除曲线数据*/
            ui->customPlot->graph(2)->data().data()->clear();
            /* 添加点i 表示第i个点的x轴的位置 */
            for (int i = 0; i < rgdata.size(); ++i) {
                ui->customPlot->graph(2)->addData(i,rgdata.at(i));
            }
        }
        double graph1Value = ui->customPlot->graph(0)->dataMainValue(ui->customPlot->graph(0)->dataCount()-1);
        double graph2Value = ui->customPlot->graph(1)->dataMainValue(ui->customPlot->graph(1)->dataCount()-1);
        double graph3Value = ui->customPlot->graph(2)->dataMainValue(ui->customPlot->graph(2)->dataCount()-1);

        mTag1->updatePosition(graph1Value);
        mTag2->updatePosition(graph2Value);
        mTag3->updatePosition(graph3Value);
        mTag1->setText(QString::number(graph1Value, 'f', 2));
        mTag2->setText(QString::number(graph2Value, 'f', 2));
        mTag3->setText(QString::number(graph3Value, 'f', 2));
        ui->customPlot->replot();//每次画完曲线一定要更新显示
    }
}

/* 将仪器设置界面的内容同步的到主界面 */
void MainWindow::receiveSetInstrumentData(QString data)
{
    if(i==0)
    {
        ui->IDLabel->setText(data);
    }
    if(i==1)
    {
        ui->stationLabel->setText(data);
    }
    if(i==2)
    {
        ui->codeLabel->setText(data);
    }
    i++;
    if(i==3)
    {
        i=0;
    }
}

void MainWindow::receiveSetStationData(QString data)
{
    if(i==0)
    {
        ui->longitudeLabel->setText(data);
    }
    if(i==1)
    {
        ui->latitudeLabel->setText(data);
    }
    if(i==2)
    {
        ui->altitudeLabel->setText(data);
    }
    i++;
    if(i==3)
    {
        i=0;
    }
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy年MM月dd日");
    QString str1 = time.toString("dddd");
    QString str2 = time.toString("hh:mm:ss");
    ui->dateLabel->setText(str);
   // ui->weekLabel->setText(str1);
    ui->timeLabel->setText(str2);

    if(str2 == "00:00:00")
    {
        emit newday();
    }  

   // changeDispalyMode();

}

void MainWindow::changeDispalyMode(){
    QTime currentTime=QTime::currentTime();
    if(currentTime>=QTime(0,0)&&currentTime<=QTime(6,0)){
        NightModeSetting();
    }else{
        DaylightModeSetting();
    }
    MainWindow::update();
}


/* 每天新建一个.txt文件 */
void MainWindow::newTxt()
{   
    QDateTime time = QDateTime::currentDateTime();
    QString presentTime = time.toString("yyyyMMdd");
    /* 指定一个绝对路径来存放文件 */
    QString filePath = "/instrument/meteorological/"+presentTime+".txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream stream(&file);
    stream << presentTime << " " << ui->codeLabel->text() << " " << ui->IDLabel->text() << " " << "01" << " " << "03" << " " << "9110" << " " << "9120" << " " << "9130" << " " << endl;
    file.close();
}

/* 新的客户端连接 */
void MainWindow::clientConnected()
{
    /* 获取客户端的套接字 */
    tcpSocket = tcpServer->nextPendingConnection();
}





void MainWindow::on_pushButton_printf_clicked()
{

  //  qDebug()<<"click"<<Light<<endl;
    if(Light){
     //   qDebug()<<"night"<<endl;
        NightModeSetting();
    }
    else{
        DaylightModeSetting();
    }

    MainWindow::update();
}


void MainWindow::chageLabelText()
{

    ui->IDLabel->setText(strID);
    ui->stationLabel->setText(strLocation);
    ui->codeLabel->setText(strCodeLoca);
    ui->longitudeLabel->setText(strLongitude);
    ui->latitudeLabel->setText(strLatitude);
    ui->altitudeLabel->setText(strAltitude);

}
