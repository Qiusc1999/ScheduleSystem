#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

namespace Ui {
class mainForm;
}

class mainForm : public QWidget
{
    Q_OBJECT

public:
    explicit mainForm(QWidget *parent = nullptr);
    ~mainForm();


private slots:
    void receiveAccount(QString a);  //接收Account,用于文件匹配
    void receiveShow();                 //收到show信号
    void on_pushButton_exit_clicked();  //退出
    void on_pushButton_s_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_about_clicked();

signals:
    void showScheduleMain();
    void sendAccount(QString a);
    void showLogin();
    void showTheme();
    void showAbout();
private:
    Ui::mainForm *ui;
};

#endif // MAINFORM_H
