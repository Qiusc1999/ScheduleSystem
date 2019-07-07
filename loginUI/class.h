#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<string>
#include<malloc.h>
#include<stdlib.h>
#include<fstream>
#include<showscheduleform.h>

using namespace std;



class Schedule{						//日程
public:
    Schedule() {

    }
    Schedule(string title, string content, string location,string person, string date, string time) {

        strcpy_s(this->title, title.c_str());
        strcpy_s(this->content, content.c_str());
        strcpy_s(this->location, location.c_str());
        strcpy_s(this->person, person.c_str());
        strcpy_s(this->date, date.c_str());
        strcpy_s(this->time, time.c_str());
    }

    std::string getDate(){
        return date;
    }
    std::string getTime(){
        return time;
    }
    std::string getTitle(){
        return title;
    }

    std::string getContent(){
        return content;
    }
    std::string getLocation(){
        return location;
    }
    std::string getPerson(){
        return person;
    }
    void setTitle(std::string s){
        strcpy_s(this->title, s.c_str());

    }
    void setDate(std::string s){
        strcpy_s(this->date, s.c_str());

    }
    void setTime(std::string s){
        strcpy_s(this->time, s.c_str());

    }
    void setContent(std::string s){
        strcpy_s(this->content, s.c_str());

    }
    void setlocation(std::string s){
        strcpy_s(this->location, s.c_str());

    }
    void setPerson(std::string s){
        strcpy_s(this->person, s.c_str());

    }

private:
    char date[20];
    char time[20];
    char title[1000];
    char content[1000];									//内容
    char location[1000];                                 //地点
    char person[1000];									//人物
};


#endif // CLASS_H

