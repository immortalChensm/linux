//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>
//访问私有成员
using namespace std;

class A{
public:
    A(int a,int b,int c);

private:
    int m_a;
    int m_b;
    int m_c;
};

A::A(int a, int b, int c):m_a(a),m_b(b),m_c(c) {}

int main()
{
   // A *obj = new A(1,2,3);
    //cout<<obj->m_c<<endl;
//    printf("%#x\n",&obj);
//    printf("%#x\n",obj);
//    printf("%#x\n",&(obj->m_a));
//    printf("%#x\n",&(obj->m_b));
//    printf("%#x\n",&(obj->m_c));

//    cout<<"********************\n";
//    printf("%d\n",*(int*)obj);
//    //printf("%d\n",*(int*)( (int)obj + sizeof(int)*2 ));
//    int b = *(int*)( (int)obj + 4 );
//    cout<<b<<endl;
    A obj(1,2,3);
    printf("%#x\n",&obj);
    printf("%d\n",*(int*)&obj);
    printf("%#x\n",(int*)(&obj+ sizeof(int)));
    return 0;
}