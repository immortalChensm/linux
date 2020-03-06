//
// Created by 1655664358@qq.com on 2020/3/6.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
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

QNode *enQueue(QNode *queue,int data)
{
    QNode *node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next=NULL;
    queue->next = node;

    queue = node;
    return queue;
}

QNode *deQueue(QNode *queue,QNode *top)
{
    if (top->next==NULL){
        printf("null queue\n");
        return queue;
    }

    QNode *temp = top->next;
    top->next = temp->next;
    printf("%d\n",temp->data);
    if (temp==queue){
        queue = top;
    }
    free(temp);
    return queue;
}
int main()
{

    QNode *near,*top;
    top=near=initQueue();

    near = enQueue(near,1);
    near = enQueue(near,2);
    near = enQueue(near,3);
    //head->1->2->3
    //head=top
    //top->1->2->3
    //near=3

    near = deQueue(near,top);
    near = deQueue(near,top);
    near = deQueue(near,top);
    near = deQueue(near,top);


    near = enQueue(near,4);
    near = enQueue(near,5);
    near = enQueue(near,6);

    near = deQueue(near,top);
    near = deQueue(near,top);
    near = deQueue(near,top);
    return 0;
}