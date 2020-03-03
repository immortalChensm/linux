//
// Created by 1655664358@qq.com on 2020/3/3.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    struct link *prior;
    int data;
    struct link *next;
}link;


link *initLink()
{
    link *head = (link*)malloc(sizeof(link));
    head->next=NULL;
    head->prior=NULL;
    head->data=1;

    link *temp = head;
    for (int i = 2; i <=5 ; ++i) {

        link *body = (link*)malloc(sizeof(link));
        body->data=i;
        body->next=NULL;
        body->prior=NULL;

        temp->next=body;
        body->prior=temp;

        temp=temp->next;
    }

    temp->next=head;
    head->prior=temp;

    return head;
}

void displayLink(link *head)
{
    link *temp = head;
    while(temp->next!=head){

        if (temp->next==NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<>",temp->data);
        }
        temp=temp->next;
    }
    printf("\n*****************\n");
    while (temp->prior!=head){
        printf("%d<>",temp->data);
        temp=temp->prior;
    }
}

int main()
{
    link *head = initLink();
    displayLink(head);
    return 0;
}