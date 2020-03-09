//
// Created by 1655664358@qq.com on 2020/3/9.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;

void initBiTNode(BiTree *T)
{
    *T = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->data=1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data=2;
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data=3;

    (*T)->parent = NULL;
    (*T)->lchild->parent = (*T);


    (*T)->rchild->lchild=NULL;
    (*T)->rchild->rchild=NULL;
    (*T)->rchild->parent = (*T);

    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->rchild=NULL;

    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
    (*T)->lchild->lchild->parent = (*T)->lchild;




}

void main()
{
    BiTree T;

    initBiTNode(&T);

    printf("%d\n",(T)->lchild->lchild->data);
    printf("%d\n",(T)->lchild->lchild->parent->data);

}