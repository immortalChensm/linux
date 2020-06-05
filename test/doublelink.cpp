//
// Created by Administrator on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
typedef struct line
{
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initLine(line *head);
void display(line *head);

line *insertLine(line *head,int data,int add)
{
    line *temp = (line*)malloc(sizeof(line));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    
    if (add==1){
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{

        line *body = head;
        for (int i = 1; i <add ; ++i) {
            body = body->next;
        }
        if (body->next==NULL){
            body->next=temp;
            temp->prior=body;
        }else{

            body->next->prior=temp;
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
        }
    }

    return head;
}
line *delLine(line *head,int data)
{
    line *temp = head;
    while (temp){

        if (temp->data==data){

            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;

    }
    return head;
}
int searchElem(line *head,int elem)
{
    line *temp = head;
    int i=1;
    while (temp){

        if (temp->data==elem){
            return i;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}
line *updateLine(line *head,int add,int newElem)
{
    line *temp = head;
    for (int i = 1; i <add ; ++i) {
        temp = temp->next;
    }
    temp->data=newElem;
    return head;
}
void *talk(void *arg)
{
    cout<<pthread_self()<<"talk"<<endl;
}
int main()
{
    line *head=NULL;
    head = initLine(head);
    pthread_t tid;

    display(head);

    printf("%d\n",head->next->next->data);
    printf("%d\n",head->next->next->prior->data);

    cout<<"*********************"<<endl;

    head = insertLine(head,200,2);
    display(head);
    head = updateLine(head,3,2000);
    display(head);
    head = delLine(head,3);
    display(head);

    int pos = searchElem(head,5);
    cout<<pos<<endl;
    pthread_create(&tid,NULL,talk,NULL);
    sleep(1);
    return 0;
}

void display(line *list)
{
    line *temp = list;
    while (temp){

        if (temp->next==NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<->",temp->data);
        }
        temp=temp->next;
    }
}
line *initLine(line *head)
{
    head = (line*)malloc(sizeof(line));
    head->next=NULL;
    head->prior=NULL;
    head->data=1;

    line *list = head;
    for (int i = 2; i <=5 ; ++i) {

        line *body = (line*)malloc(sizeof(line));
        body->data=i;
        body->prior=NULL;
        body->next=NULL;

        head->next=body;
        body->prior=head;

        head = head->next;
    }

    return list;
}