//
// Created by Administrator on 2020/5/22.
//

#include <iostream>
#include <string>
//拷贝构造函数
using namespace std;

class Student{
public:
    Student(string name="",int age=0,float score=0.0f);
    Student(const Student &stu);

public:
    void display();

private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score):m_name(name),m_age(age),m_score(score) {}
Student::Student(const Student &stu) {
    this->m_name=stu.m_name;
    this->m_age=stu.m_age;
    this->m_score=stu.m_score;

    cout<<"copy constructor was called."<<endl;
}

void Student::display() {
    cout<<m_name<<" 's age is "<<m_age<<",score is "<<m_score<<endl;
}

int main()
{
    Student stu1((char*)"tom",15,100);
    Student stu2 = stu1;
    Student stu3(stu1);

    stu1.display();
    stu2.display();
    stu3.display();
    return 0;
}