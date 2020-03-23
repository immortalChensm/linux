//
// Created by 1655664358@qq.com on 2020/3/23.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
}ElemType;

typedef struct {
    ElemType *elem;
    int length;
}SSTable;

void createTable(SSTable **st,int length){

    (*st) = (SSTable*)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));

    printf("input table elem value\n");
    for (int i = 1; i <=length ; ++i) {
        scanf("%d",&((*st)->elem[i].key));
    }
}

int searchTable(SSTable *st,int key){
    (st)->elem[0].key = key;

    int i = (st)->length;
    while ((st)->elem[i].key!=key){
        i--;
    }
    return i;
}
int main()
{
    SSTable *st;
    createTable(&st,5);

    printf("search value\n");
    int key;
    scanf("%d",&key);
    int location = searchTable(st,key);
    if (location){
        printf("%d of location is :%d\n",key,location);
    }
    return 0;
}