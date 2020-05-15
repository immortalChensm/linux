#include <iostream>
#include "func.h"
#include "computer.h"
using namespace std;
struct test{
    unsigned char b:1;
};

struct test a;
//测试函数模板和类模板多文件编程
int main() {


    int n1=10,n2=10;
    Swap(n1,n2);
    cout<<n1<<n2<<endl;

    double f1=23.5,f2=83.24;
    Swap(f1,f2);
    cout<<f1<<f2<<endl;

    int a[] = {59,32,43,87,10,9};
    bobble_sort(a, (sizeof(a)/ sizeof(int)));
    for (int i = 0; i < (sizeof(a)/ sizeof(int)); ++i) {
        cout<<a[i]<<endl;
    }

    char *name=(char*)"super computer";
    int weight=100;
    computer<char*,int> co(name,weight);
    co.display();

    float w=200.34;
    computer<char *,float> co1(name,w);
    co1.display();


    return 0;
}