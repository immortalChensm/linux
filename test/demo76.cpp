//
// Created by Administrator on 2020/5/8.
//

#include <iostream>
#include <string>

using namespace std;

class Array
{
public:
    Array(int length=0);
    ~Array();

public:
    int &operator[](int i);//Array[](i)
    const int &operator[](int i)const;

public:
    int length() const { return m_length;}
    void display() const;

private:
    int m_length;
    int *m_p;
};

Array::Array(int length):m_length(length) {

    if (length==0){
        m_p = NULL;
    }else{
        m_p = new int[length];
    }
}

Array::~Array() {
    delete[] m_p;
}

const int & Array::operator[](int i) const {
    return m_p[i];
}
/**
 * int &a=b
 * int *a=&b
 * @param i
 * @return
 */
int& Array::operator[](int i) {
    //得到的i是内存地址
    return m_p[i];
}

void Array::display() const {
    for (int i = 0; i < m_length; ++i) {
        if (i==m_length-1){
            cout<<m_p[i]<<endl;
        }else{
            cout<<m_p[i]<<",";
        }
    }
}

void test(int &b)
{
    b=600;

}
int &test(int &b,int c){
    b = 1000;
    return b;
}
int main()
{
//    int n;
//    cin>>n;
//
//    Array A(n);
//    for (int i = 0,len=A.length(); i <len ; ++i) {
//
//        //往指定内存写入数据
//        A[i] = i*5;
//        //A.operator[](i) 返回类型是i指定的一个引用
//    }
//    A.display();
//    const Array B(n);
//    cout<<B[n-1]<<endl;

    int b=100;
    int &a=b;
    b=101;
    cout<<a<<b<<endl;

    a=200;
    cout<<a<<b<<endl;

    test(b);
    cout<<a<<b<<endl;

    int &c = test(b,0);
    cout<<a<<b<<c<<endl;

    c = 2000;
    cout<<a<<b<<c;

    return 0;
}