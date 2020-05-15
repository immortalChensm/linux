//
// Created by Administrator on 2020/5/15.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

template <typename T,int N>
class Array{
public:
    Array();
    ~Array();

public:
    T &operator[](int i);
    int length()const { return m_length;}
    bool capacity(int n);

private:
    int m_length;
    int m_capacity;
    T *m_p;
};

template <typename T,int N>
Array<T,N>::Array() {

    this->m_p = new T[N];
    this->m_capacity = this->m_length = N;
}

template <typename T,int N>
Array<T,N>::~Array() {
    delete[] this->m_p;
}

template <typename T,int N>
T & Array<T,N>::operator[](int i) {

    if (i<0||i>=m_length){
        cout<<"exception:Array index out of bounds!"<<endl;
    }
    return this->m_p[i];
}

template <typename T,int N>
bool Array<T,N>::capacity(int n) {

    if (n>0){

        int len = this->m_length+n;
        if (len<=this->m_capacity){
            this->m_length=len;
            return true;
        }else{
            T *pTemp = new T[this->m_length+2*n* sizeof(T)];
            if (pTemp==NULL){
                cout<<"exception:failed to allocate memory!"<<endl;
                return false;
            }else{
                memcpy(pTemp,this->m_p,this->m_length* sizeof(T));
                delete [] m_p;
                this->m_p=pTemp;
                this->m_capacity=this->m_length=len;
            }
        }
    }else{
        int len = this->m_length-abs(n);
        if (len<0){
            cout<<"Exception:Array length is to small!"<<endl;
            return false;
        }else{
            this->m_length=len;
            return true;
        }
    }
}

int main()
{
    Array<int ,5>arr;

    for (int i = 0,len=arr.length() ; i<len;++i) {

        arr[i] = 2*i;
    }
    for (int j = 0,len=arr.length();j <len ; ++j) {

        cout<<arr[j]<<" ";
    }

    cout<<endl;

    arr.capacity(8);
    for (int j = 0,len=arr.length();j <len ; ++j) {

        cout<<arr[j]<<" ";
    }
    return 0;
}