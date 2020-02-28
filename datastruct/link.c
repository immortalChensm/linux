//
// Created by 1655664358@qq.com on 2020/2/28.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    char elem;
    struct Link *next;
}link;
//头结点  首元结点  其它结点
link *initLink()
{
    link *p = NULL;//头指针
    link *temp = (link*)malloc(sizeof(link));//首元结点
    temp->elem=1;
    temp->next=NULL;

    /**
     * 变量名 temp
     * 变量内容 结构体内存
     * 变量机器地址 xx0
     */
    p = temp;//头指针->首元结点
    /**
     * 变量名  p
     * 变量内容  temp
     * 变量机器地址 xx1
     */
    for (int i = 2; i <5 ; ++i) {
        //创建新的内存结点
        link *a = (link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        //temp的指针域保存新结点
        temp->next=a;
        //p头指针已经存储了首元结点的数据
        //此时首元结点的存储内容为新结点
        temp=temp->next;
    }
    /**   temp           a               a1
     * -------      ----------       ----------
     * |  1   |---->|  2      |----->|   3     |
     * |------      |_________|      |_________|
     *
     *    p=temp    temp=a           temp=a1
     */
    return p;
}
/**
 * 需要判断  插入位置
 * @param p
 * @param elem
 * @param add
 * @return
 */
link *insertLink(link *p,int elem,int add)
{
    link *temp = p;
    for (int i = 0; i <add ; ++i) {
        temp = temp->next;
        if (temp==NULL){
            printf("insert error\n");
            return p;
        }
    }
    link *c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next=temp->next;
    temp->next=c;
    return p;
}

link *deleteLink(link *p,int add)
{
    link *temp = p;
    for (int i = 0; i <add ; ++i) {
        temp = temp->next;
        if (temp->next==NULL){
            printf("delete error\n");
            return p;
        }
    }
    link *del = temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}

link *updateLink(link *p,int add,int elem)
{
    link *temp = p;
    for (int i = 0; i <add ; ++i) {
        temp = temp->next;
    }
    temp->elem=elem;
    return p;
}
void displayLink(link *p)
{
    link *temp = p;
    while (temp){
        printf("%d\n",temp->elem);
        temp = temp->next;
    }
}
int main()
{

    link *data = initLink();
    displayLink(data);

    printf("****************\n");
    data = insertLink(data,50,2);
    displayLink(data);
    printf("*****************\n");
    data = updateLink(data,3,5);
    displayLink(data);
    printf("*****************\n");
    data = updateLink(data,4,44);
    displayLink(data);

    printf("remove \n");
    data = deleteLink(data,3);
    displayLink(data);
    return 0;
}