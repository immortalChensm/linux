//
// Created by 1655664358@qq.com on 2020/3/2.
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
    head->data=1;
    head->prior=NULL;
    head->next=NULL;

    link *list = head;
    for (int i = 2; i <5 ; ++i) {

        link *body = (link*)malloc(sizeof(link));
        body->data=i;
        body->next=NULL;
        body->prior=NULL;

        list->next=body;
        body->prior=list;

        list = list->next;
    }
    return head;
}

link *insertLink(link *head,int data,int addr)
{
    link *temp = (link*)malloc(sizeof(link));
    temp->data=data;
    temp->next=NULL;
    temp->prior=NULL;

    if (addr==1){
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        link *body = head;
        for (int i = 0; i <addr ; ++i) {
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
void displayLink(link *head)
{
    link *temp = head;
    while (temp){

        if (temp->next==NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<>",temp->data);
        }
        temp = temp->next;
    }
}
link *deleteLink(link *head,int data)
{
    link *temp = head;
    while (temp){

        if (temp->data==data){

            temp->prior->next = temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }

        temp = temp->next;
    }
    return head;
}
int searchElem(link *head,int data)
{
    link *t = head;
    int i=1;
    while (t){
        if (t->data==data){
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}

link *updateLink(link *head,int data,int addr)
{
    link *temp = head;
    for (int i = 1; i <addr ; ++i) {
        temp = temp->next;
    }
    temp->data=data;
    return head;
}
int main()
{
    link *head = initLink();
    displayLink(head);

    head = insertLink(head,5,2);
    displayLink(head);

    head = deleteLink(head,5);
    displayLink(head);

    int position = searchElem(head,2);
    printf("%d\n",position);

    head = updateLink(head,200,2);
    displayLink(head);
    return 0;
}