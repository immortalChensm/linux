//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int m_age;
    int m_score;
    char *m_name;
public:
    Person(int age,int score,char *name);
    void display();
};
//构造函数初始化列表
Person::Person(int age, int score, char *name):m_age(age),m_score(score),m_name(name) {
    ;
}

void Person::display() {
    cout<<m_name<<" age is "<<m_age<<m_score<<endl;
}

int main()
{
    Person *tom = new Person(100,100,(char*)"tom");
    tom -> display();
    return 0;
}