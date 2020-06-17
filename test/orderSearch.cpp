//
// Created by Administrator on 2020/6/16.
//

#include <stdlib.h>
#include <stdio.h>

#define KeyType int

typedef struct
{
    KeyType key;

}ElemType;

typedef struct
{
    ElemType *elem;
    int length;
}SSTable;

void create(SSTable **st,int length)
{
    (*st) = (SSTable*)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));

    printf("input data:\n");

    for (int i = 1; i <length ; ++i) {

        scanf("%d",&((*st)->elem[i].key));
    }
}

int search(SSTable *st,KeyType key)
{
    st->elem[0].key = key;

    int i = st->length;

    while (st->elem[i].key!=key){
        i--;
    }
    return i;
}

int main()
{
    SSTable *st;

    create(&st,6);

    getchar();

    printf("input key:\n");
    int key;

    scanf("%d",&key);

    int location = search(st,key);

    if (location==0){
        printf("not found\n");
    }else{
        printf("find:%d\n",location);
    }

    return 0;
}