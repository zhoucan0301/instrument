#include "instrumentsetting.h"
#include "ui_instrumentsetting.h"
#include <QDebug>
//#include <QSqlError>
#include <QTimer>
#include <QtCore/QObject>
#include <QFile>
#include <QList>
#include <QTextStream>
#include "keyboard.h"

extern QString strID,strLocation,strCodeLoca,strIP,strNetworkChild,strGateway,strLongitude,strLatitude,strAltitude;
InstrumentSetting::InstrumentSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstrumentSetting)
{
    ui->setupUi(this);

    connect(ui->pushButton_saveandexit,&QPushButton::clicked,[=](){

        emit this->instrumentSettingBack();

    });


        ui->widget->setStyleSheet("background-color: rgb(74, 44, 252)");
        ui->label_2->setStyleSheet("color:rgb(201, 201, 201);");
        ui->label_3->setStyleSheet("color:rgb(180, 180, 180);");

        QImage image(QString(":/others.png"));
        ui->label_10->setPixmap(QPixmap::fromImage(image));
        ui->label_10->setScaledContents(true);
        ui->label_10->setGeometry(576,26,191,191);
        ui->label_10->show();
        ui->checkBox_GPS->setIconSize(QSize(48, 48));
        ui->checkBox_NTP->setIconSize(QSize(48, 48));

        readPara();

        ui->lineEdit_instructID->installEventFilter(this);
        ui->lineEdit_number->installEventFilter(this);
        ui->lineEdit_name->installEventFilter(this);
        ui->lineEdit_longitude->installEventFilter(this);
        ui->lineEdit_dimension->installEventFilter(this);
        ui->lineEdit_altitude->installEventFilter(this);
        ui->lineEdit_date->installEventFilter(this);
        ui->lineEdit_time->installEventFilter(this);


        keyBoard = new KeyBoard(0, nullptr);
        //qRegisterMetaType<Instrumentsetting>("Instrumentsetting");
}

InstrumentSetting::~InstrumentSetting()
{
    delete ui;
}
bool InstrumentSetting::eventFilter(QObject *watched, QEvent *event)
{

    if (watched == ui->lineEdit_instructID && event->type() == QEvent::MouseButtonPress)
    {
      //  KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_instructID);
        CallKeyBord(ui->lineEdit_instructID);
    }
    else if (watched == ui->lineEdit_number && event->type() == QEvent::MouseButtonPress)
    {
       // KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_number);
        CallKeyBord(ui->lineEdit_number);
    }
    else if (watched == ui->lineEdit_name && event->type() == QEvent::MouseButtonPress)
    {
        CallKeyBord(ui->lineEdit_name);
    }
    else if (watched == ui->lineEdit_longitude && event->type() == QEvent::MouseButtonPress)
    {
        //KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_longitude);
        CallKeyBord(ui->lineEdit_longitude);
    }
    else if (watched == ui->lineEdit_dimension && event->type() == QEvent::MouseButtonPress)
    {
        //KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_dimension);
        CallKeyBord(ui->lineEdit_dimension);
    }
    else if (watched == ui->lineEdit_altitude && event->type() == QEvent::MouseButtonPress)
    {
        //KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_altitude);
        CallKeyBord(ui->lineEdit_altitude);
    }
    else if (watched == ui->lineEdit_date && event->type() == QEvent::MouseButtonPress)
    {
        CallKeyBord(ui->lineEdit_date);
    }
    else if (watched == ui->lineEdit_time && event->type() == QEvent::MouseButtonPress)
    {
      //  KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_time);
        CallKeyBord(ui->lineEdit_time);
    }

    return QWidget::eventFilter(watched, event);
}


void InstrumentSetting::CallKeyBord(QLineEdit *curlineEdit){

    //if open,change edit{}

    if(!keyBoard){
        keyBoard = new KeyBoard(0, nullptr);
    }
    keyBoard->setEdit(curlineEdit);
    keyBoard->show();
}

//set info
void InstrumentSetting::on_pushButton_instructInfoSet_clicked()
{
    writePara();

    strID="ID："+ui->lineEdit_instructID->text();
    strLocation=ui->lineEdit_name->text();
    strCodeLoca="("+ui->lineEdit_number->text()+")";
    strLongitude=ui->lineEdit_longitude->text() + ",";
    strLatitude=ui->lineEdit_dimension->text();
    strAltitude=ui->lineEdit_altitude->text()+"m";

}

