#include "warning_accountNullform.h"
#include "ui_warning_accountNullform.h"

warning_accountNullform::warning_accountNullform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warning_accountNullform)
{
    ui->setupUi(this);
}

warning_accountNullform::~warning_accountNullform()
{
    delete ui;
}

void warning_accountNullform::receiveShow(){
    this->show();
}

void warning_accountNullform::on_pushButton_clicked()
{
    this->close();
}
