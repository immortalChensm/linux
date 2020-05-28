//
// Created by Administrator on 2020/5/27.
//

#include "student.h"

#include <iostream>
using namespace std;

void student::show() {
    cout<<this->m_name<<this->m_age<<endl;
}
student::student(const student &obj) {
    this->m_age=obj.m_age;
    this->m_name=obj.m_name;
}
ostream &operator<<(ostream &cout,student &stu){

    cout<<stu.m_name<<stu.m_age;
    return cout;
}