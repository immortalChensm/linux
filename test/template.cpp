//
// Created by Administrator on 2020/7/1.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

template<typename T,int age=100>
class A{
    typedef T * jack;
public:
    A(T a){
        cout<<a<<endl;
    }
    jack getData();
};

template class A<char>;

template<typename T>
using myA = A<T>;

template<typename T,int age>
typename A<T,age>::jack A<T,age>::getData() {
    T d=100;
    jack data=&d;
    return data;
}

template<>
class A<int>
{
public:
    A(int a){
        cout<<"int:"<<a<<endl;
    }
};

template<typename T>
class A<T &>
{
public:
    A(T a){
        cout<<"T &:"<<a<<endl;
    }
};
template<typename T>
class A<T *>
{
public:
    A(T a){
        cout<<"T *:"<<a<<endl;
    }
};

namespace  test1{

    template<
            typename T,
            template<class> class Container,
            template<typename,typename > typename Container2
            >
            class Datas{
            public:
                Datas()
                {
                    for(int i=0;i<10;i++){
                        obj.push_back(i);

                        obj2[i] = i*10;
                    }


                }
                Container<T> getData()
                {
                    return obj;
                }
                Container<T> obj;

                Container2<int,T> obj2;
            };
    template<typename T> using myVec = std::vector<T,allocator<T>>;
    template<class D,typename F>
    using myMap = std::map<D,F>;
    void func()
    {

        Datas<int,myVec,myMap> obj;

        myVec<int> obj1 = obj.getData();
        for(auto x:obj1){
            cout<<x<<endl;
        }
        cout<<"*******************"<<endl;
        for(auto iter:obj.obj2){
            cout<<iter.first<<"="<<iter.second<<endl;
        }
    }
}

namespace test2 {

    template<typename ...U>
    class Data{

    };

    template<typename T, typename ...U>
    class Data<T, U...>
    {
    public:
        Data(T a,U...args):_i(a),obj(args...){

            cout<<a<<endl;
        }
        T _i;
        Data<U...> obj;
    };

    void func()
    {
        Data<int,int,char> obj(1,2,'a');
    }
}
int main()
{
    test1::func();
//    A<int> obj(1);
//    A<char> obj1('a');
//
//    myA<string> obj2("china");
//
//    A<int,1000> obj3(99);
//
//    int data=10000;
//    A<int &> obj5(data);
//
//    A<int *> obj6(100);
    return 0;
}