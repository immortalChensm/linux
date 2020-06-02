//
// Created by Administrator on 2020/6/2.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct Link
{
    char elem;
    struct Link *next;
}link;

link *initLink()
{
    link *p = NULL;
    link *temp = (link*)malloc(sizeof(link));

    temp->elem=1;
    temp->next=NULL;

    p = temp;

    for (int i = 2; i <=5; ++i) {

        link *a = (link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;

        temp->next=a;
        temp=temp->next;
    }
    return p;
}
void display(link *p)
{
    link *temp = p;

    while (temp){

        printf("%d\n",temp->elem);
        temp = temp->next;
    }
}
link *insertElem(link *p,int elem,int add)
{
    link *temp = p;
    for (int i = 1; i <add ; ++i) {

        temp = temp->next;
        if (temp==NULL){
            return p;
        }
    }
    link *a = (link*)malloc(sizeof(link));
    a->elem=elem;
    a->next= temp->next;
    temp->next=a;
    return p;
}
link *deleteElem(link *p,int add)
{
    link *temp = p;
    for (int i = 1; i <add ; ++i) {

        temp = temp->next;
        if (temp->next==NULL){
            return p;
        }
    }
    link *del = temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}
int searchElem(link *p,int elem)
{
    link *temp = p;
    int i=1;
    while (temp->next){

        temp = temp->next;
        if (temp->elem==elem){
            return i;
        }
        i++;
    }
    return -1;
}
link *updateElem(link *p,int add,int elem)
{
    link *temp = p;
    for (int i = 1; i <add ; ++i) {
        temp = temp->next;
    }
    temp->elem=elem;
    return p;
}
int main()
{
    link *p = initLink();
    display(p);

    cout<<"***************"<<endl;
    p = insertElem(p,100,2);
    display(p);

    cout<<"*****************"<<endl;

    p = deleteElem(p,2);
    display(p);

    cout<<"*****************"<<endl;
    p = updateElem(p,2,88);
    display(p);

    int t = searchElem(p,5);
    cout<<t<<endl;
    return 0;
}