#include "info_registersucessform.h"
#include "ui_info_registersucessform.h"

Info_RegisterSucessForm::Info_RegisterSucessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info_RegisterSucessForm)
{
    ui->setupUi(this);
}

Info_RegisterSucessForm::~Info_RegisterSucessForm()
{
    delete ui;
}

void Info_RegisterSucessForm::on_pushButton_clicked()
{
    this->close();
    emit showLogin();
}

void Info_RegisterSucessForm::receiveShow(){
    this->show();
}
