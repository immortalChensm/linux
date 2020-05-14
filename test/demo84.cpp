//
// Created by Administrator on 2020/5/11.
//

#include <iostream>
#include <string>
//函数模板重载
using namespace std;

template <class T>void Swap(T &a,T &b);
template <typename T> void Swap(T a[],T b[],int len);

void printArray(int arr[],int len);

int main()
{

    int m=10,n=99;
    Swap(m,n);
    cout<<m<<","<<n<<endl;

    int a[5] = {5,4,3,2,1};
    int b[5] = {10,20,30,40,50};

    int len = sizeof(a)/ sizeof(int);
    Swap<int>(a,b,len);
    printArray(a,len);
    printArray(b,len);

    //*c = &b[0]
    //*c[]
    int (&c)[] = b;
    cout<<c[1]<<endl;
    return 0;
}

template <class T>void Swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template <typename T> void Swap(T a[],T b[],int len)
{
    T temp;
    for (int i = 0; i <len ; ++i) {

        temp = a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

void printArray(int arr[],int len)
{
    for (int i = 0; i <len ; ++i) {

        if (i==len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<",";
        }
    }
}