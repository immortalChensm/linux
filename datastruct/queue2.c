//
// Created by 1655664358@qq.com on 2020/3/5.
//

#include <stdlib.h>
#include <stdio.h>

int max = 5;
int enQueue(int *a,int near,int front,int data)
{
    if ((near+1)%max==front){
        printf("full of queue\n");
        return near;
    }
    a[near%max] = data;
    near++;
    return near;

}

int deQueue(int *a,int front,int near)
{
    if (front==near%max){
        printf("empty of queue\n");
        return front;
    }
    printf("%d\n",a[front]);
    front = (front+1)%max;
    return front;
}
int main()
{
    int a[100];
    int front,near;
    front=near=0;

    near = enQueue(a,near,front,1);
    near = enQueue(a,near,front,2);
    near = enQueue(a,near,front,3);

    printf("near=%d\n",near);


    front = deQueue(a,front,near);
    front = deQueue(a,front,near);
    //printf("front=%d\n",front);
    front = deQueue(a,front,near);
    printf("front=%d\n",front);

    front = deQueue(a,front,near);

    near = enQueue(a,near,front,1);
    printf("near=%d\n",near);
    return 0;

}