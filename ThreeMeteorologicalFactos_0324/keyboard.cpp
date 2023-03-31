#include "keyboard.h"
#include "ui_keyboard.h"
#include "QWidget"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QDesktopWidget>

KeyBoard::KeyBoard(QWidget *parent, QLineEdit *LineEdit) :
    QDialog(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
    move((desktop->width() - this->width())/2, (desktop->height())/2);
    this->setWindowTitle( tr("键盘") );
//    this->setWindowOpacity(0.8);
//    this->setStyleSheet("");

    isCap = false;
    outputStr = "";
    lineEdit = LineEdit;
    pageAll = 0;
    curPage = 0;

    ui->nextBt->setEnabled(false);
    ui->prevBt->setEnabled(false);

    QButtonGroup *numGroup = new QButtonGroup();
    numGroup->addButton(ui->num_0_Bt, 0);
    numGroup->addButton(ui->num_1_Bt, 1);
    numGroup->addButton(ui->num_2_Bt, 2);
    numGroup->addButton(ui->num_3_Bt, 3);
    numGroup->addButton(ui->num_4_Bt, 4);
    numGroup->addButton(ui->num_5_Bt, 5);
    numGroup->addButton(ui->num_6_Bt, 6);
    numGroup->addButton(ui->num_7_Bt, 7);
    numGroup->addButton(ui->num_8_Bt, 8);
    numGroup->addButton(ui->num_9_Bt, 9);
    connect( numGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(slot_numClicked(QAbstractButton*)) );

    QButtonGroup *carGroup = new QButtonGroup();
    carGroup->addButton(ui->q_Bt, 1);
    carGroup->addButton(ui->w_Bt, 2);
    carGroup->addButton(ui->e_Bt, 3);
    carGroup->addButton(ui->r_Bt, 4);
    carGroup->addButton(ui->t_Bt, 5);
    carGroup->addButton(ui->y_Bt, 6);
    carGroup->addButton(ui->u_Bt, 7);
    carGroup->addButton(ui->i_Bt, 8);
    carGroup->addButton(ui->o_Bt, 9);
    carGroup->addButton(ui->p_Bt, 10);
    carGroup->addButton(ui->a_Bt, 11);
    carGroup->addButton(ui->s_Bt, 12);
    carGroup->addButton(ui->d_Bt, 13);
    carGroup->addButton(ui->f_Bt, 14);
    carGroup->addButton(ui->g_Bt, 15);
    carGroup->addButton(ui->h_Bt, 16);
    carGroup->addButton(ui->j_Bt, 17);
    carGroup->addButton(ui->k_Bt, 18);
    carGroup->addButton(ui->l_Bt, 19);
    carGroup->addButton(ui->z_Bt, 20);
    carGroup->addButton(ui->x_Bt, 21);
    carGroup->addButton(ui->c_Bt, 22);
    carGroup->addButton(ui->v_Bt, 23);
    carGroup->addButton(ui->b_Bt, 24);
    carGroup->addButton(ui->n_Bt, 25);
    carGroup->addButton(ui->m_Bt, 26);
    carGroup->addButton(ui->pushButton_shangjuhao, 27);
    carGroup->addButton(ui->pushButton_danshu, 28);
    carGroup->addButton(ui->pushButton_liangpie, 29);
    carGroup->addButton(ui->pushButton_pie, 30);
    connect( carGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(slot_carClicked(QAbstractButton*)) );
    carList = carGroup->buttons();

    QButtonGroup *hanziGroup = new QButtonGroup();
    hanziGroup->addButton(ui->zh_1_Bt, 1);
    hanziGroup->addButton(ui->zh_2_Bt, 2);
    hanziGroup->addButton(ui->zh_3_Bt, 3);
    hanziGroup->addButton(ui->zh_4_Bt, 4);
    hanziGroup->addButton(ui->zh_5_Bt, 5);
    hanziGroup->addButton(ui->zh_6_Bt, 6);
    hanziGroup->addButton(ui->zh_7_Bt, 7);
    hanziGroup->addButton(ui->zh_8_Bt, 8);
    hanziGroup->addButton(ui->zh_9_Bt, 9);
    hanziGroup->addButton(ui->zh_10_Bt, 10);
    connect( hanziGroup, SIGNAL(buttonClicked(QAbstractButton*)),
             this, SLOT(slot_hanziBtClicked(QAbstractButton*)));
    zhList = hanziGroup->buttons();

    ui->widget->setStyleSheet("QWidget{background: black;}");
    ui->num_0_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_1_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_2_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_3_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_4_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_5_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_6_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_7_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_8_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->num_9_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");

    ui->q_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->w_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->e_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->r_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->t_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->y_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->u_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->i_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->o_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->p_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->a_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->s_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->d_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->f_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->g_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->h_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->j_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->k_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->l_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->z_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->x_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->c_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->v_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->b_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->n_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->m_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->pushButton_shangjuhao->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->pushButton_danshu->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->pushButton_liangpie->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->pushButton_pie->setStyleSheet("background-color: rgb(43, 55, 75)");

    ui->delBt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->closeBt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->spaceBt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->prevBt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->nextBt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->caps_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_us_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");

    ui->zh_1_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_2_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_3_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_4_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_5_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_6_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_7_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_8_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_9_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");
    ui->zh_10_Bt->setStyleSheet("background-color: rgb(43, 55, 75)");

    QPalette pe10;
    pe10.setColor(QPalette::ButtonText,QColor(201, 201, 201));
    //ui->pushButton_faultDiagnosis->setPalette(pe10);
    ui->num_0_Bt->setPalette(pe10);
    ui->num_1_Bt->setPalette(pe10);
    ui->num_2_Bt->setPalette(pe10);
    ui->num_3_Bt->setPalette(pe10);
    ui->num_4_Bt->setPalette(pe10);
    ui->num_5_Bt->setPalette(pe10);
    ui->num_6_Bt->setPalette(pe10);
    ui->num_7_Bt->setPalette(pe10);
    ui->num_8_Bt->setPalette(pe10);
    ui->num_9_Bt->setPalette(pe10);

    ui->q_Bt->setPalette(pe10);
    ui->w_Bt->setPalette(pe10);
    ui->e_Bt->setPalette(pe10);
    ui->r_Bt->setPalette(pe10);
    ui->t_Bt->setPalette(pe10);
    ui->y_Bt->setPalette(pe10);
    ui->u_Bt->setPalette(pe10);
    ui->i_Bt->setPalette(pe10);
    ui->o_Bt->setPalette(pe10);
    ui->p_Bt->setPalette(pe10);
    ui->a_Bt->setPalette(pe10);
    ui->s_Bt->setPalette(pe10);
    ui->d_Bt->setPalette(pe10);
    ui->f_Bt->setPalette(pe10);
    ui->g_Bt->setPalette(pe10);
    ui->h_Bt->setPalette(pe10);
    ui->j_Bt->setPalette(pe10);
    ui->k_Bt->setPalette(pe10);
    ui->l_Bt->setPalette(pe10);
    ui->z_Bt->setPalette(pe10);
    ui->x_Bt->setPalette(pe10);
    ui->c_Bt->setPalette(pe10);
    ui->v_Bt->setPalette(pe10);
    ui->b_Bt->setPalette(pe10);
    ui->n_Bt->setPalette(pe10);
    ui->m_Bt->setPalette(pe10);
    ui->pushButton_shangjuhao->setPalette(pe10);
    ui->pushButton_danshu->setPalette(pe10);
    ui->pushButton_liangpie->setPalette(pe10);
    ui->pushButton_pie->setPalette(pe10);

    ui->delBt->setPalette(pe10);
    ui->closeBt->setPalette(pe10);
    ui->spaceBt->setPalette(pe10);
    ui->prevBt->setPalette(pe10);
    ui->nextBt->setPalette(pe10);
    ui->caps_Bt->setPalette(pe10);
    ui->zh_us_Bt->setPalette(pe10);


    ui->zh_1_Bt->setPalette(pe10);
    ui->zh_2_Bt->setPalette(pe10);
    ui->zh_3_Bt->setPalette(pe10);
    ui->zh_4_Bt->setPalette(pe10);
    ui->zh_5_Bt->setPalette(pe10);
    ui->zh_6_Bt->setPalette(pe10);
    ui->zh_7_Bt->setPalette(pe10);
    ui->zh_8_Bt->setPalette(pe10);
    ui->zh_9_Bt->setPalette(pe10);
    ui->zh_10_Bt->setPalette(pe10);
    ui->langLb->setStyleSheet("color:rgb(201, 201, 201);");
    ui->showLb->setStyleSheet("color:rgb(0, 255, 255);");

    // 加载字库
  //  loadziku();

}

