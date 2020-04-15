//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int m_a;
    int m_b;
public:
    Person(int b);
    void display();
};

/**
 * Person::Person(int b)
 * {
 *  m_a = mb;
 *  m_b = b;
 * }
 * @param b
 */
Person::Person(int b):m_b(b),m_a(m_b) {}
void Person::display() {
    cout<<m_a<<","<<m_b<<endl;
}

int main()
{
    Person *tom = new Person(10);
    tom->display();
    delete tom;
    return 0;
}