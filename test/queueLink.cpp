//
// Created by Administrator on 2020/6/9.
//

#include <iostream>
#include <string.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

QNode *initQueue()
{
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->data=0;
    queue->next=NULL;
    return queue;
}
QNode *enQueue(QNode *rear,int elem)
{
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    temp->data = elem;
    temp->next=NULL;

    rear->next=temp;
    rear = temp;
    return rear;
}

QNode *deQueue(QNode *top,QNode *rear)
{
    if(top->next==NULL){
        return top;
    }

    QNode *p = top->next;//1 2 3 4 5
    top->next = p->next;//0->2  0->3 0->4 0->5 p->null
    printf("%d\n",p->data);

    //取到最后一个时，rear重置指向 初始的结点0
    if (p==rear){
        rear = top;
    }
    free(p);

    return rear;

}
int main()
{
    QNode *queue,*top,*rear;
    queue = rear=top=initQueue();

    rear = enQueue(rear,1);
    rear = enQueue(rear,2);
    rear = enQueue(rear,3);
    rear = enQueue(rear,4);
    rear = enQueue(rear,5);

    rear = deQueue(top,rear);
    rear = deQueue(top,rear);
    rear = deQueue(top,rear);

    printf("%d\n",(int)(~5));
    return 0;
}