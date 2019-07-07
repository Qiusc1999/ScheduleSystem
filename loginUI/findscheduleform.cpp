#include "findscheduleform.h"
#include "ui_findscheduleform.h"
#include "class.h"
#include "QDateTime"

static std::string userAccount;
static std::string nowfile;

findScheduleForm::findScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findScheduleForm)
{
    ui->setupUi(this);
}

findScheduleForm::~findScheduleForm()
{
    delete ui;
}

int findScheduleForm::getNumberSchedule() {				//获取文件中Schedule对象数量
    int Scount = 0;
    fstream Sfile(nowfile,ios::in|ios::binary);
    if (!Sfile)  {
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



void findScheduleForm::receiveAccount(QString a){       //接收Account,用于文件匹配
    QString s=a;
    userAccount=a.toStdString();
    nowfile=userAccount+"S.dat";
}

void findScheduleForm::receiveShow(){
    std::string nowUser="";
    nowUser="Now Account:"+userAccount;
    ui->label_account->setText(QString::fromStdString(nowUser));
    QString s="Current number of Archives:"+QString::number(getNumberSchedule());
    ui->label_number->setText(s);
    ui->lineEdit_info->setText("");
    ui->textEdit_show->setText("");
    this->show();
}

void findScheduleForm::find(int p){                      //查询

    fstream sfin(nowfile, ios::in | ios::binary);    //判断文件是否存在
    if (!sfin) {
       emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }

    int length = 0;
    length = getNumberSchedule();

    //-----将数据存入数组--------
    if (length == 0) {                                      //没有数据
        QString s ="No Data!";
        ui->textEdit_show->setPlainText(s);
    }
    else{                                                   //有数据
        Schedule* schedule = new Schedule[length];				//申请Schedule动态数组来存储从文件读取的数据
        std::string show="";

        for (int i = 0; i < length; i++) {
            sfin.read((char*)& schedule[i], sizeof(schedule[i]));
        }
    //-----将数据存入数组------

    std::string date;
    std::string time;
    std::string title;
    std::string content;
    std::string location;
    std::string person;
    std::string::size_type findit;

    //show while num < length
    switch (p) {
    case 1:{
        QString qstrinfo=ui->lineEdit_info->text();
        std::string info=qstrinfo.toStdString();
        for(int i=0;i<length;i++){
            date=schedule[i].getDate();
            time=schedule[i].getTime();
            title=schedule[i].getTitle();
            content=schedule[i].getContent();
            location=schedule[i].getLocation();
            person=schedule[i].getPerson();
            findit=title.find(info);
            if(findit==std::string::npos){          //未找到关键字
                QString s;
                s="Not Found";
            }
            else{                                   //找到
                show="title:"+title+'\n'+"time:"+date+' '+time+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person+"\n\n";
                ui->textEdit_show->append(QString::fromStdString(show));
            }
        }
        break;
    }
    case 2: {
       QDate selectdate=ui->calendarWidget->selectedDate();
       QString qstrdate=selectdate.toString("yyyy/MM/dd");
       std::string info=qstrdate.toStdString();
       ui->textEdit_show->setText("date: "+qstrdate+"\n");
       for(int i=0;i<length;i++){
           date=schedule[i].getDate();
           time=schedule[i].getTime();
           title=schedule[i].getTitle();
           content=schedule[i].getContent();
           location=schedule[i].getLocation();
           person=schedule[i].getPerson();
           findit=date.find(info);
           if(findit==std::string::npos){          //未找到关键字
               QString s;
               s="Not Found";
           }
           else{                                   //找到
               show="title:"+title+'\n'+"time:"+date+' '+time+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person+"\n\n";
               ui->textEdit_show->append(QString::fromStdString(show));
           }
       }
       break;
    }
    case 3:{
        QString qstrinfo=ui->lineEdit_info->text();
        std::string info=qstrinfo.toStdString();
        for(int i=0;i<length;i++){
            date=schedule[i].getDate();
            time=schedule[i].getTime();
            title=schedule[i].getTitle();
            content=schedule[i].getContent();
            location=schedule[i].getLocation();
            person=schedule[i].getPerson();
            findit=content.find(info);
            if(findit==std::string::npos){          //未找到关键字
                QString s;
                s="Not Found";
            }
            else{                                   //找到
                show="title:"+title+'\n'+"time:"+date+' '+time+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person+"\n\n";
                ui->textEdit_show->append(QString::fromStdString(show));
            }
        }
        break;
    }
    case 4:{
        QString qstrinfo=ui->lineEdit_info->text();
        std::string info=qstrinfo.toStdString();
        for(int i=0;i<length;i++){
            date=schedule[i].getDate();
            time=schedule[i].getTime();
            title=schedule[i].getTitle();
            content=schedule[i].getContent();
            location=schedule[i].getLocation();
            person=schedule[i].getPerson();
            findit=location.find(info);
            if(findit==std::string::npos){          //未找到关键字
                QString s;
                s="Not Found";
            }
            else{                                   //找到
                show="title:"+title+'\n'+"time:"+date+' '+time+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person+"\n\n";
                ui->textEdit_show->append(QString::fromStdString(show));
            }
        }
        break;
    }
    case 5:{
        QString qstrinfo=ui->lineEdit_info->text();
        std::string info=qstrinfo.toStdString();
        for(int i=0;i<length;i++){
            date=schedule[i].getDate();
            time=schedule[i].getTime();
            title=schedule[i].getTitle();
            content=schedule[i].getContent();
            location=schedule[i].getLocation();
            person=schedule[i].getPerson();
            findit=person.find(info);
            if(findit==std::string::npos){          //未找到关键字
                QString s;
                s="Not Found";
            }
            else{                                   //找到
                show="title:"+title+'\n'+"time:"+date+' '+time+'\n'+"content:"+content+'\n'+"location:"+location+'\n'+"person:"+person+"\n\n";
                ui->textEdit_show->append(QString::fromStdString(show));
            }
        }
        break;
    }
    }

        delete[] schedule;
        sfin.close();
    }

}


void findScheduleForm::on_pushButton_clicked()          //按标题查询
{
    ui->textEdit_show->setText("");
    find(1);
}



void findScheduleForm::on_pushButton_2_clicked()        //按日期查询
{
    ui->textEdit_show->setText("");

    find(2);

}

void findScheduleForm::on_pushButton_3_clicked()    //按内容查询
{
    ui->textEdit_show->setText("");

    find(3);

}

void findScheduleForm::on_pushButton_4_clicked()    //按地点查询
{
    ui->textEdit_show->setText("");

    find(4);

}

void findScheduleForm::on_pushButton_5_clicked()    //按人员查询
{
    ui->textEdit_show->setText("");

    find(5);

}

void findScheduleForm::on_pushButton_6_clicked()    //返回
{
    this->close();
    emit showScheduleMain();
}
