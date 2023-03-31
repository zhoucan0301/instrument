#ifndef SAVEFORM_H
#define SAVEFORM_H
#include <QThread>

#include <QWidget>

namespace Ui {
class saveForm;
}

class saveForm : public QWidget
{
    Q_OBJECT

public:
    explicit saveForm(QWidget *parent = nullptr);
    ~saveForm();


private slots:

    void on_pushButton_scanFileLocation_clicked();

    void on_readFile_clicked();

    void on_saveFile_clicked();

    void on_pushButton_saveFileLocation_clicked();

    void on_pushButton_save_clicked();

signals:
    void saveformback();

private:
    Ui::saveForm *ui;
public:
    void readPara();
    void writePara();
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // SAVEFORM_H
