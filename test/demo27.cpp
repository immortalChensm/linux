//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <windows.h>

using namespace std;

class Person
{
private:
    char *m_userName;
    char *m_address;
    int m_age;
public:
    Person(char *userName,char *address,int age);
    void showUserName();
    void showAddress();
    void showAge();
    void printThis(){
        cout<<this<<endl;
    }
};

Person::Person(char *userName, char *address, int age):m_userName(userName),m_address(address),m_age(age) {
    //strcat(this->m_userName," and jack");
}
/**
 * c++在编译时，会将类的成员函数全部编译为全局函数，同时隐式传递当前对象作为参数，以此来关联类的成员函数和成员变量，这个参数就是this
 */
void Person::showAddress() {
    cout<<"address:"<<this->m_address<<endl;
}
void Person::showAge() {
    cout<<"age:"<<this->m_age<<endl;
}
void Person::showUserName() {
    cout<<"userName:"<<this->m_userName<<endl;
}

int main()
{
//    Person tom((char*)"tom",(char*)"amercian",19);
//
//    tom.showUserName();
//    tom.showAddress();
//    tom.showAge();
//
//    tom.printThis();
//

    Person *jack = new Person((char*)"jack",(char*)"amercian",19);
    jack->showAge();
    jack->showUserName();
    jack->printThis();

    cout<<jack<<endl;

    return 0;
}