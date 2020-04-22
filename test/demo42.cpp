//
// Created by Administrator on 2020/4/22.
//

#include <iostream>
#include <string>
//c++继承
using namespace std;

class Person
{
public:
    //Person(char *name,int age,int sex);
    char *getName();
    int getAge();
    int getSex();
    ~Person(){
        cout<<"person class "<<"is over\n";
    }
private:
    char *m_name;
    int m_age;
    int m_sex;
private:
    void display(){
        cout<<"this is a person class\n";
    }

protected:
    void show(){
        //cout<<"call child show"<<this->getMoney()<<endl;
        cout<<"this is a show func of person class \n";
    }
};

//Person::Person(char *name, int age, int sex):m_name(name),m_age(age),m_sex(sex) {}
char *Person::getName() {
    this->m_name = (char*)"test";
    return this->m_name;
}

int Person::getAge() {
    this->m_age=100;
    return m_age;
}

int Person::getSex() {
    this->m_sex=1;
    return this->m_sex;
}

class Boss: public Person{
public:
    Boss(int money);
    int getMoney();
    ~Boss(){
        cout<<"boss class is over\n";
    }
private:
    int m_money;

};
Boss::Boss(int money):m_money(money) {
}
int Boss::getMoney() {
    //this->display();
    this->show();
    return m_money;
}

int main()
{

//    Boss boss(100000000);
//    cout<<boss.getMoney()<<endl;
//    cout<<boss.getName()<<boss.getAge()<<boss.getSex()<<endl;

    //cout<<boss.display()<<endl;
    //cout<<boss.show()<<endl;

    Boss *boss = new Boss(100);
    //boss->show();
    boss->getMoney();

    delete [] boss;
    return 0;
}