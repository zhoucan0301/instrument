#ifndef USERLOGINFORM_H
#define USERLOGINFORM_H

#include <QWidget>
#include "keyboard.h"

namespace Ui {
class userLoginForm;
}

class userLoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit userLoginForm(QWidget *parent = nullptr);
    ~userLoginForm();
    int UIcount=0;
    void readUserInfo();
    std::vector<QString> userInfo;
    void changeLabel(int matchline);
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_convert_clicked();

    void on_userLoginForm_customContextMenuRequested(const QPoint &pos);

private:
    Ui::userLoginForm *ui;
    KeyBoard *keyBoard;
    void CallKeyBord(QLineEdit *curlineEdit);

    struct usrinfo{
        QString usrID;
        QString usrname;
        QString usrpass;
        QString usrLicense;
    };
    struct usrinfo userlog;
    QVector <usrinfo> users;
signals:
    void back();
};

#endif // USERLOGINFORM_H
