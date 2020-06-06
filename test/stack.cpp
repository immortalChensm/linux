//
// Created by Administrator on 2020/6/6.
//

#include <iostream>
#include <string>

using namespace std;

int push(int *a,int pop,int elem)
{
    a[++pop]=elem;
    return pop;
}
int pop(int *a,int pop)
{
    if(pop==-1){
        return -1;
    }
    printf("%d\n",a[pop]);
    pop--;
    return pop;
}
int main()
{

    int a[100];
    int top=-1;
    top = push(a,top,1);
    top = push(a,top,2);
    top = push(a,top,3);

    cout<<"******************"<<endl;

    top = pop(a,top);
    top = pop(a,top);
    top = pop(a,top);
    top = pop(a,top);
    top = pop(a,top);


    return 0;
}