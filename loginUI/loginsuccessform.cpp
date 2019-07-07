#include "loginsuccessform.h"
#include "ui_loginsuccessform.h"

LoginSuccessForm::LoginSuccessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginSuccessForm)
{
    ui->setupUi(this);
}

LoginSuccessForm::~LoginSuccessForm()
{
    delete ui;
}

void LoginSuccessForm::receiveShow(){
    this->show();
}


void LoginSuccessForm::on_pushButton_clicked()
{
    emit showMain();
    this->close();
}
