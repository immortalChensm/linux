//
// Created by Administrator on 2020/6/1.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Table
{

    int *head;
    int length;
    int size;
}table;

table initTable()
{

    table t;
    t.head = (int*)malloc(SIZE*sizeof(int));
    if(!t.head){

        printf("init error\n");
        exit(0);
    }

    t.length = 0;
    t.size = SIZE;
    return t;
}

table addTable(table t,int elem,int add)
{

    if(add<1||add>=t.length+1){

        printf("insert position error\n");
        return t;
    }
    if(t.length==t.size){


        t.head = (int*)realloc(t.head,(t.size+1)*sizeof(int));
        if(!t.head){

            printf("error\n");
            return t;
        }
        t.size++;
    }
    for(int i=t.length-1;i>=add-1;i--){

        t.head[i+1]=t.head[i];
    }

    t.head[add-1]=elem;
    t.length++;
    return t;
}

table deleteTable(table t,int add)
{

    if(add<1||add>t.length){

        return t;
    }

    for(int i=add;i<t.length;i++){

        t.head[i-1]=t.head[i];
    }
    t.length--;
    return t;
}

int searchTable(table t,int elem)
{

    for(int i=0;i<t.length;i++){

        if(t.head[i]==elem){

            return i+1;
        }
    }

    return -1;
}

table updateTable(table t,int elem,int newElem)
{

    int add = searchTable(t,elem);
    t.head[add-1] = newElem;
    return t;
}
void displayTable(table t)
{

    for(int i=0;i<t.length;i++){

        printf("%d\n",t.head[i]);
    }

    printf("\n");
}

int main()
{

    table t = initTable();
    for(int i=1;i<=SIZE;i++){

        t.head[i-1]=i;
        t.length++;
    }
    //printf("%d\n",t.length);
    printf("order table\n");

    displayTable(t);

    deleteTable(t,3);
    displayTable(t);

    t = addTable(t,300,3);
    displayTable(t);

    t = updateTable(t,300,30000);
    displayTable(t);


    return 0;
}
