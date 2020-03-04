//
// Created by 1655664358@qq.com on 2020/3/4.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct linkStack
{
    struct linkStack *next;
    int data;
}linkStack;

linkStack *push(linkStack *head,int elem)
{
    linkStack *body = (linkStack*)malloc(sizeof(linkStack));
    body->data=elem;
    body->next=head;
    head = body;
    return head;
}

linkStack *pop(linkStack *head){
    if (head){

        linkStack *temp = head;
        head = head->next;
        if (temp){
            printf("%d\n",temp->data);
        }else{
            printf("empty stack\n");
        }
        free(temp);
    }else{
        printf("empty stack\n");
        return head;
    }
    return head;
}

int main()
{

    linkStack *head = NULL;
    head = push(head,1);
    head = push(head,2);
    head = push(head,3);

    head = pop(head);
    return 0;
}