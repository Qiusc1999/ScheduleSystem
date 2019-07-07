#include "registerform.h"
#include "ui_registerform.h"
#include "info_registersucessform.h"

#include<iostream>
#include<string>
#include<vector>
#include<malloc.h>
#include<stdlib.h>
#include<fstream>

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::receiveShow(){                   //收到注册信号
    this->show();
}

void RegisterForm::on_pushButton_back_clicked(){        //点击返回按钮
    this->hide();
    emit showLogin();
}


void RegisterForm::on_pushButton_confrim_clicked()      //点击确定按钮
{
    QString account;
    QString pswd;
    std::string a;
    std::string p;

    if(ui->lineEdit_RegisterAccount->text()==""||ui->lineEdit_RegisterPassword->text()==""){
        ui->lineEdit_RegisterAccount->setText("");
        ui->lineEdit_RegisterPassword->setText("");
        emit showError();
    }
    else{
        account=ui->lineEdit_RegisterAccount->text();   //获取输入框文本
        a= account.toStdString();

        pswd=ui->lineEdit_RegisterPassword->text();   //获取输入框密码
        p= pswd.toStdString();
        std::ofstream input("login.dat",std::ios::app );
        std::string name,password;
        input<<a<<std::endl;								//写入用户名
        input<<p<<std::endl;							//写入密码
        input.close();
        ui->lineEdit_RegisterAccount->setText("");
        ui->lineEdit_RegisterPassword->setText("");
        this->hide();
        emit showInfo();
    }


}

void RegisterForm::on_pushButton_reset_clicked()        //重输
{
    ui->lineEdit_RegisterAccount->setText("");
    ui->lineEdit_RegisterPassword->setText("");
}
