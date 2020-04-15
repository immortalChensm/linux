//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    int m_age;
    int m_score;
    char *m_name;
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
    m_name = name;
}
void Person::display() {

}
int main()
{
    //在栈上定义
    Person tom;
    cout<< sizeof(tom)<<endl;
    printf("%#X\n",tom);
    printf("%#X\n",&tom.m_age);
    printf("%#X\n",&tom.m_score);
    printf("%#X\n",&tom.m_name);

    cout<<"********************\n";

    Person *jack = new Person;
   // printf("%d\n", sizeof(jack));
    cout<< sizeof(jack)<<endl;

    printf("%#X\n",jack);
    printf("%#X\n",&jack->m_age);
    printf("%#X\n",&jack->m_score);
    printf("%#X\n",&jack->m_name);


    cout<< sizeof(Person);
    delete jack;

    return 0;
}