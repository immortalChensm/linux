//
// Created by Administrator on 2020/5/14.
//

#include <iostream>
#include <string>
//模板非类型参数
using namespace std;
template <class T> void Swap(T &a,T &b);
//T是类型参数  N是非类型参数
template <typename T,unsigned N>void Swap(T (&a)[N],T (&b)[N]);

template <typename T,unsigned N>void printfArray(T (&a)[N]);

int main()
{

    int m=10,n=99;
    Swap(m,n);
    cout<<m<<","<<n<<endl;

    int a[5] = {1,2,3,4,5};
    int b[5] = {10,20,30,40,50};

    Swap(a,b);
    printfArray(a);
    printfArray(b);

    /**
     * int (*c)[5];
     * int (*c)
     * int [5]
     */
     //存储含有5个元素地址的指针变量【引用】
    int (&c)[5] = b;
    cout<<c[1]<<endl;

    int e[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    int (*d)[5] = e;
    cout<<d[0][0]<<endl;

    return 0;
}

template <class T>void Swap(T &a,T &b)
{
    T temp = a;
    a=b;
    b=temp;
}

template <typename T,unsigned N>void Swap(T (&a)[N],T (&b)[N])
{
    T temp;
    for(int i=0;i<N;i++){
        temp = a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}
template <typename T,unsigned N>void printfArray(T (&arr)[N])
{
    for (int i = 0; i <N ; ++i) {

        if (i==N-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<",";
        }
    }
}
