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
    Person(int age,int score,char *name);//构造函数
    void display();
};

Person::Person(int age, int score, char *name) {
    m_name = name;
    m_score = score;
    m_age = age;
}
void Person::display() {
    cout<<m_name<<" 's age is "<<m_age<<" and score is "<<m_score<<endl;
}

int main()
{
    Person *tom = new Person(100,90,(char*)"tom");
    tom->display();
    delete tom;

    Person jack(200,60,(char*)"jack");
    jack.display();
    return 0;
}