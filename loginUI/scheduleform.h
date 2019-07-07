#ifndef SCHEDULEFORM_H
#define SCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class scheduleForm;
}

class scheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit scheduleForm(QWidget *parent = nullptr);
    ~scheduleForm();

private slots:
    void receiveAccount(QString a);		//接收Account槽,用于文件匹配

    void on_pushButton_return_clicked();
    void receiveShow();

    void on_pushButton_new_clicked();

    void on_pushButton_get_clicked();

    void on_pushButton_getMore_clicked();

signals:
    void showMain();
    void showNewSchedule();
    void showShowSchedule();
    void sendAccount(QString a);
    void showFind();
private:
    Ui::scheduleForm *ui;
};

#endif // SCHEDULEFORM_H
