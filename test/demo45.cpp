//
// Created by Administrator on 2020/4/22.
//

#include <iostream>
#include <string>

//c++继承和通过using修改类成员访问权限
using namespace std;

class People
{
public:
    void show();

protected:
    char *m_name;
    int m_age;
};

void People::show() {
    cout<<m_name<<m_age<<endl;
}

class Student:public People
{
public:
    void learn();

public:
    using People::m_name;
    //using People::m_age;
    float m_score;
private:
    //using People::show;
    using People::m_age;
};

void Student::learn() {
    cout<<"i am "<<m_name<<",age is "<<m_age<<",score is"<<m_score<<endl;
}

int main()
{
    Student stu;
    stu.m_name=(char*)"jack";
    stu.m_age=200;
    stu.m_score=100;
    stu.show();
    stu.learn();

    return 0;
}