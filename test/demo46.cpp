//
// Created by Administrator on 2020/4/22.
//

#include <iostream>

using namespace std;

class People
{
public:
    void show();

protected:
    char *m_name;
    int m_age;
};
void People::show() {
    cout<<m_name<<m_age<<endl;
}

class Student:public People
{
public:
    Student(char *name,int age,float score);

public:
    void show();//遮蔽？

private:
    float m_score;
};
Student::Student(char *name, int age, float score) {
    m_name = name;
    m_age = age;
    m_score = score;
}

void Student::show() {
    cout<<m_name<<m_age<<m_score<<endl;
}

int main()
{
    Student stu((char*)"jack",15,100.66);
    stu.show();

    stu.People::show();
    return 0;
}