#ifndef NETWORKSETTING_H
#define NETWORKSETTING_H

#include <QWidget>


namespace Ui {
class NetworkSetting;
}

class NetworkSetting : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkSetting(QWidget *parent = nullptr);
    ~NetworkSetting();


private slots:
    void on_pushButton_saveandexit_clicked();

    void on_pushButton_networkSet_clicked();

    void on_pushButton_C_clicked();
    void buttonNumslot(QString bn);

    void on_pushButton_OK_clicked();

private:
    Ui::NetworkSetting *ui;
signals:
    void networkSettingBack();
    void setNet();
public:
    void readPara();
    void writePara();
    std::vector<QString> emitUIdata;
};

#endif // NETWORKSETTING_H
