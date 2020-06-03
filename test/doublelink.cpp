//
// Created by Administrator on 2020/6/3.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initLine(line *head);
void display(line *head);

int main()
{
    line *head=NULL;
    head = initLine(head);

    display(head);

    printf("%d\n",head->next->next->data);
    printf("%d\n",head->next->next->prior->data);
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