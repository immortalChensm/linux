//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//c++构造函数
//派生类调用基类的构造
using namespace std;

class Person
{
protected:
    char *m_name;
    char *m_sex;
public:
    Person(char *name,char *sex);
};

Person::Person(char *name, char *sex):m_name(name),m_sex(sex) {}

class Student:public Person
{
private:
    int m_score;
public:
    Student(char *name,char *sex,int score);
    void display();
};
//基类构造函数只能在函数头调用
//多继承场景下也是层层调用如：A->B->C c是最后的派生类，它最好调用b的构造，没必要还要在调用a的构造
Student::Student(char *name, char *sex, int score):Person(name,sex),m_score(score) {}
void Student::display() {
    cout<<this->m_name<<this->m_sex<<this->m_score<<endl;
}

int main()
{
    Student stu((char*)"jack",(char*)"female",100);
    stu.display();
    return 0;
}