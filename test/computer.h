//
// Created by Administrator on 2020/5/15.
//

#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <iostream>
using namespace std;

template <typename T,typename N>
class computer{
public:
    computer(T name,N m_weight);
public:
    void display();
private:
    T m_name;
    N m_weight;
};
template <typename T,typename N>
computer<T,N>::computer(T name, N m_weight) {
    this->m_name=name;
    this->m_weight=m_weight;
}
template <typename T,typename N>
void computer<T,N>::display() {
    cout<<this->m_name<<this->m_weight<<endl;
}

class router{
public:
    router();
public:
    char *operator[](int i);
private:
    string *routers;
};
router::router() {

    this->routers = new char[10];
}
char* router::operator[](int i) {

}
#endif //SWOOLE_TEST_COMPUTER_H
