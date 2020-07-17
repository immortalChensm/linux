//
// Created by Administrator on 2020/7/15.
//

#include <iostream>
#include <string.h>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

class A{
public:
    A(){
        cout<<"A()"<<_i<<endl;
    }
    A(int a){
       _i = a;
        cout<<"A(int a)"<<endl;
    }
    A(const A &obj)
    {
        cout<<obj._i<<endl;
        cout<<" A(const A &obj)"<<endl;
        _i = obj._i;
    }
    A(const A &&obj)
    {
        _i = obj._i;
        cout<<" A(const A &&obj)"<<endl;
    }
    ~A()
    {
        cout<<"~A"<<_i<<endl;
    }
public:
    int _i;
};

void talk(A &obj)
{
    ;
}
void say(std::shared_ptr<A> o){

    cout<<o->_i<<endl;
    o->_i = 100;
}

#include <windows.h>
int main()
{

    //A obj;
    //A obj(1);
    //A obj{1};
    //A obj = 1;
    //A obj = 2;
    //A obj1 = obj;
    //talk(obj);
    //std::shared_ptr<A> o(new A(1));
    //say(o);
    //A obj2(std::move(obj));

    //std::thread t(say,o);
    //t.join();

    //std::chrono::milliseconds t(5000);
    //std::this_thread::sleep_for(t);

    //cout<<"over"<<endl;

    vector<std::shared_ptr<A>> data;
    data.push_back(make_shared<A>(1));
    data.push_back(make_shared<A>(2));
    data.push_back(make_shared<A>(3));
    data.push_back(make_shared<A>(4));
    data.push_back(make_shared<A>(5));

    data.erase(data.begin());
    data.clear();
    while (1){

        
    }
    return 0;
}