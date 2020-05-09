//
// Created by Administrator on 2020/5/9.
//

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class CArray
{
    int size;
    T *ptr;
public:
    //构造函数
    CArray(int s=0);
    CArray(CArray &a);
    ~CArray();
    void push_back(const T &v);
    //operator=()赋值运算符重载
    CArray &operator=(const CArray &a);
    T length(){return size;}
    //赋值重载函数 返回ptr中指定的成员地址
    T &operator[](int i){
        return ptr[i];
    }
};
//构造函数
template<class T>
CArray<T>::CArray(int s):size(s) {

    if (s==0){
        ptr = NULL;

    }else{
        ptr = new T[s];
    }
}
//重载构造 用于复制
template<class T>
CArray<T>::CArray(CArray &a) {
    if (!a.ptr){
        ptr = NULL;
        size = 0;
        return ;
    }

    ptr = new T[a.size];
    memcpy(ptr,a.ptr, sizeof(T)*a.size);
    size = a.size;
}
//析构函数
template <class T>
CArray<T>::~CArray() {
    if (ptr)delete [] ptr;
}
//=赋值运算符重载函数
template <class T>
CArray<T>& CArray<T>::operator=(const CArray &a) {

    if (this==&a){
        return *this;
    }
    if (a.ptr==NULL){
        if (ptr){
            delete [] ptr;
        }
        ptr = NULL;
        size = 0;
        return *this;
    }
    if (size<a.size){
        if (ptr){
            delete [] ptr;
            ptr = new T[a.size];
        }

    }
    memcpy(ptr,a.ptr, sizeof(T)*a.size);
    size = a.size;
    return  *this;
}
template <class T>
void CArray<T>::push_back(const T &v) {
    if (ptr){
        T *tmpPtr = new T[size+1];
        cout<<"size="<<this->size<<endl;
        memcpy(tmpPtr,ptr, sizeof(T)*size);
        delete []ptr;
        ptr = tmpPtr;
    }else{
        ptr = new T[1];

    }
    ptr[size++] = v;
}

int main()
{
    CArray<int> a;

    for (int i = 0; i <5 ; ++i) {
        a.push_back(i);

    }
    for (int j = 0; j <a.length() ; ++j) {
        cout<<a[j]<<"";
    }

    return 0;
}

