//
// Created by Administrator on 2020/5/23.
//

#include <iostream>
#include <string>
//初始化 定义变量或是对象时
//赋值初始化 定义变量或是对象时给值
//赋值 给值操作

//拷贝构造函数的运行时机：初始化赋值时运行

using namespace std;

class Student{
public:
    Student(string name="",int age=0,float score=0.0f);
    Student(const Student &stu);

public:
    Student &operator=(const Student &stu);
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

Student& Student::operator=(const Student &stu) {
    this->m_score=stu.m_score;
    this->m_age=stu.m_age;
    this->m_name=stu.m_name;
    cout<<"operator=() was called."<<endl;
    return *this;
}

void Student::display() {
    cout<<m_name<<m_age<<m_score<<endl;
}

int main()
{
    Student stu1((char*)"jack",1,2);
    Student stu2((char*)"tom",3,4);
    Student stu3((char*)"lucy",5,6);

    Student stu4 = stu1;//赋值初始化  调用拷贝构造函数
    stu4.display();
    stu4 = stu2;//调用operator=()函数

    stu4.display();
    stu4 = stu3;
    stu4.display();

    Student stu5;
    stu5 = stu1;
    stu5=stu2;

    stu5.display();

    Student stu6(stu5);//初始化拷贝

    stu6.display();


    return 0;
}