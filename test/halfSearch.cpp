//
// Created by Administrator on 2020/6/17.
//

#include <stdio.h>
#include <stdlib.h>

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
    printf("input data\n");

    for (int i = 1; i <=length ; ++i) {

        scanf("%d",&((*st)->elem[i].key));
    }
}

int search(SSTable *st,KeyType key)
{
    int low = 1;
    int high = st->length;
    int mid;

    while(low<=high){

        mid = (low+high)/2;

        if(st->elem[mid].key == key){
            return mid;
        }
        else if(key<st->elem[mid].key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return 0;
}

int main(int argc,const char *argv[])
{
    SSTable *st;

    create(&st,6);

    getchar();

    printf("find key:\n");
    int key;
    scanf("%d",&key);
    int location = search(st,key);
    if (location==0){
        printf("not found\n");
    }else{
        printf("%d=%d\n",location,st->elem[location].key);
    }

    return 0;
}