#include "warning_pswderrorform.h"
#include "ui_warning_pswderrorform.h"

Warning_PswdErrorForm::Warning_PswdErrorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warning_PswdErrorForm)
{
    ui->setupUi(this);
}

Warning_PswdErrorForm::~Warning_PswdErrorForm()
{
    delete ui;
}

void Warning_PswdErrorForm::on_pushButton_clicked() //点击返回loginUI
{
    this->close();
}

void Warning_PswdErrorForm::receiveShow(){
    this->show();
}
