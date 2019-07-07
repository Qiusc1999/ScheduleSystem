#include "themeform.h"
#include "ui_themeform.h"
#include "loginui.h"
#include "registerform.h"
#include "mainForm.h"
#include "warning_noaccountform.h"
#include "warning_pswderrorform.h"
#include "info_registersucessform.h"
#include "scheduleform.h"
#include "newscheduleform.h"
#include "warning_filenotfoundform.h"
#include "showscheduleform.h"

themeForm::themeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::themeForm)
{

    ui->setupUi(this);

}

themeForm::~themeForm()
{
    delete ui;
}

void themeForm::receiveShow(){
    this->show();
}


void themeForm::on_pushButton_1_clicked()
{
    loginUI l;
    RegisterForm r;
    mainForm m;
    Warning_noAccountForm w;
    Warning_PswdErrorForm wp;
    warning_fileNotFoundForm wf;
    Info_RegisterSucessForm info_r;
    scheduleForm s0;
    newScheduleForm s1;
    ShowScheduleForm s2;



    l.setStyleSheet("#loginUI{background-image: url(:/1.jpg);}");
    r.setStyleSheet("#RegisterForm{background-image: url(:/1.jpg);}");
    m.setStyleSheet("#mainForm{background-image: url(:/1.jpg);}");
    w.setStyleSheet("#Warning_noAccountForm{background-image: url(:/1.jpg);}");
    wp.setStyleSheet("#Warning_PswdErrorForm{background-image: url(:/1.jpg);}");
    wf.setStyleSheet("#warning_fileNotFoundForm{background-image: url(:/1.jpg);}");
    info_r.setStyleSheet("#Info_RegisterSucessForm{background-image: url(:/1.jpg);}");
    s2.setStyleSheet("#scheduleForm{background-image: url(:/1.jpg);}");
    s1.setStyleSheet("#newScheduleForm{background-image: url(:/1.jpg);}");
    s2.setStyleSheet("#ShowScheduleForm{background-image: url(:/1.jpg);}");


    this->setStyleSheet("#themeForm{"
                    "background-image: url(:/1.jpg);}");

    //this->hide();

}
