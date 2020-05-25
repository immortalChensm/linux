//
// Created by Administrator on 2020/5/25.
//

#include <iostream>
#include <cstdlib>
#include <string>
//深拷贝测试
using namespace std;

class Array{
public:
    Array(int len);
    Array(const Array &arr);
    ~Array();

public:
    int operator[](int i)const { return m_p[i];}
    int &operator[](int i){ return m_p[i];}
    int length()const { return m_len;}
private:
    int m_len;
    int *m_p;
};

Array::Array(int len):m_len(len) {
    m_p=(int*)calloc(len, sizeof(int));
}
Array::Array(const Array &arr) {
    this->m_len=arr.m_len;
    this->m_p=(int*)calloc(this->m_len, sizeof(int));
    memcpy(this->m_p,arr.m_p,m_len* sizeof(int));
}
Array::~Array() {
    free(m_p);
}

void printArray(const Array &arr)
{
    int len = arr.length();
    for (int i = 0; i < len; i++) {
        if (i==len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<",";
        }

    }
}

int main()
{
    Array arr1(10);
    for (int i = 0; i <10 ; ++i) {
        //cout<<i<<endl;
        arr1[i] = i;
    }
    printArray(arr1);
    Array arr2 = arr1;
    arr2[5] = 100;
    arr2[3] = 20;

    printArray(arr1);
    printArray(arr2);

    return 0;
}