//
// Created by 1655664358@qq.com on 2020/3/10.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void initTree(BiTree *tree)
{
    (*tree) = (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->data = 1;

    (*tree)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*tree)->lchild->data=2;
    (*tree)->rchild->data=3;

    (*tree)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->lchild->lchild->data=4;
    (*tree)->lchild->lchild->lchild=NULL;
    (*tree)->lchild->lchild->rchild=NULL;

    (*tree)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->lchild->rchild->data=5;
    (*tree)->lchild->rchild->lchild=NULL;
    (*tree)->lchild->rchild->rchild=NULL;

    (*tree)->rchild->lchild= (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->rchild->lchild->data=6;
    (*tree)->rchild->lchild->lchild=NULL;
    (*tree)->rchild->lchild->rchild=NULL;
    (*tree)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*tree)->rchild->rchild->data=7;
    (*tree)->rchild->rchild->lchild=NULL;
    (*tree)->rchild->rchild->rchild=NULL;


}

void displayItem(BiTNode *node)
{
    printf("%d\n",node->data);
}
void preOrderTraverse(BiTree tree)
{
    if (tree){
        //displayItem(tree);
        preOrderTraverse(tree->lchild);
        //displayItem(tree);
        preOrderTraverse(tree->rchild);
        displayItem(tree);
    }
}
int main()
{
    BiTree tree;
    initTree(&tree);

    preOrderTraverse(tree);

    return 0;
}