KeyBoard::~KeyBoard()
{
    delete ui;
}

/* 加载字库 */
void KeyBoard::loadziku()
{
    // 加载字库文件
    QFile zikuFile("/opt/zikui.txt");
    if ( !zikuFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QMessageBox::information(this, "键盘字库",
                                 "加载字库文件错误，中文输入不可用！", QMessageBox::Ok);
        ui->zh_us_Bt->setEnabled(false);
        return;
    }

    QString zikuAll;

    while (true)
    {
        char buf[1024];
        qint64 len = zikuFile.readLine(buf, sizeof(buf));
        if (len <= 0)
        {
            break;
        }
        QString str = QString::fromUtf8(buf);
        zikuAll += str;
    }

    zikuList = zikuAll.split("\n");      //用QString的split函数将字库文件划分成一段一段，每个拼音对应一段字库
    zikuFile.close();
}

/* 查找中文 */
QString KeyBoard::findChinese(QString PinYin)
{
    QStringList lst;
    QString Line;
    QString returnChinese;

    for(int i = 0; i < zikuList.count(); i++)//m_srf.count()QStringList有多少段
    {
        Line = zikuList.at(i);
        if (Line.isEmpty() || PinYin.isEmpty()) continue;

        lst = Line.split(",");
        if (QString::compare(lst.at(0), PinYin, Qt::CaseInsensitive) == 0)
        {
            returnChinese =  lst.at(1);
        }
    }

    // 字符串分割成10个10个一组
    pageList.clear();
    int len = returnChinese.length();
    if (len > 0)
    {
        pageAll = len % 10 == 0 ? len/10 : (len/10) + 1;
        QString str;
        for (int i = 1; i <= len; i++)
        {
            str += returnChinese.at(i-1);
            if (i % 10 == 0 && i != 0)
            {
                pageList << str;
                str = "";
            }
        }

        if (len % 10 != 0)
        {
            pageList << returnChinese.right(len % 10);
        }
    }//if

    return returnChinese;
}

