#include "loginui.h"
#include "ui_loginui.h"
#include "warning_noaccountform.h"
#include "class.h"



static std::string userAccount;

loginUI::loginUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginUI)
{
    ui->setupUi(this);
}

loginUI::~loginUI()
{
    delete ui;
}



void loginUI::on_pushButton_register_clicked()
{
    ui->lineEdit_account->setText("");              //文本框清空
    ui->lineEdit_password->setText("");
    this->hide();
    emit showRegister();
}

void loginUI::receiveShow(){                        //收到要求show信号
    this->show();
}


void loginUI::on_pushButton_exit_clicked()          //点击退出
{
    this->close();
}


void loginUI::on_pushButton_login_clicked()         //点击登录
{

    int existAccount = 0;                      //是否存在账号

    QString account;
    account=ui->lineEdit_account->text();   //获取输入框文本
    std::string a;
    a= account.toStdString();

    QString pswd;
    pswd=ui->lineEdit_password->text();   //获取输入框密码
    std::string p;
    p= pswd.toStdString();

    std::string temp1;
    std::string temp2;
    std::ifstream fin("login.dat", std::ios::in);
    while (std::getline(fin, temp1))
            {
                std::getline(fin, temp2);					//一次读进去两行，分别是用户名和密码
                if (!std::strcmp(a.c_str(), temp1.c_str())) {			//找到用户名，比对密码
                    existAccount = 1;
                    if (!std::strcmp(p.c_str(), temp2.c_str())) {		//密码正确
                        userAccount=a;
                        ui->lineEdit_account->setText("");              //文本框清空
                        ui->lineEdit_password->setText("");
                        this->close();      //隐藏窗口                      
                        emit showOK();    //发射信号
                        QString s;
                        s=QString::fromStdString(userAccount);
                        emit sendAccount(s);
                        return;
                    }
                    else {					//用户名和密码不匹配
                        emit showPswdError(); //显示密码错误窗口
                        return;
                    }
                }  
            }
    if (existAccount==0) {		//没有用户名
        emit showNoAccount();
    }
    fin.close();

}


