//
// Created by Administrator on 2020/5/27.
//

#include "student.h"
#include <iostream>
using namespace std;

int main()
{
    student stu((char*)"jack",200);
    stu.show();

    cout<<stu<<stu<<endl;

    student stu1(stu);
    stu1.show();

    teacher<char,int> tea((char*)"tom",2000);
    cout<<tea.getName()<<tea.getSalary()<<endl;

    teacher<char,float> *tea1 = new teacher<char,float>((char*)"lucy",2000.54);
    cout<<tea1->getName()<<tea1->getSalary()<<endl;

    teacher<char,int> &obj = teacher<char,int>::getSelf((char*)"father",5000);
    cout<<obj.getName()<<obj.getSalary()<<endl;

    teacher<char,int> &obj1 = teacher<char,int>::getSelf((char*)"mother",10000);
    cout<<obj1.getName()<<obj1.getSalary()<<endl;

    return 0;
}