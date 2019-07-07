#include "warning_noaccountform.h"
#include "ui_warning_noaccountform.h"

Warning_noAccountForm::Warning_noAccountForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warning_noAccountForm)
{
    ui->setupUi(this);
}

Warning_noAccountForm::~Warning_noAccountForm()
{
    delete ui;
}

void Warning_noAccountForm::receiveShow(){
    this->show();
}

void Warning_noAccountForm::on_pushButton_clicked()
{
    this->close();
}
