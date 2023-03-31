#include "userloginform.h"
#include "ui_userloginform.h"
#include <QDesktopWidget>
#include <QApplication>
#include "instrumentsetting.h"
#include "mainwindow.h"
//#include "faultdiagnosisform.h"
#include "networksetting.h"
#include "usersetting.h"
//#include "saveform.h"
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "keyboard.h"



int curUser=0;



userLoginForm::userLoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userLoginForm)
{
    ui->setupUi(this);

    connect(ui->pushButton_cannel,&QPushButton::clicked,[=](){
           emit this->back();
        ui->lineEdit_passwords1->clear();

    });
   // ui->lineEdit_usernames1->setEnabled(false);
//    faultDiagnosisForm *s1 = new faultDiagnosisForm();
    InstrumentSetting *s2 = new InstrumentSetting();
    NetworkSetting *s3 = new NetworkSetting();
    saveForm *s4 = new saveForm();
   // usersetting *s4 = new usersetting();
   // saveForm *s5 = new saveForm();

    connect(ui->pushButton_ok,&QPushButton::clicked,[=](){
            //当前窗口隐藏

        QString struser = ui->lineEdit_usernames1->text();
        int userCount=0;
        for(int i = 0; i <users.size();i++)
        {
              if(users.at(i).usrname==struser)
              {
                  userCount = i;
                  break;
              }
        }

        QString strpassword = ui->lineEdit_passwords1->text();
        if((struser==users[userCount].usrname)&&(users[userCount].usrpass==strpassword ))
        {
            this->hide();
            switch(UIcount){
            case 1:
                s2->show();
                break;
            case 2:
                s3->show();
                break;
            case 3:
                s4->show();
                break;
            case 4:
                break;
            }
            UIcount=0;
            ui->lineEdit_passwords1->clear();
            changeLabel(userCount);
        }
        else
        {
            QMessageBox::information(this, "提示！", "用户名或密码错误，请检查后重新输入！", QMessageBox::Ok);
            ui->lineEdit_passwords1->clear();
        }

        });
    //监测查询窗口s的回退信号
//    connect(s1,&faultDiagnosisForm::back,[=](){
//        //隐藏查询窗口
//        s1->hide();
//    });
    connect(s2,&InstrumentSetting::instrumentSettingBack,[=](){
        //隐藏查询窗口
        s2->hide();
    });
    connect(s3,&NetworkSetting::networkSettingBack,[=](){
        //隐藏查询窗口
        s3->hide();
    });
    connect(s4,&saveForm::saveformback,[=](){
        //隐藏查询窗口
        s4->hide();
    });
//    connect(s5,&saveForm::back,[=](){
//        //隐藏查询窗口
//        s5->hide();
//    });

    //ui->widget->setStyleSheet("background-color: rgb(217, 217, 217)");
    //ui->userLoginForm->setBackground(QBrush(Qt::WA_TranslucentBackground));

    //setWindowFlags(Qt::Dialog);
    //setWindowModality(Qt::ApplicationModal);
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

    QImage image(QString(":/login.png"));
    ui->label_7->setPixmap(QPixmap::fromImage(image));
    ui->label_7->setScaledContents(true);
    ui->label_7->show();    

    readUserInfo();
    ui->lineEdit_usernames1->installEventFilter(this);
    ui->lineEdit_passwords1->installEventFilter(this);

    keyBoard=new KeyBoard(0,nullptr);
}

userLoginForm::~userLoginForm()
{
    delete ui;
}
bool userLoginForm::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->lineEdit_usernames1 && event->type() == QEvent::MouseButtonPress)
    {
        CallKeyBord(ui->lineEdit_usernames1);
    }
    if (watched == ui->lineEdit_passwords1 && event->type() == QEvent::MouseButtonPress)
    {
        CallKeyBord(ui->lineEdit_passwords1);
    }


    return QWidget::eventFilter(watched, event);
}


void userLoginForm::on_pushButton_ok_clicked()
{

}
void userLoginForm::readUserInfo()
{

    std::vector<QString> strs;
    // 读取文件位置
    QFile file("/home/userInfo.txt");
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
        QRegExp regex("(#?)([0-4]+):([a-zA-Z0-9]+)\\s([a-zA-Z0-9]+)\\s([a-zA-Z0-9]+)");
        if (regex.exactMatch(line )){
        // regex.indexIn(mousposi);
            for(int i=1;i<6;i++){
                qDebug()<<i<<" "<<regex.cap(i)<<endl;
            }
            if(regex.cap(1)=="#"){
                curUser=regex.cap(2).toInt();
        }
        userlog.usrID=regex.cap(2).toInt();
        userlog.usrname=regex.cap(3);
        userlog.usrpass=regex.cap(4);
        userlog.usrLicense=regex.cap(5);

        qDebug()<<"license"<<userlog.usrLicense<<endl;
            users.append(userlog);
        }
        qDebug()<<"curUser"<<curUser<<endl;

    }
    file.close();
    ui->lineEdit_usernames1->setText(users[curUser].usrname);
}

void userLoginForm::on_pushButton_convert_clicked()
{
    curUser=curUser+1;
    if(curUser<=users.size()-1){
        ui->lineEdit_usernames1->setText(users[curUser].usrname);
    }
    else if(curUser>users.size()-1){
        curUser=0;
        ui->lineEdit_usernames1->setText(users[0].usrname);
    }

}

void userLoginForm::changeLabel(int matchline)
{
    std::vector<QString> strs1;
    // 读取文件位置
    QFile file("/home/userInfo.txt");
    //QFile file("/home/quan/linux/2022.12.2/co2_manage_4/userInfo.txt");

    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        qDebug()<<"file open fial"<<endl;

    }

    // 文件流
    QTextStream stream(&file);
    QString ll="hello";
    ll.remove(0,1);
    qDebug()<<ll.length()<<endl;
    ll.insert(0,"1");
    qDebug()<<ll.length()<<endl;
    QVector <QString> strs;
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        strs.append(line);

    }
    qDebug()<<strs<<endl;

    QRegExp regex("(#?)([0-4]+):([a-zA-Z0-9]+)\\s([a-zA-Z0-9]+)\\s([a-zA-Z0-9]+)");
    for(int i=0;i<strs.size();i++){

        if (regex.exactMatch(strs[i])){
            qDebug()<<"begin line is"<<strs[i]<<endl;

            if((regex.cap(1)=="")&&(matchline==regex.cap(2).toInt())){

                strs[i].insert(0,"#");

            }
            else if((regex.cap(1)=="#")&&(matchline!=regex.cap(2).toInt())){
                strs[i].remove(0,1);


            }else if((regex.cap(1)!="")&&(matchline!=regex.cap(2).toInt())){

            }

            qDebug()<<"last line is"<<strs[i]<<endl;
        }

    }

     file.close();

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // 文件流
        QTextStream streams(&file);
        // 输入内容
        for(int i=0;i<strs.size();i++)
        {
            //strs1[i].replace(strs1[i].size(), 1, " ");
            streams << strs[i] + "\n";
        }

    }

    file.close();

}
void userLoginForm::on_userLoginForm_customContextMenuRequested(const QPoint &pos)
{

}


void userLoginForm::CallKeyBord(QLineEdit *curlineEdit){

    //if open,change edit{}

    if(!keyBoard){
        keyBoard = new KeyBoard(0, nullptr);
    }
    keyBoard->setEdit(curlineEdit);
    keyBoard->show();
}
