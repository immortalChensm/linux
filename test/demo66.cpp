//
// Created by Administrator on 2020/5/5.
//

#include <iostream>
#include <string>
//虚函数构成的多态
//1、继承
//2、派生类覆盖虚函数
//3、基类对象调用成员函数【虚函数】
//4、调用的成员函数由基类对象的地址决定【不由数据类型决定】
using namespace std;

class People
{
public:
    People(string name,int age);
public:
    virtual void display();
    virtual void eating();

protected:
    string m_name;
    int m_age;
};

People::People(string name, int age):m_name(name),m_age(age) {}
void People::display() {
    cout<<"class People:"<<m_name<<",age"<<m_age<<endl;
}
void People::eating() {
    cout<<"Class People:i am eating\n";
}
class Student:public People
{
public:
    Student(string name,int age,float score);

public:
    virtual void display();
    virtual void examing();

protected:
    float m_score;
};
Student::Student(string name, int age, float score):People(name,age),m_score(score){}
void Student::display() {
    cout<<"Class Student:"<<m_name<<m_age<<m_score<<endl;
}
void Student::examing() {
    cout<<"Class Student:"<<m_name<<endl;
}

class Senior:public Student
{
public:
    Senior(string name,int age,float score,bool hasJob);

public:
    virtual void display();
    virtual void parting();

private:
    bool m_hasJob;
};
Senior::Senior(string name, int age, float score, bool hasJob):Student(name,age,score),m_hasJob(hasJob) {}
void Senior::display() {
    if (m_hasJob){
        cout<<"Class Senior:"<<m_name<<m_score<<m_age<<endl;
    }else{
        cout<<"Class Senior:"<<m_name<<m_score<<m_age<<"no job"<<endl;
    }
}
void Senior::parting() {
    cout<<"Class Senior:over\n";
}

int main()
{
    /**
     * People{
     * string m_name
     * int m_age
     * }
     * Student{
     * string m_name
     * int m_age
     * int m_score
     * }
     * Senior{
     * string m_name
     * int m_age
     * int m_score
     * bool hasJob
     * }
     */
    People *p = new People("jack",20);
    //display会被编译为全局函数
    //同时隐匿传递this参数,this=p
    //如果类中没有虚函数，则p指向的是People中的类成员函数
    //如果有虚函数且派生类覆盖了，如Student则this=Student类，并不是People类了
    p->display();

    p = new Student("tom",0,99.12);
    p->display();

    p = new Senior("lucy",22,99.55,true);
    p->display();

    return 0;
}