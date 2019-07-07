#ifndef MODIFYSCHEDULEFORM_H
#define MODIFYSCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class modifyScheduleForm;
}

class modifyScheduleForm : public QWidget
{
    Q_OBJECT

public:
    int getNumberSchedule();
    explicit modifyScheduleForm(QWidget *parent = nullptr);
    ~modifyScheduleForm();

private:
    Ui::modifyScheduleForm *ui;

private slots:


    void on_pushButton_modify_clicked();

signals:
    void showNoFile();
};

#endif // MODIFYSCHEDULEFORM_H
