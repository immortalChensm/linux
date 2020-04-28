//
// Created by Administrator on 2020/4/28.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    char *m_name;
    static char *m_sex;
protected:
    int m_age;
    void show();
    static char *showName();
};

char *Person::m_sex=NULL;
char *Person::showName() {
    return m_sex;
}
void Person::show() {
    cout<<m_name<<m_sex<<m_age<<endl;
}

class Student:public Person
{
public:
    using Person::m_age;
public:
    using Person::show;
    using Person::showName;
    void show(int i);
};
void Student::show(int i) {
    cout<<i<<endl;
}

int main()
{
    Student *jack = new Student;
    jack->m_name=(char*)"jack";
    jack->m_sex=(char*)"female";
    jack->m_age=200;
    jack->show();

    jack->showName();

    jack->show(1000);

    Student::showName();
    return 0;
}

