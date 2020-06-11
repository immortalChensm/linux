//
// Created by Administrator on 2020/6/11.
//

#include <iostream>
#include <string.h>
#include <string>
//三叉链
using namespace std;
#define ElemType int
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;

void createBiTree(BiTree *T)//变量名称 T  变量内容 0x01 变量地址0x02
{
    //只写T 则它的值为内存地址0x01  *0x01 则表示传递过来的内存
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->parent = NULL;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data=2;
    (*T)->lchild->parent = (*T);



    cout<<"(T):"<<(*T)->data<<endl;

    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data=3;
    (*T)->rchild->parent = (*T);

    (*T)->rchild->lchild=NULL;
    (*T)->rchild->rchild=NULL;


    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->rchild=NULL;
    (*T)->lchild->lchild->parent=(*T)->lchild;

    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild = NULL;


}
int main()
{

    //变量名称  T
    //变量地址  0x01 它有一个名字T指向此地址
    //变量内容  null
    BiTree T;
    createBiTree(&T);//把它的内存地址传递过云

//    cout<<(T->data)<<endl;
//    cout<<(T->lchild->data)<<endl;
//    cout<<(T->rchild->data)<<endl;
//
//
//    cout<<(T->lchild->lchild->data)<<endl;
//    //cout<<(T->lchild->rchild->data)<<endl;

    cout<<"***********************"<<endl;
    cout<<(T->lchild->data)<<endl;
    cout<<(T->lchild->parent->data)<<endl;

    cout<<(T->rchild->data)<<endl;
    cout<<(T->rchild->parent->data)<<endl;
    return 0;
}