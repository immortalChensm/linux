//
// Created by Administrator on 2020/4/20.
//

#include <iostream>
#include <string>
//友元函数
using namespace std;

class Person{
private:
    int m_age;
    char *m_name;
    char *m_address;
public:
    Person(int age,char *name,char *address);
    //friend void show(Person *person);
    void show(Person *person);
};

Person::Person(int age, char *name, char *address):m_age(age),m_name(name),m_address(address) {}
void show(Person *person)
{
    cout<<person->m_name<<person->m_address<<person->m_age<<endl;
}
int main()
{
    Person person(10,(char*)"jack",(char*)"shanghai");
    //person.show(person);
    show(&person);

    Person *person1 = new Person(20,(char*)"lucy",(char*)"beijing");
    show(person1);
    return 0;
}