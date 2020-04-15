//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>
//构造函数初始化列表  动态创建数组
using namespace std;

class Person
{
private:
    int const m_len;
    int *m_address;
public:
    Person(int len);
    void display();
};

//Person::Person(int len):m_len(len) {
//    m_address = new int[len];
//}
Person::Person(int len) {
    m_len = len;//报错，成员类型为const时只能通过构造函数初始化列表实现赋值操作
    m_address = new int[len];
}
void Person::display() {
    for (int i = 0; i <m_len ; ++i) {
        m_address[i] = i;
    }
   // cout<< sizeof(m_address)<<endl;
    for (int j = 0; j <m_len ; ++j) {
        cout<<" i="<<m_address[j]<<endl;
    }
}

int main()
{
    Person *tom = new Person(2);
    tom->display();
    delete tom;
    return 0;
}