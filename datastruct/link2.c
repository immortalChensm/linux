//
// Created by 1655664358@qq.com on 2020/3/3.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct link
{
    int data;
    struct link *next;
}link;


link *initLink(int k)
{
    link *head = (link*)malloc(sizeof(link));
    head->data=1;
    head->next=NULL;

    link *temp = head;
    for (int i = 2; i <=5 ; ++i) {
        link *body = (link*)malloc(sizeof(link));
        body->data=i;
        body->next = NULL;

        temp->next = body;
        temp = temp->next;
    }
    temp->next=head;

    return head;
}

void displayLink(link *head)
{
    link *temp = head;
    while (temp){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int main()
{
    link *head = initLink(5);
    displayLink(head);
    return 0;
}