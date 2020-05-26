//
// Created by Administrator on 2020/5/26.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Array
{
public:
    Array(int len);
    Array(const Array &arr);
    ~Array();

public:
    int operator[](int i)const { return m_p[i];}
    int &operator[](int i){ return m_p[i];}
    Array &operator=(const Array &arr);
    int length() const { return m_len;}
private:
    int m_len;
    int *m_p;
};

Array::Array(int len):m_len(len) {
    m_p = (int*)calloc(len, sizeof(int));
}

Array::Array(const Array &arr) {
    this->m_len=arr.m_len;
    this->m_p = (int*)calloc(this->m_len, sizeof(int));
    memcpy(this->m_p,arr.m_p,m_len* sizeof(int));
}

Array::~Array() {
    free(m_p);
}

Array& Array::operator=(const Array &arr) {
    if (this!=&arr){
        this->m_len=arr.m_len;
        free(this->m_p);
        this->m_p=(int*)calloc(this->m_len, sizeof(int));
        memcpy(this->m_p,arr.m_p,m_len* sizeof(int));
    }
    return *this;
}

void printArray(const Array &arr){
    int len = arr.length();
    for (int i = 0; i <len ; ++i) {

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
        arr1[i]=i;
    }

    printArray(arr1);

    Array arr2(5);
    for (int j = 0; j <5 ; ++j) {
        arr2[j]=j;
    }
    printArray(arr2);
    arr2 = arr1;


    arr2[3]=234;
    arr2[7]=920;

    printArray(arr1);

    return 0;
}