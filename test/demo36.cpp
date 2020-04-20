//
// Created by Administrator on 2020/4/20.
//

#include <iostream>
#include <string>
//类也是一种作用域  类似命名空间
using namespace std;

namespace Test
{
    class A
    {
    private:
        typedef int INT;
        INT i;
    public:
        A(int b);
        void display();
    };
}
Test::A::A(int b):i(b) {}
void Test::A::display() {
    cout<<this->i<<endl;
}

class Person
{
private:
    char *m_name;
    int m_age;
public:
    Person(char *name,int age);
    void show();
};

Person::Person(char *name, int age):m_name(name),m_age(age) {}
void Person::show() {
    std::cout<<this->m_name<<this->m_age<<endl;
}

int main()
{
    Person people((char*)"jack",100);

    people.show();

    Test::A a(1050);
    a.display();

    return 0;
}