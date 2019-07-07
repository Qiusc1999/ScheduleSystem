#include "showscheduleform.h"
#include "ui_showscheduleform.h"
#include "class.h"
#include "QTextStream"

static std::string userAccount;
static std::string nowfile;

static int theNumOfData=0;

ShowScheduleForm::ShowScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowScheduleForm)
{
    ui->setupUi(this);
}

ShowScheduleForm::~ShowScheduleForm()
{
    delete ui;
}

void ShowScheduleForm::receiveAccount(QString a){       //接收Account,用于文件匹配
    QString s=a;
    userAccount=a.toStdString();
    nowfile=userAccount+"S.dat";
}

void ShowScheduleForm::receiveShow(){
    readfile(0);
    std::string nowUser="";
    nowUser="Now Account:"+userAccount;
    ui->label_6->setText(QString::fromStdString(nowUser));
    QString s="Current number of Archives:"+QString::number(theNumOfData+1)+"/"+QString::number(getNumberSchedule());
    ui->label_notification->setText(s);
    this->show();
}


int ShowScheduleForm::getNumberSchedule() {				//获取文件中Schedule对象数量
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

void ShowScheduleForm::readfile(int p){

    fstream sfin(nowfile, ios::in | ios::binary);    //判断文件是否存在
    if (!sfin) {
       //emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }

    int length = 0;
    length = getNumberSchedule();
    if(theNumOfData==length){                         //位置走到末尾
        theNumOfData--;
    }

    if(int length=getNumberSchedule()!=0){
        QString s="Current number of Archives:"+QString::number(theNumOfData+1)+"/"+QString::number(getNumberSchedule());
        ui->label_notification->setText(s);
    }

    //-----将数据存入数组--------
    if (length == 0) {                                      //没有数据
        QString s ="No Data!";
        ui->label_notification->setText(s);
    }
    else{                                                   //有数据
        Schedule* schedule = new Schedule[length];			//申请Schedule动态数组来存储从文件读取的数据
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

        //show while num < length
        date=schedule[theNumOfData].getDate();
        time=schedule[theNumOfData].getTime();
        title=schedule[theNumOfData].getTitle();
        content=schedule[theNumOfData].getContent();
        location=schedule[theNumOfData].getLocation();
        person=schedule[theNumOfData].getPerson();
        ui->lineEdit_title->setText(QString::fromStdString(title));
        ui->lineEdit_date->setText(QString::fromStdString(date));
        ui->lineEdit_time->setText(QString::fromStdString(time));
        ui->textEdit_content->setText(QString::fromStdString(content));
        ui->lineEdit_location->setText(QString::fromStdString(location));
        ui->lineEdit_person->setText(QString::fromStdString(person));
        //show

        delete[]schedule;
        sfin.close();
    }
}

void ShowScheduleForm::modifyfile(){

    fstream fin(nowfile, ios::in |ios::binary); //读出
    if (!fin) {    //判断文件是否存在
       //emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }

    int length = 0;
    length = getNumberSchedule();

    if (length == 0) {                                      //没有数据
        QString s ="No Data!";
        ui->label_notification->setText(s);
        return;
    }

    //-----将数据存入数组--------
    Schedule* schedule = new Schedule[length];				//申请Schedule动态数组来存储从文件读取的数据

    for (int i = 0; i < length; i++) {
        fin.read((char*)& schedule[i], sizeof(schedule[i]));}

    fin.close();
    //-----将数据存入数组------

    // -------修改-------
    std::string date;
    std::string time;
    std::string title;
    std::string content;
    std::string location;
    std::string person;

    date=ui->lineEdit_date->text().toStdString();
    time=ui->lineEdit_time->text().toStdString();
    title=(ui->lineEdit_title->text()).toStdString();
    content=ui->textEdit_content->document()->toPlainText().toStdString();
    location=(ui->lineEdit_location->text()).toStdString();
    person=(ui->lineEdit_person->text()).toStdString();

    schedule[theNumOfData].setDate(date);
    schedule[theNumOfData].setTime(time);
    schedule[theNumOfData].setTitle(title);
    schedule[theNumOfData].setContent(content);
    schedule[theNumOfData].setlocation(location);
    schedule[theNumOfData].setPerson(person);
    // ---------修改----------


    fstream foutclear(nowfile,ios::out|ios::binary);          //清空原文件数据
    if (!foutclear) {     //判断文件是否存在
       //emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }
    foutclear.close();

    fstream mfout(nowfile,ios::app|ios::binary);          //写入原文件
    for(int i=0;i<length;i++){
        mfout.write((char*)&schedule[i],sizeof(schedule[i]));
    }

    mfout.close();

    delete[]schedule;

}

void ShowScheduleForm::deletethis(){                                            //删除
    fstream fin(nowfile, ios::in |ios::binary); //读出
    if (!fin) {    //判断文件是否存在
       //emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }

    int length = 0;
    length = getNumberSchedule();

    if (length == 0) {                                      //没有数据
        QString s ="No Data!";
        ui->label_notification->setText(s);
        return;
    }

    //-----将数据存入数组--------
    Schedule* schedule = new Schedule[length];				//申请Schedule动态数组来存储从文件读取的数据
    for (int i = 0; i < length; i++) {
        fin.read((char*)& schedule[i], sizeof(schedule[i]));}
    fin.close();
    //-----将数据存入数组------

    //-------将要删除的第k个对象放在数组最后--------
    for(int i=theNumOfData;i<length-1;i++){
        Schedule temp=schedule[i];
        schedule[i]=schedule[i+1];
        schedule[i+1]=temp;
    }
    //-------将要删除的第k个对象放在数组最后--------

    fstream foutclear(nowfile,ios::out|ios::binary);          //清空原文件数据
    if (!foutclear) {     //判断文件是否存在
       //emit showNoFile();
       ofstream createfile1(nowfile);
       createfile1.close();
    }
    foutclear.close();

    fstream mfout(nowfile,ios::app|ios::binary);          //写入原文件
    for(int i=0;i<length-1;i++){
        mfout.write((char*)&schedule[i],sizeof(schedule[i]));
    }
    mfout.close();
    delete[]schedule;
}

void ShowScheduleForm::on_pushButton_showNext_clicked()
{
    int length=getNumberSchedule();
    if(theNumOfData>=length){
        theNumOfData=length-1;
        return;
    }
    else {
        theNumOfData++;     //点击下一个加一
    }
    readfile(0);
}

void ShowScheduleForm::on_pushButton_showBefore_clicked()
{
    if(theNumOfData>0){
        theNumOfData--;     //点击上一个减一
        readfile(1);
    }

}



void ShowScheduleForm::on_pushButton_modify_clicked()           //修改当前记录
{
    modifyfile();
    ui->lineEdit_title->setText("");
    ui->lineEdit_time->setText("");
    ui->textEdit_content->setText("");
    ui->lineEdit_location->setText("");
    ui->lineEdit_person->setText("");
    ui->lineEdit_date->setText("");
    ui->lineEdit_time->setText("");
    readfile(1);
}

void ShowScheduleForm::on_pushButton_return_clicked()
{
    theNumOfData=0;
    ui->lineEdit_title->setText("");
    ui->lineEdit_time->setText("");
    ui->textEdit_content->setText("");
    ui->lineEdit_location->setText("");
    ui->lineEdit_person->setText("");
    ui->lineEdit_date->setText("");
    ui->lineEdit_time->setText("");
    this->close();
    emit showScheduleMain();
}




void ShowScheduleForm::on_pushButton_delete_clicked()
{
    deletethis();
    ui->lineEdit_title->setText("");
    ui->lineEdit_time->setText("");
    ui->textEdit_content->setText("");
    ui->lineEdit_location->setText("");
    ui->lineEdit_person->setText("");
    ui->lineEdit_date->setText("");
    ui->lineEdit_time->setText("");

    readfile(1);
}
