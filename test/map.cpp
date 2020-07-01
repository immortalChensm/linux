//
// Created by Administrator on 2020/6/24.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename T>
class A{
public:
    typedef T *iterator;
public:
    A();
    A & A(const A&);
public:
    iterator begin();
};
template <typename T>
A<T>::A() {

}
template <typename T>
A<T>::A(const A &) {
    return *this;
}
template <typename T>
typename A<T>::iterator A<T>::begin() {

}
int main()
{
    std::map<int,string> data;

    data[1] = "china";
    data[2] = "japanese";
    data[3] = "amercian";

    for(auto x:data){
        cout<<x.first<<endl;

        data.erase(2);
    }
    cout<<data.begin()->first<<endl;
    return 0;
}