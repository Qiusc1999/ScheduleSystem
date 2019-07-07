#ifndef SHOWSCHEDULEFORM_H
#define SHOWSCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class ShowScheduleForm;
}

class ShowScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShowScheduleForm(QWidget *parent = nullptr);
    ~ShowScheduleForm();

    int getNumberSchedule();

    void readfile(int p);

    void modifyfile();

    void deletethis();

private slots:
    void receiveAccount(QString a);		//接收Account槽,用于文件匹配

    void receiveShow();

    void on_pushButton_return_clicked();

    void on_pushButton_showNext_clicked();

    void on_pushButton_showBefore_clicked();

    void on_pushButton_modify_clicked();

    void on_pushButton_delete_clicked();

signals:
    void showScheduleMain();

    void showNoFile();

private:
    Ui::ShowScheduleForm *ui;
};

#endif // SHOWSCHEDULEFORM_H