/* 汉字按钮的设置 */
void KeyBoard::setHanziBt()
{

    for (int i = 0; i < 10; i++)
    {
        zhList.at(i)->setText("");
    }

    QString PinYin = ui->showLb->text();
    QString ChineseStr = findChinese(PinYin);

    ui->nextBt->setEnabled(false);
    ui->prevBt->setEnabled(false);

    if (ChineseStr != "")
    {
        int ChineseStrCount = ChineseStr.length();
        // 10字以内汉字个数
        if (ChineseStrCount <= 10)
        {
            for (int i = 0; i < ChineseStrCount; i++)
            {
                ((QPushButton *)zhList.at(i))->setText(ChineseStr.at(i));
            }
            return;
        }

        // 大于十字
        for (int i = 0; i < 10; i++)
        {
            ((QPushButton *)zhList.at(i))->setText(ChineseStr.at(i));
        }

        ui->nextBt->setEnabled(true);
        ui->prevBt->setEnabled(true);

    }//if
}

/* 大小写转换 */
void KeyBoard::on_caps_Bt_clicked()
{
    if (isCap == false) // 小写状态
    {
        for (int i = 0; i < carList.size(); i++)
        {
            QString upper = carList.at(i)->text().toUpper();
            carList.at(i)->setText(upper);
        }
        isCap = true;
        return;
    }
    else // 大写状态
    {
        for (int i = 0; i < carList.size(); i++)
        {
            QString lower = carList.at(i)->text().toLower();
            carList.at(i)->setText(lower);
        }
        isCap = false;
        return;
    }
}


