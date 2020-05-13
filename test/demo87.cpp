//
// Created by Administrator on 2020/5/13.
//

#include <iostream>
#include <string>
//类模板  类型参数 显示具体化
using namespace std;

template <class T1,class T2> class Point
{
public:
    Point(T1 x,T2 y):m_x(x),m_y(y){};
public:
    T1 getX() const { return m_x;}
    void setX(T1 x){m_x=x;}
    T2 getY() const { return m_y;}
    void setY(T2 y){m_y=y;}
    void display() const;
private:
    T1 m_x;
    T2 m_y;
};

template <class T1,class T2>
void Point<T1,T2>::display() const {
    cout<<"x="<<m_x<<",y="<<m_y<<endl;
}

template <> class Point<char *,char *>
{
public:

    Point(char *x,char *y):m_x(x),m_y(y){}

public:
    char *getX()const{ return m_x;}
    void setX(char *x){m_x=x;}
    char *getY()const{ return m_y;}
    void setY(char *y){m_y=y;}
    void display() const;
    Point &operator+(char *arg){
        //this->m_arg=m_arg + arg;
        cout<<arg<<endl;
        cout<<m_arg<<endl;

        return *this;
    }
private:
    char *m_x;
    char *m_y;
public:
    char *m_arg;
};

void Point<char *,char *>::display() const {
    cout<<"x="<<m_x<<"| y="<<m_y<<endl;
}

int main()
{
    (new Point<int,int>(10,20))->display();
    (new Point<int,char *>(10,(char*)"east 180"))->display();
    (new Point<char *,char *>((char*)"east180",(char*)"north120"))->display();

    Point<char *,char *> p1((char*)"tom",(char*)"jack");
    p1.m_arg=(char*)"jack";
    p1+(char*)"is good student";
    //p1.operator+()
    cout<<p1.m_arg<<endl;
    p1.display();

    return 0;
}