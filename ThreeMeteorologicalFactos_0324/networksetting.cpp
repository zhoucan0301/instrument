#include "networksetting.h"
#include "ui_networksetting.h"
#include "instrumentsetting.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QProcess>
#include <QButtonGroup>
#include <QTextBlock>
#include "mainwindow.h"
extern QString strIP,strNetworkChild,strGateway;
NetworkSetting::NetworkSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkSetting)
{
    ui->setupUi(this);

    connect(ui->pushButton_saveandexit,&QPushButton::clicked,[=](){

           emit this->networkSettingBack();

    });
    QTextEdit *textEdit=new QTextEdit ;
    QPalette pl=textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit_Info->setPalette(pl);
    ui->textEdit_Info->setStyleSheet("border: none;");
    ui->textEdit_Info->setText("1.网络地址框内为本机的网络地址配置信息，使用IPv4协议格式进行配置，其中格式为：X.X.X.X（X为0~255的整数）；\n2.服务器地址IPv4框内配置的是与本机通信的服务器网络信息，使用IPv4协议格式进行配置，其中地址（左边输入框）格式为X.X.X.X（X为0~255的整数），端口（右边输入框）格式为：Y（Y为0~20000的整数）；\n3.本机地址IPv6框内，配置的是本机的IPv6协议的网络信息，其中地址格式为：xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx（x为十六进制数，均采用小写，其中，若出现:0000:，可以简写为::，下同），长度格式为：y（y为0~100的整数）；\n4.IP协议框内的两个复选框，用来选择本机通信的网络协议。");
    //ui->textEdit_Info->setStyleSheet("background-color: rgb(239, 239, 239)");
    ui->widget->setStyleSheet("background-color: rgb(74, 44, 252)");
    ui->label->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_2->setStyleSheet("color:rgb(180, 180, 180);");

    QTextDocument* doc = ui->textEdit_Info->document();
    QTextCursor textCursor = ui->textEdit_Info->textCursor();
    for(QTextBlock it = doc->begin(); it != doc->end(); it = it.next())
    {
        QTextBlockFormat textBlockFormat = it.blockFormat();
        textBlockFormat.setBottomMargin(10);//设置行间距
        textCursor.setBlockFormat(textBlockFormat);
        ui->textEdit_Info->setTextCursor(textCursor);
    }

    ui->pushButton_del->setStyleSheet("background-color: white");
    ui->pushButton_C->setStyleSheet("background-color: white");
    ui->pushButton_7->setStyleSheet("background-color: white");
    ui->pushButton_8->setStyleSheet("background-color: white");
    ui->pushButton_9->setStyleSheet("background-color: white");
    ui->pushButton_OK->setStyleSheet("background-color: white");
    ui->pushButton_D->setStyleSheet("background-color: white");
    ui->pushButton_4->setStyleSheet("background-color: white");
    ui->pushButton_5->setStyleSheet("background-color: white");
    ui->pushButton_6->setStyleSheet("background-color: white");
    ui->pushButton_A->setStyleSheet("background-color: white");
    ui->pushButton_E->setStyleSheet("background-color: white");
    ui->pushButton_1->setStyleSheet("background-color: white");
    ui->pushButton_2->setStyleSheet("background-color: white");
    ui->pushButton_3->setStyleSheet("background-color: white");
    ui->pushButton_B->setStyleSheet("background-color: white");
    ui->pushButton_F->setStyleSheet("background-color: white");
    ui->pushButton_doubledian->setStyleSheet("background-color: white");
    ui->pushButton_dian->setStyleSheet("background-color: white");
    ui->pushButton_0->setStyleSheet("background-color: white");

    readPara();

    QButtonGroup *m_buGroup = new QButtonGroup(this);//按钮组
    ui->pushButton_A->setFocusPolicy(Qt::NoFocus);//设置按钮无焦点
    ui->pushButton_B->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_C->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_D->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_E->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_F->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_0->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_1->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_9->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_dian->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_doubledian->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_del->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_OK->setFocusPolicy(Qt::NoFocus);

    connect(ui->pushButton_A,&QPushButton::clicked,[=](){buttonNumslot("a");});
    connect(ui->pushButton_B,&QPushButton::clicked,[=](){buttonNumslot("b");});
    connect(ui->pushButton_C,&QPushButton::clicked,[=](){buttonNumslot("c");});
    connect(ui->pushButton_D,&QPushButton::clicked,[=](){buttonNumslot("d");});
    connect(ui->pushButton_E,&QPushButton::clicked,[=](){buttonNumslot("e");});
    connect(ui->pushButton_F,&QPushButton::clicked,[=](){buttonNumslot("f");});
    connect(ui->pushButton_0,&QPushButton::clicked,[=](){buttonNumslot("0");});
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){buttonNumslot("1");});
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){buttonNumslot("2");});
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){buttonNumslot("3");});
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){buttonNumslot("4");});
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){buttonNumslot("5");});
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){buttonNumslot("6");});
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){buttonNumslot("7");});
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){buttonNumslot("8");});
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){buttonNumslot("9");});
    connect(ui->pushButton_dian,&QPushButton::clicked,[=](){buttonNumslot(".");});
    connect(ui->pushButton_doubledian,&QPushButton::clicked,[=](){buttonNumslot(":");});
    connect(ui->pushButton_del,&QPushButton::clicked,[=](){buttonNumslot("del");});
    connect(ui->pushButton_OK,&QPushButton::clicked,[=](){buttonNumslot("ok");});
}
NetworkSetting::~NetworkSetting()
{
    delete ui;
}

