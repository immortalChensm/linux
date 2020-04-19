//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>
//静态成员变量和静态成员函数
using namespace std;

class Student
{
public:
    Student(char *name,int age,float score);
    void show();

public:
    static int getTotal();
    static float getPoints();

private:
    static int m_total;
    static float m_points;
private:
    char *m_name;
    int m_age;
    float m_score;
};

int Student::m_total=0;
float Student::m_points=0.0;

Student::Student(char *name, int age, float score):m_name(name),m_age(age),m_score(score) {
    m_total++;
    m_points+=score;
}

void Student::show() {
    cout<<m_name<<" 's age is "<<m_age<<",score is "<<this->m_score<<endl;
}

int Student::getTotal() {
    return m_total;
}

float Student::getPoints() {
    return m_points;
}

int main()
{

    (new Student((char*)"tom",10,50.3))->show();
    (new Student((char*)"jack",11,51.3))->show();
    (new Student((char*)"lucy",12,52.3))->show();

    int total = Student::getTotal();
    float points = Student::getPoints();

    cout<<"total:"<<total<<",score is "<<points/total<<endl;
    return 0;
}