#include "usersetting.h"
#include "ui_usersetting.h"
#include "instrumentsetting.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include "keyboard.h"

UserSetting::UserSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSetting)
{
    ui->setupUi(this);

    connect(ui->pushButton_saveandexit,&QPushButton::clicked,[=](){

           emit this->back();

    });

    ui->widget->setStyleSheet("background-color: rgb(74, 44, 252)");
    ui->label->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_2->setStyleSheet("color:rgb(180, 180, 180);");

    QImage image(QString(":/userlogin.png"));
    ui->label_9->setPixmap(QPixmap::fromImage(image));
    ui->label_9->setScaledContents(true);
    ui->label_9->show();

    ui->comboBox_username->setEditable(true);

  //  readUserInfo();
//    ui->comboBox_username->addItem(userInfo[1]);
//    ui->comboBox_username->addItem(userInfo[4]);
//    ui->comboBox_username->addItem(userInfo[7]);
//    ui->comboBox_username->addItem(userInfo[10]);
//    ui->lineEdit_password->setText(userInfo[2]);
//    ui->lineEdit_repassword->setText(userInfo[2]);
//    ui->lineEdit_number->setText(userInfo[3]);

    ui->comboBox_username->installEventFilter(this);
    ui->lineEdit_number->installEventFilter(this);
    ui->lineEdit_password->installEventFilter(this);
    ui->lineEdit_repassword->installEventFilter(this);

}

UserSetting::~UserSetting()
{
    delete ui;
}

bool UserSetting::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->comboBox_username && event->type() == QEvent::MouseButtonPress)
    {
        //KeyBoard *keyBoard = new KeyBoard(0,nullptr,ui->comboBox_username);
        //keyBoard->show();
    }
    else if (watched == ui->lineEdit_number && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_number);
        keyBoard->show();
    }
    else if (watched == ui->lineEdit_password && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_password);
        keyBoard->show();
    }
    else if (watched == ui->lineEdit_repassword && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_repassword);
        keyBoard->show();
    }



    return QWidget::eventFilter(watched, event);
}

void UserSetting::on_pushButton_saveandexit_clicked()
{

}

void UserSetting::on_pushButton_timeseting_clicked()
{
    /*QString str1,str2;

        str1 = "date -s" + ui->lineEdit_ymd->text();
        str2 = "date -s" + ui->lineEdit_hms->text();*/

        /* 类型转换，转换成system可以执行的指令格式 */
        /*char *ch;
        QByteArray ba = str1.toLatin1();
        ch = ba.data();

        char *ch1;
        QByteArray ba1 = str2.toLatin1();
        ch1 = ba1.data();*/

        /* 执行date指令 */
        /*system(ch);
        system(ch1);
        system("hwclock -w");*/

}
void UserSetting::readUserInfo()
{
    std::vector<QString> strs;
    // 读取文件位置
    QFile file("/home/CO2_current_data/userInfo.txt");
    //QFile file("/home/quan/linux/2022.12.2/co2_manage_4/userInfo.txt");
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


    std::vector<QString> para;
    for(int i=0;i<4;i++)
    {
        QStringList List = strs[i].split(':');
        if((List[0]=="#0")||(List[0]=="#1")||(List[0]=="#2")||(List[0]=="#3"))
        {
            userInfo.push_back(List[0]);
            qDebug() <<  "当前用户shi："<<userInfo[0] << endl;
        }
    }
    for(int i=0;i<4;i++)
    {

        QStringList List = strs[i].split(':');
        QStringList myList0 = List[1].split(' ');
        userInfo.push_back(myList0[0]);
        userInfo.push_back(myList0[1]);
        userInfo.push_back(myList0[2]);
    }
}
void UserSetting::saveUserInfo()
{
    std::vector<QString> strs1;
    // 读取文件位置
    QFile file("/home/CO2_current_data/userInfo.txt");
    //QFile file("/home/quan/linux/2022.12.2/co2_manage_4/userInfo.txt");
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
    QString str0,str1,str2;
    str0 = ui->comboBox_username->currentText();
    str1 = ui->lineEdit_password->text();
    str2 = ui->lineEdit_number->text();
    int currentNum = ui->comboBox_username->currentIndex();

    switch(currentNum)
    {
        case 0:
            strs1[0].replace(3, 30, str0+" "+str1+" "+str2);
            userInfo[1]=str0;
            userInfo[2]=str1;
            userInfo[3]=str2;
            break;
        case 1:
            strs1[1].replace(3, 30, str0+" "+str1+" "+str2);
            userInfo[4]=str0;
            userInfo[5]=str1;
            userInfo[6]=str2;
            break;
        case 2:
            strs1[2].replace(3, 30, str0+" "+str1+" "+str2);
            userInfo[7]=str0;
            userInfo[8]=str1;
            userInfo[9]=str2;
            break;
        case 3:
            strs1[3].replace(3, 30, str0+" "+str1+" "+str2);
            userInfo[10]=str0;
            userInfo[11]=str1;
            userInfo[12]=str2;
            break;
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

void UserSetting::on_pushButton_save_clicked()
{
    saveUserInfo();
    ui->comboBox_username->clear();
    ui->comboBox_username->addItem(userInfo[1]);
    ui->comboBox_username->addItem(userInfo[4]);
    ui->comboBox_username->addItem(userInfo[7]);
    ui->comboBox_username->addItem(userInfo[10]);
}

void UserSetting::on_comboBox_username_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            ui->lineEdit_password->setText(userInfo[2]);
            ui->lineEdit_repassword->setText(userInfo[2]);
            ui->lineEdit_number->setText(userInfo[3]);
            break;
        case 1:
            ui->lineEdit_password->setText(userInfo[5]);
            ui->lineEdit_repassword->setText(userInfo[5]);
            ui->lineEdit_number->setText(userInfo[6]);
            break;
        case 2:
            ui->lineEdit_password->setText(userInfo[8]);
            ui->lineEdit_repassword->setText(userInfo[8]);
            ui->lineEdit_number->setText(userInfo[9]);
            break;
        case 3:
            ui->lineEdit_password->setText(userInfo[11]);
            ui->lineEdit_repassword->setText(userInfo[11]);
            ui->lineEdit_number->setText(userInfo[12]);
            break;
    }
}
