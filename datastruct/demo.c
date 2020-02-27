//
// Created by 1655664358@qq.com on 2020/2/27.
//

#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
//线性表的存储指针  当前存储的数据长度  总元素个数
typedef struct table
{
    int *head;
    int length;
    int size;
}table;

table initTable()
{
    table t;
    t.head = (int*)malloc(SIZE* sizeof(int));
    if (!t.head){
        printf("init head error\n");
        exit(0);
    }
    t.length=0;
    t.size=SIZE;
    return t;
}
void displayTable(table t){
    for (int i = 0; i <t.length ; ++i) {
        printf("%d\n",*(t.head+i));
    }
}
/**
 * 插入得考虑插入的位置是否超出当前长度  同时考虑当前数据的个数是否超出总个数
 * 插入数据：最后一个元素下标加1操作，一直操作到当前指定的位置【要插入的位置】
 * @param t
 * @param add
 * @param elem
 * @return
 */
table addTable(table t,int add,int elem)
{
    if (add>t.length+1||add<1){
        printf("add error\n");
        exit(0);
    }
    if (t.length+1>=t.size){
        t.head = (int*)realloc(t.head, (t.size+1)*sizeof(int));
        if (!t.head){
            printf("t.head calloc error\n");
            return t;
        }
        t.size+=1;
    }
    for (int i = t.length-1; i >=add-1 ; i--) {
        t.head[i+1] = t.head[i];
    }
    t.head[add-1] = elem;
    t.length++;
    return t;
}
/**
 * 删除线性表的某位置上的元素
 * 删除数据：当前位置减1操作，一直减到最后一个元素的位置
 * @param t
 * @param add
 * @return
 */
table delTable(table t,int add)
{
    if (add>t.length||add<1){
        printf("del error\n");
        return t;
    }
    for (int i = add; i <t.length ; ++i) {
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
}
int searchElem(table t,int elem)
{
    for (int i = 0; i <t.length ; ++i) {
        if (t.head[i]==elem){
            return i+1;
        }
    }
    return -1;
}

table updateTable(table t,int elem,int new)
{
    int add = searchElem(t,elem);
    t.head[add-1] = new;
    return t;
}
int main()
{
    table t = initTable();
    for(int i=1;i<=t.size;i++){
        t.head[i-1] = i;
        t.length++;
    }
    displayTable(t);
    printf("add operation\n");
    t = addTable(t,3,6);
    displayTable(t);
    printf("remove operation\n");
    t = delTable(t,3);
    displayTable(t);
    printf("update operation\n");
    t = updateTable(t,3,300);
    displayTable(t);
    return 0;
}