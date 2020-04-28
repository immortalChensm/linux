//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    char *m_name;
    char *m_sex;
public:
    Person();
    Person(char *name,char *sex);
};
Person::Person():m_name((char*)"xx"),m_sex((char*)"secret") {
    cout<<"Person::person()\n";
}
Person::Person(char *name, char *sex):m_name(name),m_sex(sex) {}

class Student:public Person
{
private:
    int m_score;
public:
    Student();
    Student(char *name,char *sex,int score);

public:
    void display();
};
Student::Student():m_score(0.0) {
    cout<<"Student::Student()\n";
}
Student::Student(char *name, char *sex, int score):Person(name,sex),m_score(score) {}
void Student::display() {
    cout<<m_name<<m_sex<<m_score<<endl;
}

int main()
{
    Student stu1;
    stu1.display();

    Student stu2((char*)"jack",(char*)"female",100);
    stu2.display();
    return 0;
}