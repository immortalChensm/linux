//
// Created by Administrator on 2020/7/22.
//

#include <iostream>
#include <string>

class A{
public:
    int _i;
    A *next;
};
int main()
{
    A *tmp;
    size_t size = 5*sizeof(A);

    A *mem = reinterpret_cast<A*>(new char[size]);
    //A *mem = new A[5]();
    tmp = mem;
    for(;tmp!=&mem[size-1];++tmp){

        tmp->next = tmp+1;
    }

    tmp = mem;
    mem = mem->next;
    tmp->_i=10;
    std::cout<<tmp->_i<<std::endl;




    return 0;
}