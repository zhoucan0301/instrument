#include "saveform.h"
//#include "saveworker.h"
#include "ui_saveform.h"
#include <QFile>
#include <QList>
#include <QFileDialog>
#include "instrumentsetting.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTextStream>
#include <QDebug>
#include "keyboard.h"

saveForm::saveForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::saveForm)
{
    ui->setupUi(this);
    this->setWindowTitle("保存窗口");
    connect(ui->pushButton_return,&QPushButton::clicked,[=](){
           emit this->saveformback();
    });




    ui->widget->setStyleSheet("background-color: rgb(74, 44, 252)");
    ui->label->setStyleSheet("color:rgb(201, 201, 201);");
    ui->label_2->setStyleSheet("color:rgb(180, 180, 180);");

    QImage image(QString(":/others.png"));
    ui->label_3->setPixmap(QPixmap::fromImage(image));
    ui->label_3->setScaledContents(true);
    ui->label_3->show();


    readPara();

    ui->lineEdit_CO2->installEventFilter(this);
    ui->lineEdit_Tem->installEventFilter(this);
    ui->lineEdit_SuctionPump->installEventFilter(this);

}

saveForm::~saveForm()
{
    delete ui;
}

bool saveForm::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->lineEdit_CO2 && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_CO2);
        keyBoard->show();
    }
    else if (watched == ui->lineEdit_Tem && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_Tem);
        keyBoard->show();
    }
    else if (watched == ui->lineEdit_SuctionPump && event->type() == QEvent::MouseButtonPress)
    {
        KeyBoard *keyBoard = new KeyBoard(0, ui->lineEdit_SuctionPump);
        keyBoard->show();
    }

    return QWidget::eventFilter(watched, event);
}





void saveForm::on_pushButton_scanFileLocation_clicked()
{
    /*QString file_full, file_name,filePath,file_path,file_suffix;
    QFileInfo fileinfo;
    filePath = QCoreApplication::applicationDirPath();
    file_full = QFileDialog::getOpenFileName(this, tr("打开文本文件"),filePath, "文本文件(*.txt);;所有文件(*.*)");
    fileinfo = QFileInfo(file_full);
    //文件名
    file_name = fileinfo.fileName();
    //文件后缀
    file_suffix = fileinfo.suffix();
    //绝对路径
    file_path = fileinfo.absolutePath();


    ui->lineEdit_fileLocation->setText(file_path);*/

}

void saveForm::on_readFile_clicked()
{
    //获取文件路径及名称
        //QString path = QFileDialog::getOpenFileName(this,"打开文件","/home/CO2_current_data/","txt(*.txt) ;;"
         //                                                           "doc(*.doc *.docx)");
        //qDebug() <<  "文件读取" << endl;
        //判断路径是否为空
        //if(path.isEmpty() == false)
        //{
             //指定文件路径
            //QFile file(path);
            //检查文件打开情况
            //bool isOk = file.open(QIODevice::ReadOnly);
            //if(isOk == true)
            //{
                //读文件 内容放到字节组
                //QByteArray array = file.readAll();
                //显示到界面文本框
                //ui->textEdit->setText(array);
            //}
            //文件关闭
            //file.close();

       // }
}
void saveForm::readPara()
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

        if(strs[i]=="*Instrument Parameters*")
        {
           para.push_back(strs[i+1]);
           para.push_back(strs[i+2]);
           para.push_back(strs[i+3]);
           para.push_back(strs[i+4]);
           para.push_back(strs[i+5]);
           break;
        }
    }

    QStringList myList0 = para[0].split(' ');

    if(myList0[0]=="1")
    {
        ui->radioButton_1->setChecked(1);
    }
    else if(myList0[0]=="30")
    {
        ui->radioButton_30->setChecked(1);
    }
    else if(myList0[0]=="60")
    {
        ui->radioButton_60->setChecked(1);
    }
    else if(myList0[0]=="120")
    {
        ui->radioButton_120->setChecked(1);
    }
    QStringList myList1 = para[1].split(' ');
    ui->lineEdit_CO2->setText(myList1[0]);
    QStringList myList2 = para[2].split(' ');
    ui->lineEdit_Tem->setText(myList2[0]);
    QStringList myList3 = para[3].split(' ');
    if(myList3[0]=="true")
    {
        ui->checkBox_SuctionPump->setChecked(1);
    }
    else if(myList3[0]=="false")
    {
        ui->checkBox_SuctionPump->setChecked(0);
    }
    QStringList myList4 = para[4].split(' ');
    ui->lineEdit_SuctionPump->setText(myList4[0]);

}
void saveForm::writePara()
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
    QString str0,str1,str2,str3,str4;
    if(ui->radioButton_1->isChecked()==1)
    {
        str0 = "1";
    }
    else if(ui->radioButton_30->isChecked()==1)
    {
        str0 = "30";
    }
    else if(ui->radioButton_60->isChecked()==1)
    {
        str0 = "60";
    }
    else if(ui->radioButton_120->isChecked()==1)
    {
        str0 = "120";
    }
    str1 = ui->lineEdit_CO2->text();
    str2 = ui->lineEdit_Tem->text();
    if(ui->checkBox_SuctionPump->isChecked()==1)
    {
        str3 = "true";
    }
    else if(ui->checkBox_SuctionPump->isChecked()==0)
    {
        str3 = "false";
    }
    str4 = ui->lineEdit_SuctionPump->text();
    //qDebug() <<  "保存参数："<<str0+str1+str2+str3+str4 << endl;
    for(int i=0;i<strs1.size();i++)
    {
        if(strs1[i]=="*Instrument Parameters*")
        {
           std::vector<QString> para;

           para.push_back(strs1[i+1]);
           para.push_back(strs1[i+2]);
           para.push_back(strs1[i+3]);
           para.push_back(strs1[i+4]);
           para.push_back(strs1[i+5]);
           QStringList myList0 = para[0].split(' ');
           QStringList myList1 = para[1].split(' ');
           QStringList myList2 = para[2].split(' ');
           QStringList myList3 = para[3].split(' ');
           QStringList myList4 = para[4].split(' ');
           qDebug() <<  "保存参数："<<strs1[i+1] << endl;
           strs1[i+1].replace(0, myList0[0].size(), str0);
           strs1[i+2].replace(0, myList1[0].size(), str1);
           strs1[i+3].replace(0, myList2[0].size(), str2);
           strs1[i+4].replace(0, myList3[0].size(), str3);
           strs1[i+5].replace(0, myList4[0].size(), str4);
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
void saveForm::on_saveFile_clicked()
{
    //设置文件保存路径及文件名
    //QString path = QFileDialog::getSaveFileName(this,"保存文件","/home/CO2_current_data/","TXT (*.txt *.doc *.docx)");
    //检查路径是否为空
    //if(path.isEmpty() == false)
    //{
    //设置文件文路径
        //QFile file;
        //file.setFileName(path);
        //判断文件打开
        //bool ret = file.open(QIODevice::WriteOnly);
        //if(ret == true)
        //{
       //讲文本框内容添加至文件
            //QString str =ui->textEdit->toPlainText();
            //file.write(str.toUtf8());
        //}
        //关闭文件
        //file.close();
    //}
}

void saveForm::on_pushButton_saveFileLocation_clicked()
{
    //QString a = ui->lineEdit_fileLocation->text();
    //int e = m_radio_synchronizationtime;
}

void saveForm::on_pushButton_save_clicked()
{
    writePara();
}
