//
// Created by 1655664358@qq.com on 2020/3/24.
//

#include <stdio.h>
#include <stdlib.h>

struct index{
    int key;
    int start;
}newIndex[3];

int cmp(const void *a,const void *b)
{
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}

int search(int key,int *a)
{
    int i,startValue;
    i=0;
    while (i<3&&key>newIndex[i].key){
        i++;
    }

    if (i>=3){
        return 0;
    }

    startValue = newIndex[i].start;
    //0<5 1<6 5<6
    //6<11
    while (startValue<=startValue+5&&a[startValue]!=key){
        startValue++;
    }

    if (startValue>startValue+5){
        return -1;
    }
    return startValue;
}
int main()
{
    int i,j=-1,k,key;
    int a[] = {33,42,44,38,24,48, 22,12,13,8,9,20,  60,58,74,49,86,53};

    for (i=0;i<3;i++) {
        newIndex[i].start = j+1;
        j+=6;

        for(k=newIndex[i].start;k<=j;k++){

            if (newIndex[i].key<a[k]){
                newIndex[i].key = a[k];
            }
        }
    }

    qsort(newIndex,3, sizeof(newIndex[0]),cmp);

    for (int l = 0; l <3 ; ++l) {
        printf("%d=%d\n",newIndex[l].start,newIndex[l].key);
    }

    printf("find key\n");
    scanf("%d",&key);
    k = search(key,a);
    if (k){
        printf("location :%d\n",k);
    }
    return 0;
}