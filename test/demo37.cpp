//
// Created by Administrator on 2020/4/20.
//

#include <iostream>
#include <string>
//c++的struct 和 class是一样的
//1、struct成员默认是public 而class默认是private
//2、struct 没有模板，而class有
//3、继承也是一样的道理
using namespace std;

struct Person
{
    char *m_name;
    Person(int age,char *name);
    void display();
private:
    int m_age;
};

class Thing
{
    char * m_name;
    int m_size;
public:
    Thing(int size,char *name);
    void display();
};

Thing::Thing(int size, char *name) {
    cout<<"thing init\n";
    m_size = size;
    m_name = name;
}
void Thing::display() {
    cout<<this->m_name<<this->m_size<<endl;

}
Person::Person(int age, char *name):m_age(age),m_name(name) {}
void Person::display() {
    cout<<this->m_name<<this->m_age<<endl;
}

int main()
{
    Person *tom = new Person(200,(char*)"tom");

    tom->display();
    cout<<tom->m_name<<endl;

    delete [] tom;

    Thing thing(100,(char*)"desk");

    return 0;
}