/* 数字键盘点击 */
void KeyBoard::slot_numClicked(QAbstractButton *bt)
{
    QPushButton *tmpBt = (QPushButton *)bt;
    QString str = lineEdit->text();
    str.append(tmpBt->text());
    lineEdit->setText(str);
}

/* 字母键点击 */
void KeyBoard::slot_carClicked(QAbstractButton *bt)
{
    QPushButton *tmp = (QPushButton *)bt;
    QString str_1 = ui->showLb->text();
    str_1.append(tmp->text());
    ui->showLb->setText(str_1);

    if (ui->langLb->text() == "英文")
    {
        QString str_2 = lineEdit->text();
        str_2.append(tmp->text());
        lineEdit->setText(str_2);
    }
    else
    {
        setHanziBt();
    }
}

/* 十个中文按钮点击 */
void KeyBoard::slot_hanziBtClicked(QAbstractButton *bt)
{
    QPushButton *tmp = (QPushButton *)bt;
    QString str = lineEdit->text();
    str.append(tmp->text());
    lineEdit->setText(str);
    ui->showLb->setText("");
    for (int i = 0; i < 10; i++)
    {
        zhList.at(i)->setText("");
    }

    ui->nextBt->setEnabled(false);
    ui->prevBt->setEnabled(false);
}

/* 中英切换按钮 */
void KeyBoard::on_zh_us_Bt_clicked()
{
    if (ui->langLb->text() == "英文")
    {
        ui->langLb->setText("中文");
        ui->showLb->setText("");
    }
    else
    {
        ui->langLb->setText("英文");
        ui->showLb->setText("");
    }
}

/* 退格键 */
void KeyBoard::on_delBt_clicked()
{
    QString tmp = ui->showLb->text();
    ui->showLb->setText(tmp.left(tmp.length() - 1));

    if (ui->langLb->text() == "英文")
    {
        QString str = lineEdit->text();
        lineEdit->setText(str.left(str.length() - 1));
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            zhList.at(i)->setText("");
        }
        setHanziBt();
        if (ui->showLb->text() == "") // 中文模式下，showLb中删除完毕才去删除LineEdit里的文字
        {
            QString str = lineEdit->text();
            lineEdit->setText(str.left(str.length() - 1));
        }
    }
}

/* 翻页按键 */
void KeyBoard::on_nextBt_clicked()
{
    curPage++;

    if (curPage > pageAll)
    {
        curPage = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        zhList.at(i)->setText("");
    }

    QString str = pageList.at(curPage-1);
    qDebug() << str;
    for (int i = 0; i < str.length(); i++)
    {
        zhList.at(i)->setText(str.at(i));
    }
}

void KeyBoard::on_prevBt_clicked()
{
    curPage--;
    if (curPage == 0)
    {
        curPage = pageAll;
    }

    for (int i = 0; i < 10; i++)
    {
        zhList.at(i)->setText("");
    }

    QString str = pageList.at(curPage-1);
    for (int i = 0; i < str.length(); i++)
    {
        zhList.at(i)->setText(str.at(i));
    }
}

void KeyBoard::on_closeBt_clicked()
{
    this->close();
}

void KeyBoard::setEdit(QLineEdit*&newEdit)
{
    lineEdit=newEdit;
    ui->showLb->setText("");
}
void KeyBoard::getEdit(){


   qDebug()<<"lineedit is "<<lineEdit<<endl;
}
