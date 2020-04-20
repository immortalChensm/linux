//
// Created by Administrator on 2020/4/20.
//

#include <iostream>

using namespace std;

class Address;

class Student
{
public:
    Student(char *name,int age,float score);

public:
    void show(Address *address);

private:
    char *m_name;
    int m_age;
    float m_score;
};

class Address
{
public:
    Address(char *province,char *city,char *district);

public:
    friend class Student;//表示Student类能访问本类的所有成员
private:
    char *m_province;
    char *m_city;
    char *m_district;
};

//构造初始化列表
Student::Student(char *name, int age, float score):m_name(name),m_age(age),m_score(score) {}
//通过友元函数访问Address的私有成员
void Student::show(Address *address) {
    cout<<m_name<<" age is "<<m_age<<",score is "<<m_score<<endl;
    cout<<"province "<<address->m_province<<",city is "<<address->m_city<<address->m_district<<endl;
}

//构造函数初始化列表
Address::Address(char *province, char *city, char *district) {
    m_province = province;
    m_city = city;
    m_district = district;
}

int main()
{
    Student stu((char*)"jack",16,99.45f);
    Address add((char*)"guizhou",(char*)"guiyang",(char*)"guiyangshi");
    stu.show(&add);


    Student *stu1 = new Student((char*)"tom",18,123.4f);
    Address *address = new Address((char*)"guizhou",(char*)"duyun",(char*)"duyunshi");
    stu1->show(address);


    return 0;

}