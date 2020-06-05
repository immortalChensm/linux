//
// Created by Administrator on 2020/6/5.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct link
{
    struct link *next;
    int data;
}link;

typedef struct dblink
{
    struct dblink *next;
    struct dblink *piror;
    int data;
}dblink;


dblink *initDbLink(dblink *head)
{
    head = (dblink*)malloc(sizeof(dblink));
    head->data=1;
    head->next=NULL;
    head->piror=NULL;

    dblink *list = head;

    for (int i = 1; i <=5 ; ++i) {

        dblink *body = (dblink*)malloc(sizeof(dblink));
        body->data=i;
        body->piror=NULL;
        body->next=NULL;

        list->next=body;
        body->piror=list;

        list = list->next;
    }

    list->next=head;
    head->piror=list;

    return head;
}
link *initLink(link *head)
{
    head = (link*)malloc(sizeof(link));
    head->data=1;
    head->next=NULL;

    link *list = head;

    for (int i = 2; i <=5 ; ++i) {

        link *body = (link*)malloc(sizeof(link));
        body->data=i;
        body->next=NULL;

        list->next=body;
        list = list->next;
    }

    list->next=head;

    return head;
}

void display(link *head)
{
    link *temp = head;
    while (temp){

        if (temp->next==NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<->",temp->data);
        }
        temp = temp->next;
    }
}

void displaylink(dblink *head)
{
    dblink *temp = head;
    while (temp){

        if (temp->next==NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<->",temp->data);
        }
        temp = temp->next;
    }
}
int main()
{

    link *head;
    head = initLink(head);
    display(head);

//    dblink *head1;
//    head1 = initDbLink(head1);
//    displaylink(head1);
    return 0;
}