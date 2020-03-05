//
// Created by 1655664358@qq.com on 2020/3/5.
//

#include <stdio.h>
#include <stdlib.h>

int enQueue(int *a,int near,int data)
{
    a[near] = data;
    near++;
    return near;
}
void deQueue(int *a,int near,int front)
{
    while (front!=near){
        printf("%d\n",a[front]);
        front++;
    }
}
int main()
{
    int a[100];
    int front,near;
    front=near=0;

    near = enQueue(a,near,1);
    near = enQueue(a,near,2);
    near = enQueue(a,near,3);

    deQueue(a,near,front);

    return 0;
}