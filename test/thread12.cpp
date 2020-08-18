//
// Created by Administrator on 2020/8/8.
//

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class A{
public:
    A(int i)
    {
        cout<<"A(int i)"<<endl;
    }
    A(const A&obj)
    {
        cout<<"A(const A&obj)"<<endl;
    }
    ~A()
    {
        cout<<"~A()"<<endl;
    }
};
void test(const A &obj)
{
    int i=50;
    while(i--){
        cout<<"test"<<i<<endl;
    }


}
int main()
{

    thread t(test,A(2));
    int i=6;
    while(i--){
        cout<<"main1"<<i<<endl;
    }

    t.join();

    return 0;
}