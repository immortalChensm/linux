//
// Created by Administrator on 2020/6/6.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct stackLink
{
    struct stackLink *next;
    int data;

}stackLink;

stackLink *push(stackLink *stack,int data)
{
    stackLink *temp = (stackLink*)malloc(sizeof(stackLink));
    temp->data=data;

    temp->next = stack;
    stack = temp;

    return stack;
}

stackLink *pop(stackLink *stack)
{
    if (stack){

        stackLink *temp = stack;
        stack = stack->next;
        if (temp){
            printf("%d\n",temp->data);
        }
        else{
            printf("empty stack\n");
        }

    }else{
        printf("empty stack\n");
        return stack;
    }
    return stack;
}
int main()
{

    stackLink *link = NULL;

    link = push(link,1);
    link = push(link,2);
    link = push(link,3);

    link = pop(link);
    return 0;
}