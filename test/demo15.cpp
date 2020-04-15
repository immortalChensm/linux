//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int m_age;
    int m_score;
    //char *m_name;
public:
    void setAge(int age);
    void setScore(int score);
    void setName(char *name);
    void display();
};

void Person::setAge(int age) {
    m_age = age;
}
void Person::setScore(int score) {
    m_score=score;
}
void Person::setName(char *name) {
   // m_name = name;
}
void Person::display() {
   // cout<<m_name<<" 'is age is "<<m_age<<",score is "<<m_score<<endl;
   // cout<<"hello,world"<<endl;
    //cout<<age<<endl;
}
int main()
{
    //在栈上定义
    Person tom;
    cout<< sizeof(tom)<<endl;
    printf("%#Xl\n",tom);
    //tom.setName((char*)"tom");
    //tom.setScore(100);
    //tom.setAge(18);

    //tom.display();


    Person *jack = new Person;
    printf("%d\n", sizeof(jack));
    //jack->setAge(10);
    //jack->setScore(19);
    //jack->setName((char*)"jack");
    //jack->display();



    delete jack;

    return 0;
}