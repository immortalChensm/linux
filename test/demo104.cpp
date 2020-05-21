//
// Created by Administrator on 2020/5/21.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class OutOfRange{
public:
    OutOfRange():m_flag(1){};
    OutOfRange(int len,int index):m_len(len),m_index(index),m_flag(2){}

public:
    void what() const;
private:
    int m_flag;
    int m_len;
    int m_index;
};

void OutOfRange::what() const {
    if (this->m_flag==1){
        cout<<"Error:empty array,no elements to pop."<<endl;
    }
    else if(this->m_flag==2){
        cout<<"Error:out of range(array length"<<this->m_len<<",access index"<<this->m_index<<")"<<endl;
    }else{
        cout<<"Unknown exception."<<endl;
    }
}

class Array{
public:
    Array();
    ~Array(){free(m_p);};
public:
    int operator[](int i)const;
    int push(int ele);
    int pop();
    int length()const{return this->m_len;};
private:
    int m_len;
    int m_capacity;
    int *m_p;
private:
    static const int m_stepSize=50;
};

Array::Array() {
    this->m_p = (int*)malloc(sizeof(int)*this->m_stepSize);
    this->m_capacity=this->m_stepSize;
    this->m_len=0;
}

int Array::operator[](int i) const {
    if (i<0||i>=this->m_len){
        throw OutOfRange(this->m_len,i);
    }

    return *(this->m_p+i);
}

int Array::push(int ele) {

    if (this->m_len>=this->m_stepSize){
        this->m_capacity+=this->m_stepSize;
        this->m_p=(int*)realloc(this->m_p, sizeof(int)*this->m_capacity);
    }
    *(this->m_p+this->m_len) = ele;
    this->m_len++;
    return this->m_len-1;
}

int Array::pop() {
    if (this->m_len==0){
        throw OutOfRange();
    }
    this->m_len--;
    return *(this->m_p+this->m_len);
}

void printArray(Array &arr)
{
    int len = arr.length();
    if (len==0){
        cout<<"Empty array!no elements to print."<<endl;
        return;
    }
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

    Array nums;

    for (int i = 0; i <10 ; ++i) {

        nums.push(i);
    }

    printArray(nums);

    try{
        cout<<nums[20]<<endl;
    }catch (OutOfRange &e){
        e.what();
    }

    try{
        for (int i = 0; i <20 ; ++i) {
            nums.pop();
        }
    }catch (OutOfRange &e){
        e.what();
    }

    printArray(nums);
    return 0;
}