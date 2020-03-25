//
// Created by 1655664358@qq.com on 2020/3/25.
//

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define ElemType int
#define KeyType int

typedef struct BiTNode
{
    int data;
    struct BiTNode  *lchild,*rchild;
}BiTNode,*BiTree;

int SearchBst(BiTree T,KeyType key,BiTree f,BiTree *p)
{
    if (!T){
        *p = f;
        return FALSE;
    }
    else if (key==T->data){
        *p = T;
        return TRUE;
    }
    else if (key<T->data){
        return SearchBst(T->lchild,key,T,p);
    }else{
        return SearchBst(T->rchild,key,T,p);
    }
}
int InsertBst(BiTree *T,ElemType e)
{
    BiTree p = NULL;
    if (!SearchBst((*T),e,NULL,&p)){

        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data=e;
        s->lchild=s->rchild=NULL;

        if (!p){
            *T = s;
        }
        else if(e<p->data){
            p->lchild=s;
        }else{
            p->rchild=s;
        }
        return TRUE;
    }
    return FALSE;
}
int Delete(BiTree *p){

    BiTree q,s;

    if (!(*p)->lchild&&!(*p)->rchild){
        *p = NULL;
    }
    else if (!(*p)->lchild){
        q = *p;
        *p = q->rchild;
        free(q);
    }
    else if (!(*p)->rchild){
        q = *p;
        *p = q->lchild;
        free(q);
    }else{ //删除的结点  左右都有结点【树】建议看图理解

        q  = *p;//根结点
        s = (*p)->lchild;//左子树
        while (s->rchild){//左子树是否有右结点
            q = s;//左子树
            s = s->rchild;//继续存储右子树

        }
        (*p)->data = s->data;
        //当前要删除的结点
        if (q!=*p){
            q->rchild = s->lchild;
        }else{
            q->lchild=s->lchild;
        }
        free(s);

    }
    return TRUE;
}
int DeleteBst(BiTree *T,int key)
{
    if (!(*T)){
        return FALSE;
    }
    else{
        if (key == (*T)->data){
            Delete(T);
            return TRUE;
        }
        else if(key<(*T)->data){
            return DeleteBst(&(*T)->lchild,key);
        }else{
            return DeleteBst(&(*T)->rchild,key);
        }
    }
}

void order(BiTree T){

    if (T==NULL){
        return;
    }
    order(T->lchild);
    printf("%d",T->data);
    order(T->rchild);
}
int main()
{
    int i;
    int a[] = {3,4,2,5,9};

    BiTree T = NULL;
    for (int j = 0; j <5 ; ++j) {
        InsertBst(&T,a[j]);
    }

    order(T);

    printf("remove 3 elem\n");
    DeleteBst(&T,3);
    order(T);
    return 0;
}