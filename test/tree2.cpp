//
// Created by Administrator on 2020/6/12.
//

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

#define ElemType int

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

int rear=0,front=0;

void enQueue(BiTree *a,BiTree node)
{
    a[rear++] = node;
}
BiTree deQueue(BiTree *a)
{
    return a[front++];
}
void createBiTree(BiTree *T)
{
    (*T) = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->lchild->data = 2;
    (*T)->rchild->data = 3;

    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->rchild->data = 5;

    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;

    (*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->rchild->data = 7;

    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;

    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
}

void PreOrderTraverse(BiTree T)
{
    if(T){
        printf("%d",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return;
}
int main()
{

    BiTree T;
    createBiTree(&T);

    //PreOrderTraverse(T);
    BiTree p;
    BiTree a[20];

    enQueue(a,T);
    while(front<rear){

        p = deQueue(a);
        printf("%d\n",p->data);
        if(p->lchild!=NULL){
            enQueue(a,p->lchild);
        }
        if (p->rchild!=NULL){
            enQueue(a,p->rchild);
        }
    }
    return 0;
}