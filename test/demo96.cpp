//
// Created by Administrator on 2020/5/18.
//

#include <iostream>
#include <string>

using namespace std;

template <class T1,class T2>
class Pair{
private:
    T1 key;
    T2 value;
public:
    //构造函数
    Pair(T1 k,T2 v):key(k),value(v){};
    //operator<() 函数
    bool operator<(const Pair<T1,T2> &p) const;
    //ostream
    //operator<<() 函数
    template <class T3,class T4>
    friend ostream &operator<<(ostream & o,const Pair<T3,T4> &p);
};

template <class T1,class T2>
bool Pair<T1,T2>::operator<(const Pair<T1, T2> &p) const {

    return key<p.key;
}

template <class T3,class T4>
ostream &operator<<(ostream & o,const Pair<T3,T4> &p)
{
    o<<"("<<p.key<<","<<p.value<<")";
    return o;
}

int main()
{
    Pair<string,int> student((char*)"jack",5);
    Pair<int,double> obj(12,3.1415);
    cout<<student<<""<<obj;
    //operator<<(ostream,Pair)

    return 0;
}