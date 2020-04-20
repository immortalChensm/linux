//
// Created by Administrator on 2020/4/20.
//

#include <iostream>
#include <string>
//const成员
using namespace std;

class Person
{

private:
    int m_age;
    char *m_name;
    char *m_address;
public:
    Person(int age,char *name,char *address);
    void show();
    int getAge() const;
    char *getName() const;
    char *getAddress() const;
};

Person::Person(int age, char *name, char *address):m_age(age),m_name(name),m_address(address) {}
void Person::show() {
    cout<<this->m_name<<this->m_address<<this->m_age<<endl;
}
int Person::getAge() const {
    return this->m_age;
}
char *Person::getName() const {
    return this->m_name;
}
char *Person::getAddress() const {
    return this->m_address;
}

int main()
{
    Person tom(18,(char*)"tom",(char*)"china");
    tom.show();
    cout<<tom.getName()<<endl;

    Person *jack = new Person(19,(char*)"jack",(char*)"japanese");
    jack->show();
    cout<<jack->getName()<<endl;

    Person people[2] = {Person(20,(char*)"huahua",(char*)"beijing"),Person(21,(char*)"tang",(char*)"suzhou")};
    for (int i = 0; i <2 ; ++i) {
        people[i].show();
        cout<<people[i].getName()<<endl;
    }

    Person *people1[2] = {new Person(21,(char*)"zhang",(char*)"korean"),new Person(23,(char*)"dadat",(char*)"franch")};
    for (int j = 0; j <2 ; ++j) {
        people1[j]->show();
        cout<<people1[j]->getName()<<endl;
    }
    return 0;
}