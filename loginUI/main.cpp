#include "loginui.h"
#include "registerform.h"
#include "mainForm.h"
#include "warning_noaccountform.h"
#include "warning_pswderrorform.h"
#include "info_registersucessform.h"
#include "scheduleform.h"
#include "newscheduleform.h"
#include "warning_accountNullform.h"
#include "showscheduleform.h"
#include "findscheduleform.h"
#include "loginsuccessform.h"
#include "aboutform.h"

#include <QApplication>

#include<iostream>
#include<string>
#include<vector>
#include<malloc.h>
#include<stdlib.h>
#include<fstream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginUI l;
    RegisterForm r;
    mainForm m;
    Warning_noAccountForm w;
    Warning_PswdErrorForm wp;
    warning_accountNullform wf;
    Info_RegisterSucessForm info_r;
    scheduleForm s0;
    newScheduleForm s1;
    ShowScheduleForm s2;
    findScheduleForm f;
    LoginSuccessForm ls;
    AboutForm af;

    l.show();


    //login&main
    QObject::connect(&l,SIGNAL(showRegister()),&r,SLOT(receiveShow()));
    QObject::connect(&r,SIGNAL(showLogin()),&l,SLOT(receiveShow()));
    QObject::connect(&r,SIGNAL(showLogin()),&l,SLOT(receiveShow()));
    QObject::connect(&l,SIGNAL(showMain()),&ls,SLOT(receiveShow()));
    QObject::connect(&l,SIGNAL(showOK()),&ls,SLOT(receiveShow()));
    QObject::connect(&ls,SIGNAL(showMain()),&m,SLOT(receiveShow()));
    QObject::connect(&m,SIGNAL(showLogin()),&l,SLOT(receiveShow()));
    QObject::connect(&r,SIGNAL(showInfo()),&info_r,SLOT(receiveShow()));
    QObject::connect(&info_r,SIGNAL(showLogin()),&l,SLOT(receiveShow()));
    QObject::connect(&l,SIGNAL(showNoAccount()),&w,SLOT(receiveShow()));
    QObject::connect(&l,SIGNAL(showPswdError()),&wp,SLOT(receiveShow()));
    QObject::connect(&m,SIGNAL(showAbout()),&af,SLOT(receiveShow()));
    QObject::connect(&r,SIGNAL(showError()),&wf,SLOT(receiveShow()));   //用户号或密码为空

    //Account传递
    QObject::connect(&l,SIGNAL(sendAccount(QString)),&m,SLOT(receiveAccount(QString)));
    QObject::connect(&m,SIGNAL(sendAccount(QString)),&s0,SLOT(receiveAccount(QString)));
    QObject::connect(&s0,SIGNAL(sendAccount(QString)),&s1,SLOT(receiveAccount(QString)));
    QObject::connect(&s0,SIGNAL(sendAccount(QString)),&s2,SLOT(receiveAccount(QString)));
    QObject::connect(&s0,SIGNAL(sendAccount(QString)),&f,SLOT(receiveAccount(QString)));


    //schedule
    QObject::connect(&m,SIGNAL(showScheduleMain()),&s0,SLOT(receiveShow()));
    QObject::connect(&s0,SIGNAL(showMain()),&m,SLOT(receiveShow()));
    QObject::connect(&s0,SIGNAL(showNewSchedule()),&s1,SLOT(receiveShow()));
    QObject::connect(&s1,SIGNAL(showScheduleMain()),&s0,SLOT(receiveShow()));
    QObject::connect(&s1,SIGNAL(showNoFile()),&wf,SLOT(receiveShow()));
    QObject::connect(&s0,SIGNAL(showShowSchedule()),&s2,SLOT(receiveShow()));
    QObject::connect(&s2,SIGNAL(showScheduleMain()),&s0,SLOT(receiveShow()));
    QObject::connect(&s2,SIGNAL(showNoFile()),&wf,SLOT(receiveShow()));
    QObject::connect(&s0,SIGNAL(showFind()),&f,SLOT(receiveShow()));
    QObject::connect(&f,SIGNAL(showNoFile()),&wf,SLOT(receiveShow()));
    QObject::connect(&f,SIGNAL(showScheduleMain()),&s0,SLOT(receiveShow()));



    return a.exec();
}