/*void InstrumentSetting::on_pushButton_locationSet_clicked()
{

}*/
void InstrumentSetting::readPara()
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

        if(strs[i]=="*Terminal Settings*")
        {
           para.push_back(strs[i+1]);
           para.push_back(strs[i+2]);
           para.push_back(strs[i+3]);
           para.push_back(strs[i+4]);
           para.push_back(strs[i+5]);
           para.push_back(strs[i+6]);
           para.push_back(strs[i+7]);
           para.push_back(strs[i+8]);
           break;
        }
    }
    //qDebug() <<  "我是："<<strs.size() << endl;
    QStringList myList0 = para[0].split(' ');
    ui->lineEdit_instructID->setText(myList0[0]);
    emitUIdata.push_back(myList0[0]);
    QStringList myList1 = para[1].split(' ');
    ui->lineEdit_number->setText(myList1[0]);
    emitUIdata.push_back(myList1[0]);
    QStringList myList2 = para[2].split(' ');
    ui->lineEdit_name->setText(myList2[0]);
    emitUIdata.push_back(myList2[0]);
    QStringList myList3 = para[3].split(' ');
    ui->lineEdit_longitude->setText(myList3[0]);
    emitUIdata.push_back(myList3[0]);
    QStringList myList4 = para[4].split(' ');
    ui->lineEdit_dimension->setText(myList4[0]);
    emitUIdata.push_back(myList4[0]);
    QStringList myList5 = para[5].split(' ');
    ui->lineEdit_altitude->setText(myList5[0]);
    emitUIdata.push_back(myList5[0]);

    QStringList myList6 = para[6].split(' ');

    if(myList6[0]=="true")
    {
        ui->checkBox_GPS->setChecked(1);
    }
    else if(myList6[0]=="false")
    {
        ui->checkBox_GPS->setChecked(0);
    }
    QStringList myList7 = para[7].split(' ');
    if(myList7[0]=="true")
    {
        ui->checkBox_NTP->setChecked(1);
    }
    else if(myList7[0]=="false")
    {
        ui->checkBox_NTP->setChecked(0);
    }

}
void InstrumentSetting::writePara()
{
    std::vector<QString> strs1;
    // 读取文件位置
    QFile file("/home/parameterInfo.txt");
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
    QString str0,str1,str2,str3,str4,str5,str6,str7;
    str0 = ui->lineEdit_instructID->text();
    str1 = ui->lineEdit_number->text();
    str2 = ui->lineEdit_name->text();
    str3 = ui->lineEdit_longitude->text();
    str4 = ui->lineEdit_dimension->text();
    str5 = ui->lineEdit_altitude->text();

    if(ui->checkBox_GPS->isChecked()==1)
    {
        str6 = "true";
    }
    else if(ui->checkBox_GPS->isChecked()==0)
    {
        str6 = "false";
    }
    if(ui->checkBox_NTP->isChecked()==1)
    {
        str7 = "true";
    }
    else if(ui->checkBox_NTP->isChecked()==0)
    {
        str7 = "false";
    }

    for(int i=0;i<strs1.size();i++)
    {
        if(strs1[i]=="*Terminal Settings*")
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

           QStringList myList0 = para[0].split(' ');
           QStringList myList1 = para[1].split(' ');
           QStringList myList2 = para[2].split(' ');
           QStringList myList3 = para[3].split(' ');
           QStringList myList4 = para[4].split(' ');
           QStringList myList5 = para[5].split(' ');
           QStringList myList6 = para[6].split(' ');
           QStringList myList7 = para[7].split(' ');

           qDebug() <<  "保存参数："<<strs1[i+1] << endl;
           strs1[i+1].replace(0, myList0[0].size(), str0);
           strs1[i+2].replace(0, myList1[0].size(), str1);
           strs1[i+3].replace(0, myList2[0].size(), str2);
           strs1[i+4].replace(0, myList3[0].size(), str3);
           strs1[i+5].replace(0, myList4[0].size(), str4);
           strs1[i+6].replace(0, myList5[0].size(), str5);
           strs1[i+7].replace(0, myList6[0].size(), str6);
           strs1[i+8].replace(0, myList7[0].size(), str7);

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

void InstrumentSetting::on_pushButton_saveandexit_clicked()
{
 // emit instrumentSettingBack();
}

void InstrumentSetting::on_pushButton_saves_clicked()
{
//    *MainWindow *p = new MainWindow();
//    p->uiUpdateInfo[0]="ID："+ui->lineEdit_instructID->text();
//    p->uiUpdateInfo[1]=ui->lineEdit_name->text() + "("+ui->lineEdit_number->text()+")";
//    p->uiUpdateInfo[5]=ui->lineEdit_longitude->text() + ","+ui->lineEdit_dimension->text();
//    p->uiUpdateInfo[6]=ui->lineEdit_altitude->text()+"m";*/
//    p->updateUI_InstrumentINfo();
//    emit this->setUIinstu();
}
//initialization
void InstrumentSetting::on_pushButton_initialization_clicked()
{
    QString str1,str2;

        str1 = "date -s" + ui->lineEdit_date->text();

        QString originText = ui->lineEdit_time->text();;
        QString searchText = "-";
        QString replaceText = ":";
        QString result = originText.replace(QRegExp(searchText), replaceText);
        str2 = "date -s" + result;

        /* 类型转换，转换成system可以执行的指令格式 */
        char *ch;
        QByteArray ba = str1.toLatin1();
        ch = ba.data();

        char *ch1;
        QByteArray ba1 = str2.toLatin1();
        ch1 = ba1.data();

        /* 执行date指令 */
        system(ch);
        system(ch1);
        system("hwclock -w");

}
