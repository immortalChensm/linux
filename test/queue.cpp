//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int enQueue(int *a,int rear,int data)
{
    a[rear]=data;
    rear++;
    return rear;
}
void deQueue(int *a,int rear,int front)
{
    while (rear!=front){
        printf("%d\n",a[front]);
        front++;
    }
}
int main()
{
    int a[5] = {};
    int rear,front;
    rear=front=0;

    rear = enQueue(a,rear,1);
    rear = enQueue(a,rear,2);
    rear = enQueue(a,rear,3);
    rear = enQueue(a,rear,4);

    deQueue(a,rear,front);

    return 0;
}