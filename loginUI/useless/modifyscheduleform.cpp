#include "modifyscheduleform.h"
#include "ui_modifyscheduleform.h"
#include "threeclasses.h"

static std::string userAccount;
static int theNumOfData=-1;


modifyScheduleForm::modifyScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifyScheduleForm)
{
    ui->setupUi(this);
}

modifyScheduleForm::~modifyScheduleForm()
{
    delete ui;
}


int modifyScheduleForm::getNumberSchedule() {				//获取文件中Schedule对象数量
    int Scount = 0;
    fstream Sfile("Schedule.dat");
    if (!Sfile) {
        emit showNoFile();
        ofstream createfile1("Schedule.dat");
        createfile1.close();
        return 0;
    }
    Schedule schedule;
    while (Sfile.read((char*)& schedule, sizeof(schedule))) {
        Scount++;
    }
    Sfile.close();
    return Scount;
}



void modifyScheduleForm::on_pushButton_modify_clicked()
{

}
