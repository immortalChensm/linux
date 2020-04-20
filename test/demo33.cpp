//
// Created by Administrator on 2020/4/20.
//

#include <iostream>
#include <string>
//友元函数
//友元函数  主要用于对象的成员函数间访问私有成员
using namespace std;
class Address;
class Person
{
private:
    char *m_name;
    char *m_address;
    int m_age;
public:
    Person(int age,char *name,char *address);
    void show(Address *address);
};

class Address
{
private:
    char *m_city;
    char *m_prvoince;
public:
    Address(char *city,char *province);
    friend void Person::show(Address *address);//表示Person的show方法能访问本类的所有成员
};
Person::Person(int age, char *name, char *address):m_age(age),m_name(name),m_address(address) {}
void Person::show(Address *address) {
    cout<<address->m_prvoince<<address->m_city<<this->m_address<<this->m_name<<this->m_age<<endl;
   // cout<<address->m_prvoince
}
Address::Address(char *city, char *province):m_city(city),m_prvoince(province) {}
int main()
{
    Person jack(18,(char*)"jack",(char*)"beijing");
    Address address((char*)"bj",(char*)"china");

    jack.show(&address);

    return 0;
}