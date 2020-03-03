//
// Created by 1655664358@qq.com on 2020/3/3.
//
#include <stdlib.h>
#include <stdio.h>

int push(int *a,int top,int elem)
{
    a[++top] = elem;
    return top;
}
int pop(int *a,int top)
{
    if (top==-1){
        return -1;
    }
    printf("%d\n",a[top]);
    top--;
    return top;
}
int main()
{
    int a[10];
    int top=-1;

    top = push(a,top,1);
    top = push(a,top,2);
    top = push(a,top,3);
    top = push(a,top,4);
    top = push(a,top,5);

    printf("%d\n",top);

    top = pop(a,top);
    printf("%d\n",top);
}