void NetworkSetting::on_pushButton_saveandexit_clicked()
{

}

void NetworkSetting::on_pushButton_networkSet_clicked()
{
    if(ui->pushButton_networkSet->text()=="修改/Modify")
    {
        QProcess *process = new QProcess();
        process->start("ifconfig eth0 "+ui->lineEdit_IPAddress->text());
        emit this->setNet();
        ui->pushButton_networkSet->setText("保存/Save");
    }
    else if(ui->pushButton_networkSet->text()=="保存/Save")
    {
        writePara();
        strIP="IP："+ui->lineEdit_IPAddress->text();
        strNetworkChild=ui->lineEdit_subnetMask->text();
        strGateway=ui->lineEdit_gateway->text();

        ui->pushButton_networkSet->setText("修改/Modify");
    }

}
void NetworkSetting::readPara()
{

    std::vector<QString> strs;
    // 读取文件位置
    QFile file("/home/CO2_current_data/parameterInfo.txt");
    //QFile file("/home/quan/linux/2022.12.2/co2_manage_4/parameterInfo.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return ;
    }
    // 文件流
    QTextStream stream(&file);
    // 一行一行的读
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        strs.push_back(line);
    }

    file.close();
    qDebug() <<  "有多少行："<<strs.size() << endl;
    std::vector<QString> para;
    for(int i=0;i<strs.size();i++)
    {

        if(strs[i]=="*Network Settings*")
        {
           para.push_back(strs[i+1]);
           para.push_back(strs[i+2]);
           para.push_back(strs[i+3]);
           para.push_back(strs[i+4]);
           para.push_back(strs[i+5]);
           para.push_back(strs[i+6]);
           para.push_back(strs[i+7]);
           para.push_back(strs[i+8]);
           para.push_back(strs[i+9]);
           para.push_back(strs[i+10]);
           para.push_back(strs[i+11]);
           para.push_back(strs[i+12]);
           para.push_back(strs[i+13]);
           para.push_back(strs[i+14]);
           break;
        }
    }
    //qDebug() <<  "我是："<<strs.size() << endl;
    QStringList myList0 = para[0].split(' ');
    ui->lineEdit_IPAddress->setText(myList0[0]);
    emitUIdata.push_back(myList0[0]);
    QStringList myList1 = para[1].split(' ');
    ui->lineEdit_subnetMask->setText(myList1[0]);
    emitUIdata.push_back(myList1[0]);
    QStringList myList2 = para[2].split(' ');
    ui->lineEdit_gateway->setText(myList2[0]);
    emitUIdata.push_back(myList2[0]);
    QStringList myList3 = para[3].split(' ');
    ui->lineEdit_udpAddress->setText(myList3[0]);
    QStringList myList4 = para[4].split(' ');
    ui->lineEdit_udpPort->setText(myList4[0]);
    QStringList myList5 = para[5].split(' ');
    ui->lineEdit_middlewareIP->setText(myList5[0]);
    QStringList myList6 = para[6].split(' ');
    ui->lineEdit_middlewarePort->setText(myList6[0]);
    QStringList myList7 = para[7].split(' ');
    ui->lineEdit_TimerIP->setText(myList7[0]);
    QStringList myList8 = para[8].split(' ');
    ui->lineEdit_TimerPort->setText(myList8[0]);
    QStringList myList9 = para[9].split(' ');
    ui->lineEdit_IPv6Address->setText(myList9[0]);
    QStringList myList10 = para[10].split(' ');
    ui->lineEdit_IPv4Gateway->setText(myList10[0]);
    QStringList myList11 = para[11].split(' ');
    ui->lineEdit_IPv6length->setText(myList11[0]);

    QStringList myList12 = para[12].split(' ');
    if(myList12[0]=="true")
    {
        ui->checkBox_IPv4->setChecked(1);
    }
    else if(myList12[0]=="false")
    {
        ui->checkBox_IPv4->setChecked(0);
    }
    QStringList myList13 = para[13].split(' ');
    if(myList13[0]=="true")
    {
        ui->checkBox_IPv6->setChecked(1);
    }
    else if(myList13[0]=="false")
    {
        ui->checkBox_IPv6->setChecked(0);
    }

}
void NetworkSetting::writePara()
{
    std::vector<QString> strs1;
    // 读取文件位置
    QFile file("/home/CO2_current_data/parameterInfo.txt");
    //QFile file("/home/quan/linux/2022.12.2/co2_manage_4/parameterInfo.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return ;
    }
    // 文件流
    QTextStream stream(&file);
    // 一行一行的读
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        strs1.push_back(line);
    }
    file.close();
    QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11,str12,str13;
    str0 = ui->lineEdit_IPAddress->text();
    str1 = ui->lineEdit_subnetMask->text();
    str2 = ui->lineEdit_gateway->text();
    str3 = ui->lineEdit_udpAddress->text();
    str4 = ui->lineEdit_udpPort->text();
    str5 = ui->lineEdit_middlewareIP->text();
    str6 = ui->lineEdit_middlewarePort->text();
    str7 = ui->lineEdit_TimerIP->text();
    str8 = ui->lineEdit_TimerPort->text();
    str9 = ui->lineEdit_IPv6Address->text();
    str10 = ui->lineEdit_IPv4Gateway->text();
    str11 = ui->lineEdit_IPv6length->text();

    if(ui->checkBox_IPv4->isChecked()==1)
    {
        str12 = "true";
    }
    else if(ui->checkBox_IPv4->isChecked()==0)
    {
        str12 = "false";
    }
    if(ui->checkBox_IPv6->isChecked()==1)
    {
        str13 = "true";
    }
    else if(ui->checkBox_IPv6->isChecked()==0)
    {
        str13 = "false";
    }

    for(int i=0;i<strs1.size();i++)
    {
        if(strs1[i]=="*Network Settings*")
        {
           std::vector<QString> para;

           para.push_back(strs1[i+1]);
           para.push_back(strs1[i+2]);
           para.push_back(strs1[i+3]);
           para.push_back(strs1[i+4]);
           para.push_back(strs1[i+5]);
           para.push_back(strs1[i+6]);
           para.push_back(strs1[i+7]);
           para.push_back(strs1[i+8]);
           para.push_back(strs1[i+9]);
           para.push_back(strs1[i+10]);
           para.push_back(strs1[i+11]);
           para.push_back(strs1[i+12]);
           para.push_back(strs1[i+13]);
           para.push_back(strs1[i+14]);

           QStringList myList0 = para[0].split(' ');
           QStringList myList1 = para[1].split(' ');
           QStringList myList2 = para[2].split(' ');
           QStringList myList3 = para[3].split(' ');
           QStringList myList4 = para[4].split(' ');
           QStringList myList5 = para[5].split(' ');
           QStringList myList6 = para[6].split(' ');
           QStringList myList7 = para[7].split(' ');
           QStringList myList8 = para[8].split(' ');
           QStringList myList9 = para[9].split(' ');
           QStringList myList10 = para[10].split(' ');
           QStringList myList11 = para[11].split(' ');
           QStringList myList12 = para[12].split(' ');
           QStringList myList13 = para[13].split(' ');

           qDebug() <<  "保存参数："<<strs1[i+1] << endl;
           strs1[i+1].replace(0, myList0[0].size(), str0);
           strs1[i+2].replace(0, myList1[0].size(), str1);
           strs1[i+3].replace(0, myList2[0].size(), str2);
           strs1[i+4].replace(0, myList3[0].size(), str3);
           strs1[i+5].replace(0, myList4[0].size(), str4);
           strs1[i+6].replace(0, myList5[0].size(), str5);
           strs1[i+7].replace(0, myList6[0].size(), str6);
           strs1[i+8].replace(0, myList7[0].size(), str7);
           strs1[i+9].replace(0, myList8[0].size(), str8);
           strs1[i+10].replace(0, myList9[0].size(), str9);
           strs1[i+11].replace(0, myList10[0].size(), str10);
           strs1[i+12].replace(0, myList11[0].size(), str11);
           strs1[i+13].replace(0, myList12[0].size(), str12);
           strs1[i+14].replace(0, myList13[0].size(), str13);

           qDebug() <<  "保存参数："<<strs1[i+4] << endl;
        }
    }
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // 文件流
        QTextStream streams(&file);
        // 输入内容
        for(int i=0;i<strs1.size();i++)
        {
            //strs1[i].replace(strs1[i].size(), 1, " ");
            streams << strs1[i] + "\n";
        }

    }

    file.close();


}
void NetworkSetting::buttonNumslot(QString bn)
{

    if(ui->lineEdit_IPAddress->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_IPAddress->backspace();
        else if(bn=="ok")
              ui->lineEdit_subnetMask->setFocus();
        else
              ui->lineEdit_IPAddress->insert(bn);

    }
    else if(ui->lineEdit_subnetMask->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_subnetMask->backspace();
        else if(bn=="ok")
              ui->lineEdit_gateway->setFocus();
        else
              ui->lineEdit_subnetMask->insert(bn);

    }
    else if(ui->lineEdit_gateway->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_gateway->backspace();
        else if(bn=="ok")
              ui->lineEdit_udpAddress->setFocus();
        else
              ui->lineEdit_gateway->insert(bn);

    }
    else if(ui->lineEdit_udpAddress->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_udpAddress->backspace();
        else if(bn=="ok")
              ui->lineEdit_udpPort->setFocus();
        else
              ui->lineEdit_udpAddress->insert(bn);

    }
    else if(ui->lineEdit_udpPort->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_udpPort->backspace();
        else if(bn=="ok")
              ui->lineEdit_middlewareIP->setFocus();
        else
              ui->lineEdit_udpPort->insert(bn);

    }
    else if(ui->lineEdit_middlewareIP->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_middlewareIP->backspace();
        else if(bn=="ok")
              ui->lineEdit_middlewarePort->setFocus();
        else
              ui->lineEdit_middlewareIP->insert(bn);

    }
    else if(ui->lineEdit_middlewarePort->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_middlewarePort->backspace();
        else if(bn=="ok")
              ui->lineEdit_TimerIP->setFocus();
        else
              ui->lineEdit_middlewarePort->insert(bn);

    }
    else if(ui->lineEdit_TimerIP->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_TimerIP->backspace();
        else if(bn=="ok")
              ui->lineEdit_TimerPort->setFocus();
        else
              ui->lineEdit_TimerIP->insert(bn);

    }
    else if(ui->lineEdit_TimerPort->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_TimerPort->backspace();
        else if(bn=="ok")
              ui->lineEdit_IPv6Address->setFocus();
        else
              ui->lineEdit_TimerPort->insert(bn);

    }
    else if(ui->lineEdit_IPv6Address->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_IPv6Address->backspace();
        else if(bn=="ok")
              ui->lineEdit_IPv4Gateway->setFocus();
        else
              ui->lineEdit_IPv6Address->insert(bn);

    }
    else if(ui->lineEdit_IPv4Gateway->hasFocus())
    {
        if(bn=="del")
              ui->lineEdit_IPv4Gateway->backspace();
        else if(bn=="ok")
              ui->lineEdit_IPv6length->setFocus();
        else
              ui->lineEdit_IPv4Gateway->insert(bn);

    }
    else if(ui->lineEdit_IPv6length->hasFocus())
    {
      if(bn=="del")
            ui->lineEdit_IPv6length->backspace();
      else if(bn=="ok")
            ui->pushButton_networkSet->setFocus();
      else
            ui->lineEdit_IPv6length->insert(bn);

    }
}
void NetworkSetting::on_pushButton_C_clicked()
{

}

void NetworkSetting::on_pushButton_OK_clicked()
{

}
