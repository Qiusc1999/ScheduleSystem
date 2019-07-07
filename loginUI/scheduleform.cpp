#include "scheduleform.h"
#include "ui_scheduleform.h"

static std::string userAccount;

scheduleForm::scheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scheduleForm)
{
    ui->setupUi(this);
}

scheduleForm::~scheduleForm()
{
    delete ui;
}

void scheduleForm::receiveAccount(QString a){       //接收Account,用于文件匹配
    QString s=a;
    userAccount=a.toStdString();
}


void scheduleForm::receiveShow(){                        //收到要求show信号
    this->show();
}


void scheduleForm::on_pushButton_return_clicked()
{
    this->hide();
    emit showMain();
}

void scheduleForm::on_pushButton_new_clicked()
{
    this->hide();
    QString s;
    s=QString::fromStdString(userAccount);
    emit sendAccount(s);
    emit showNewSchedule();
}


void scheduleForm::on_pushButton_get_clicked()
{
    this->hide();
    QString s;
    s=QString::fromStdString(userAccount);
    emit sendAccount(s);
    emit showShowSchedule();

}

void scheduleForm::on_pushButton_getMore_clicked()
{
    this->hide();
    QString s;
    s=QString::fromStdString(userAccount);
    emit sendAccount(s);
    emit showFind();
}
