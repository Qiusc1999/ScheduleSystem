#include "newscheduleform.h"
#include "ui_newscheduleform.h"
#include "class.h"
#include "qdatetime.h"


static std::string userAccount;
static std::string nowfile;

newScheduleForm::newScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newScheduleForm)
{
    ui->setupUi(this);

}

newScheduleForm::~newScheduleForm()
{
    delete ui;
}


void newScheduleForm::receiveAccount(QString a){       //接收Account,用于文件匹配
    QString s=a;
    userAccount=a.toStdString();
    nowfile=userAccount+"S.dat";
}

void newScheduleForm::receiveShow(){
    this->show();
    QString number="Current number of Archives:"+QString::number(getNumberSchedule());
    ui->label_number->setText(number);
    QTime time=QTime::currentTime();
    QString qstrhour=time.toString("hh");
    QString qstrminute=time.toString("mm");
    ui->lineEdit__hour->setText(qstrhour);
    ui->lineEdit_minute->setText(qstrminute);
}

void newScheduleForm::on_pushButton_return_clicked()
{
    this->close();
    ui->lineEdit_title->setText("");
    ui->lineEdit_content->setText("");
    ui->lineEdit_location->setText("");
    ui->lineEdit_person->setText("");
    ui->lineEdit__hour->setText("");
    ui->lineEdit_minute->setText("");
    ui->textEdit_show->setText("");
    emit showScheduleMain();
}

void newScheduleForm::on_pushButton_save_clicked()      //保存
{
    QDate date=ui->calendarWidget->selectedDate();
    QString qstrdate=date.toString("yyyy/MM/dd ddd");
    std::string strdate=qstrdate.toStdString();
    QString qstrhour,qstrminute;
    qstrhour=ui->lineEdit__hour->text();
    qstrminute=ui->lineEdit_minute->text();
    std::string strtime="";

    bool correct=(qstrhour.toInt()<=23)&&(qstrhour.toInt()>=0)&&(qstrminute.toInt()>=0)&&(qstrminute.toInt()<=60)
            &&(ui->lineEdit_title->text()!="")&&(ui->lineEdit_content->text()!="")
            &&(ui->lineEdit_location->text()!="")&&(ui->lineEdit_person->text()!="");
    if(correct==true){          //判断输入格式是否正确
        strtime=(qstrhour.toStdString())+":"+(qstrminute.toStdString());
        std::string title=(ui->lineEdit_title->text()).toStdString();
        std::string content=(ui->lineEdit_content->text()).toStdString();
        std::string location=(ui->lineEdit_location->text()).toStdString();
        std::string person=(ui->lineEdit_person->text()).toStdString();

        Schedule s(title, content, location, person, strdate, strtime);

        fstream fout(nowfile, ios::app | ios::binary);     //文件写入
        if (!fout) {
            //emit showNoFile();
            ofstream createfile1(nowfile);
            createfile1.close();
        }
        fout.write((char*) &s, sizeof(s));
        fout.close();

        QTime time=QTime::currentTime();
        QString hour=time.toString("hh");
        QString minute=time.toString("mm");
        ui->lineEdit__hour->setText(qstrhour);
        ui->lineEdit_minute->setText(qstrminute);
        ui->lineEdit_title->setText("");
        ui->lineEdit_content->setText("");
        ui->lineEdit_location->setText("");
        ui->lineEdit_person->setText("");
        ui->textEdit_show->setText("信息已保存！");
        QString number="Current number of Archives:"+QString::number(getNumberSchedule());
        ui->label_number->setText(number);

    }
    else {
        QString error="";
        error="Error: Every lineEdit must not be empty! "
              "Time must be correct! "
              "Hour must be 0 to 24 and minute must be 0 to 60";
        ui->textEdit_show->setText(error);
    }




}

int newScheduleForm::getNumberSchedule() {				//获取文件中Schedule对象数量
    int Scount = 0;
    fstream Sfile(nowfile,ios::in|ios::binary);
    if (!Sfile) {
        //emit showNoFile();
        ofstream createfile1(nowfile);
        createfile1.close();
    }
    Schedule schedule;
    while (Sfile.read((char*)& schedule, sizeof(schedule))) {
        Scount++;
    }
    Sfile.close();
    return Scount;
}


void newScheduleForm::on_pushButton_preview_clicked()   //预览
{
    QDate date=ui->calendarWidget->selectedDate();
    QString qstrdate=date.toString("yyyy/MM/dd ddd");
    std::string strdate=qstrdate.toStdString();
    QString qstrhour,qstrminute;
    qstrhour=ui->lineEdit__hour->text();
    qstrminute=ui->lineEdit_minute->text();
    std::string strtime="";
    strtime=(qstrhour.toStdString())+":"+(qstrminute.toStdString());
    std::string title=(ui->lineEdit_title->text()).toStdString();
    std::string content=(ui->lineEdit_content->text()).toStdString();
    std::string location=(ui->lineEdit_location->text()).toStdString();
    std::string person=(ui->lineEdit_person->text()).toStdString();
    std::string show="";
    show="title:"+title+'\n'+"date:"+strdate+"   "+"time:"+strtime+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person;
    ui->textEdit_show->setPlainText(QString::fromStdString(show));
}

