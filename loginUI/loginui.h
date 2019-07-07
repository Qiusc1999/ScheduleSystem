#ifndef LOGINUI_H
#define LOGINUI_H

#include <QMainWindow>
#include<string>


namespace Ui {
class loginUI;
}

class loginUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginUI(QWidget *parent = nullptr);
    ~loginUI();

private slots:
    void on_pushButton_register_clicked();      //注册按钮
    void receiveShow();                         //返回
    void on_pushButton_exit_clicked();          //退出按钮
    void on_pushButton_login_clicked();         //点击登录


signals:                                        //信号
    void sendAccount(QString a);            //发送Account,用于文件匹配
    void showRegister();                        //显示registerUI
    void showMain();                            //显示主页面
    void showPswdError();
    void showNoAccount();
    void showOK();

private:

    Ui::loginUI *ui;

};

#endif // LOGINUI_H
