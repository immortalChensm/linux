//
// Created by Administrator on 2020/5/27.
//

#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
using namespace std;
class student{
public:
    student(char *name,int age):m_name(name),m_age(age){}
    student(const student &obj);
public:
    void show();

public:
    friend ostream &operator<<(ostream &cout,student &stu);
private:
    char *m_name;
    int m_age;
};

template <typename T1,typename T2>
class teacher{
public:
    teacher(T1 *name,T2 salary):m_name(name),m_salary(salary){}

public:
    static teacher<T1,T2>&getSelf(char *name,int salary);
public:
    T1 *getName();
    T2 getSalary();
private:
    T1 *m_name;
    T2 m_salary;
private:
    static teacher<T1,T2> * m_obj;
};
//template <typename T1,typename T2>
//teacher<T1,T2>::teacher(T1 &name, T2 salary) {
//
//}
template <typename T1,typename T2>
teacher<T1,T2> *teacher<T1,T2>::m_obj=NULL;

template <typename T1,typename T2>
teacher<T1,T2>& teacher<T1,T2>::getSelf(char *name,int salary) {
    //return new teacher<T1,T2>((char*)"self",100);
    teacher<char,int> *obj = new teacher<char,int>(name,salary);
    return *obj;
}
template <typename T1,typename T2>
T1 *teacher<T1,T2>::getName() {
    return this->m_name;
}
template <typename T1,typename T2>
T2 teacher<T1,T2>::getSalary() {
    return this->m_salary;
}

#endif //SWOOLE_TEST_STUDENT_H
