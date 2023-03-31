#ifndef USERSETTING_H
#define USERSETTING_H

#include <QWidget>

namespace Ui {
class UserSetting;
}

class UserSetting : public QWidget
{
    Q_OBJECT

public:
    explicit UserSetting(QWidget *parent = nullptr);
    ~UserSetting();

private slots:
    void on_pushButton_saveandexit_clicked();

    void on_pushButton_timeseting_clicked();

    void on_pushButton_save_clicked();

    void on_comboBox_username_currentIndexChanged(int index);

private:
    Ui::UserSetting *ui;

signals:
    void back();
public:
    void readUserInfo();
    void saveUserInfo();
    std::vector<QString> userInfo;
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // UserSetting_H
