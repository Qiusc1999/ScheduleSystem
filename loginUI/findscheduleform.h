#ifndef FINDSCHEDULEFORM_H
#define FINDSCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class findScheduleForm;
}

class findScheduleForm : public QWidget
{
    Q_OBJECT

public:
    void find(int p);
    int getNumberSchedule();
    explicit findScheduleForm(QWidget *parent = nullptr);
    ~findScheduleForm();

private slots:
    void receiveAccount(QString a);		//接收Account槽,用于文件匹配

    void receiveShow();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

signals:
    void showNoFile();

    void showScheduleMain();


private:
    Ui::findScheduleForm *ui;
};

#endif // FINDSCHEDULEFORM_H
