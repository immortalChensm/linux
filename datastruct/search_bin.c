//
// Created by 1655664358@qq.com on 2020/3/23.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int key;
}ElemType;

typedef struct {
    ElemType *elem;
    int length;
}SSTable;

void createTable(SSTable **st,int length)
{
    (*st) = (SSTable*)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));

    for (int i = 1; i <=length ; ++i) {

        scanf("%d",&((*st)->elem[i].key));
    }


}

int search_bin(SSTable *st,int key)
{
    int low = 1;
    int high = st->length;
    int min=0;
    while (low<=high){

        min = (low+high)/2;
        printf("min=%d,value=%d\n",min,st->elem[min].key);
        if (st->elem[min].key == key){
            return min;
        }
        else if (key<st->elem[min].key){

            high = min-1;
        }else{
            low = min+1;
        }
    }
    return 0;
}
int main()
{
    SSTable *st;
    createTable(&st,5);
    printf("search value:\n");
    int key;
    scanf("%d",&key);

    int location = search_bin(st,key);
    if (location){
        printf("%d of location is :%d\n",key,location);
    }else{
        printf("not found\n");
    }
    return 0;
}
