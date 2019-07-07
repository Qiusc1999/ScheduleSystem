#include "mainform.h"
#include "ui_mainform.h"

static std::string userAccount;


mainForm::mainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainForm)
{
    ui->setupUi(this);
}

mainForm::~mainForm()
{
    delete ui;
}

void mainForm::receiveAccount(QString a){       //接收Account,用于文件匹配
    QString s=a;
    userAccount=a.toStdString();
}
void mainForm::receiveShow(){                  //收到登录信号
    this->show();
    QString welcome="你好 "+QString::fromStdString(userAccount);
    ui->label_welcome->setText(welcome);
}

void mainForm::on_pushButton_logout_clicked(){  //注销
    this->hide();
    emit showLogin();
}


void mainForm::on_pushButton_exit_clicked(){    //退出
    this->close();
}

void mainForm::on_pushButton_s_clicked(){       //功能键
    this->hide();
    QString s;
    s=QString::fromStdString(userAccount);
    emit sendAccount(s);
    emit showScheduleMain();
}

void mainForm::on_pushButton_about_clicked()
{
    emit showAbout();
}
