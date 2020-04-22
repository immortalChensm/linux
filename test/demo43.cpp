//
// Created by Administrator on 2020/4/22.
//

#include <iostream>
#include <string>

using namespace std;

class People
{
public:
    void setName(char *name);
    void setAge(int age);
    void setHobby(char *hobby);
    char *getHobby();

protected:
    char *m_name;
    int m_age;
private:
    char *m_hobby;
};

void People::setName(char *name) {
    m_name=name;
}
void People::setAge(int age) {
    m_age=age;
}
void People::setHobby(char *hobby) {
    m_hobby = hobby;
}
char *People::getHobby() {
    return this->m_hobby;
}
class Student:public People
{
public:
    void setScore(float score);

protected:
    float m_score;
};

void Student::setScore(float score) {
    m_score = score;
}

class Pupil:public Student
{
public:
    void setRankIng(int ranking);
    void display();

private:
    int m_ranking;
};
void Pupil::setRankIng(int ranking) {
    m_ranking = ranking;
}
void Pupil::display() {
    cout<<m_name<<m_age<<m_score<<m_ranking<<getHobby()<<endl;
}

int main()
{
    Pupil pup;
    pup.setName((char*)"jack");
    pup.setAge(16);
    pup.setScore(85.3f);
    pup.setRankIng(5);
    pup.setHobby((char*)"football");
    pup.display();

    return 0;
}