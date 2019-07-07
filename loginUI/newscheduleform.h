#ifndef NEWSCHEDULEFORM_H
#define NEWSCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class newScheduleForm;
}

class newScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit newScheduleForm(QWidget *parent = nullptr);
    int getNumberSchedule();

    ~newScheduleForm();

private slots:
    void receiveAccount(QString a);		//接收Account槽,用于文件匹配
    void receiveShow();
    void on_pushButton_save_clicked();
    void on_pushButton_return_clicked();
    void on_pushButton_preview_clicked();

signals:
    void showScheduleMain();
    void showNoFile();
private:
    Ui::newScheduleForm *ui;
};

#endif // NEWSCHEDULEFORM_H
