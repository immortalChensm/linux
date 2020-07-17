//
// Created by Administrator on 2020/7/9.
//

#include <iostream>
#include <string>
#include <thread>
#include <string.h>
using namespace std;

void show(const int& i, char *j)
{
    cout << i << endl;
    cout << j << endl;
    j[0]='k';
    return;
}
class A {
public:
    int _i;
    void show()
    {
        cout << "a::show" << endl;
    }
};
class B {
public:
    int _j;
    int _k;
    void display()
    {
        cout << "b::display" << endl;
    }
};
int main()
{
    //1、传递临时对象作为线程的参数
//    int i = 1;
//    int& k = i;
//    char buf[] = "test";
//
//    thread t(show, i, buf);
//    t.join();
//
//    cout << "main end" << endl;
//    cout << buf << endl;

    char* data = (char*)malloc(100);


    int a = 10;
    char* b = (char*)"test";
    A *obja = new A();
    obja->_i=20;
    B *objb = new B();
    objb->_j=1;
    objb->_k=100;

    //10|test|A|B|
    //4bytes|5bytes|4bytes|8bytes


    memcpy(data,&a,sizeof(a));

    data+=sizeof(a);
    //cout<<*(int*)data<<endl;

    memcpy(data,b,strlen(b));
    data+=strlen(b);

    memcpy(data,obja,sizeof(A));
    data+=sizeof(A);

    memcpy(data,objb,sizeof(B));
   // data+=sizeof(B);

   B *nb = (B*)data;

    cout<<nb->_k<<endl;

    data-=sizeof(A);
    A *na = (A*)data;

    cout<<na->_i<<endl;

    data-=strlen(b);

    char *nc = data;
    cout<<nc<<endl;

    data-=sizeof(int);
    int *j = (int*)data;
    cout<<*j<<endl;
    return 0;
}