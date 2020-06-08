//
// Created by Administrator on 2020/6/8.
//

#include <stdio.h>
#include <iostream>
#define max 5

using namespace std;

int enQueue(int *a,int rear,int front,int data)
{
    if ((rear+1)%max==front){
        cout<<"queue is full"<<endl;
        return rear;
    }
    a[rear%max] = data;
    rear++;
    return rear;
}

int deQueue(int *a,int rear,int front)
{
    if (front==(rear%max)){
        cout<<"queue is empty"<<endl;
        return front;
    }

    printf("%d",a[front]);
    front = (front+1)%max;
    return front;
}
int main()
{

    int a[max] = {};
    int rear,front;
    rear=front=0;

    rear = enQueue(a,rear,front,1);
    rear = enQueue(a,rear,front,2);
    rear = enQueue(a,rear,front,3);
    rear = enQueue(a,rear,front,4);
    rear = enQueue(a,rear,front,5);

    front = deQueue(a,rear,front);
    front = deQueue(a,rear,front);
    front = deQueue(a,rear,front);
    front = deQueue(a,rear,front);

    rear = enQueue(a,rear,front,5);
    rear = enQueue(a,rear,front,6);
    rear = enQueue(a,rear,front,7);

    front = deQueue(a,rear,front);
    front = deQueue(a,rear,front);
    front = deQueue(a,rear,front);

    cout<<"rear="<<rear<<"front="<<front<<endl;
    return 0;
}