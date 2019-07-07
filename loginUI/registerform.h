#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void receiveShow();             //收到注册信号
    void on_pushButton_back_clicked();  //点击返回
    void on_pushButton_confrim_clicked();   //点击确定

    void on_pushButton_reset_clicked();

signals:
    void showLogin();               //显示loginUI
    void showInfo();
    void showError();

private:
    Ui::RegisterForm *ui;
};

#endif // REGISTERFORM_H
