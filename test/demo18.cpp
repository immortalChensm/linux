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
    Person();//构造函数重载
    Person(int age,int score,char *name);//构造函数
    void setAge(int age);
    void setScore(int score);
    void setName(char *name);
    void show();
    void display();
};

Person::Person() {
    m_score = 0;
    m_age = 0;
    m_name = NULL;
}
Person::Person(int age, int score, char *name) {
    m_name = name;
    m_score = score;
    m_age = age;
}
void Person::setName(char *name) {
    m_name = name;
}
void Person::setScore(int score) {
    m_score = score;
}
void Person::setAge(int age) {
    m_age = age;
}
void Person::show() {
    if (m_score==0||m_name==NULL){
        cout<<"class property of value is empty\n";
    }else{
        cout<<"show method "<<m_name<<m_age<<m_score<<endl;
    }

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

    Person lucy;
    lucy.show();
    Person chen(100,90,(char*)"chen");
    chen.show();

    Person *tang = new Person();
    tang->setAge(100);
    tang->setScore(60);
    tang->setName((char*)"tang");
    tang->show();
    return 0;
}