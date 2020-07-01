//
// Created by Administrator on 2020/6/17.
//

#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class demo
{
public:
    demo(T a){
        _a = a;
    }
    void show()
    {
        cout<<_a<<endl;
    }
public:
    T _a;
    T _b;
    //char data[10240000];//1024k = 10M
    //char *data = new char[1024000];
};


int main()
{
//    demo c;
//    int a = sizeof(demo);
//    int b = sizeof(c);
//
//    cout<<a<<endl;
//    cout<<b<<endl;
//
//    //demo *d[5] = {new demo,new demo,new demo,new demo,new demo};
//    demo *d[10000];
//    for (int i = 0; i <10000 ; ++i) {
//        d[i] = new demo;
//
//    }
//    cout<<sizeof(d)<<endl;
//    cout<<sizeof(d[0])<<endl;
//    cout<<sizeof(d[4])<<endl;

    //demo a(10);
    //a.show();
    demo<int>(10).show();
    return 0;
}