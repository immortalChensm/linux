//
// Created by Administrator on 2020/6/19.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ElemType int
#define KeyType int

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int searchBST(BiTree T,KeyType key,BiTree f,BiTree *p)
{
    if(!T){
        *p = f;
        return FALSE;
    }

    else if(key == T->data){
        *p = T;
        return TRUE;
    }
    else if(key < T->data){
        return searchBST(T->lchild,key,T,p);
    }else{
        return searchBST(T->rchild,key,T,p);
    }
}

int insertBST(BiTree *T,ElemType e)
{
    BiTree p = NULL;
    printf("ccc\n");
    if(!searchBST((*T),e,NULL,&p)){

        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->lchild = NULL;


        if(!p){

            *T = s;
            printf("%d==%d\n",s->data,(*T)->data);
        }
        else if(e<p->data){
            p->lchild = s;
            printf("%d==%d\n",s->data,(*T)->data);
        }else{
            p->rchild = s;
            printf("%d==%d\n",s->data,(*T)->data);
        }

        return TRUE;
    }else{
        //printf("bbb\n");
    }
    return FALSE;
}

int Delete(BiTree *p)
{
    BiTree q,s;

    if(!(*p)->lchild && !(*p)->rchild){
        *p = NULL;
    }

    else if(!(*p)->lchild){

        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if(!(*p)->rchild){
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else{

        q = *p;
        s = (*p)->lchild;

        while(s->rchild){
            q = s;
            s = s->rchild;
        }

        (*p)->data = s->data;
        if(q!=*p){
            q->rchild = s->lchild;
        }
        else{
            q->lchild = s->lchild;
        }
        free(s);
    }
    return TRUE;
}

int deleteBST(BiTree *T,int key)
{
    if(!(*T)){
        return FALSE;
    }
    else{

        if(key==(*T)->data){
            Delete(T);
            return TRUE;
        }
        else if(key<(*T)->data){
            return deleteBST(&(*T)->lchild,key);
        }else{
            return deleteBST(&(*T)->lchild,key);
        }
    }
}

void order(BiTree t)
{
    if(t == NULL){
        return;
    }
    order(t->lchild);
    printf("%d",t->data);
    order(t->rchild);
}

int main()
{
    int i;
    int a[5] = {3,5,7,2,1};

    BiTree T = NULL;

    for (int j = 0; j <5 ; ++j) {
        //printf("%d\n",j);
        insertBST(&T,a[j]);
    }

    printf("data:\n");

    order(T);
    //printf("data:\n");
    printf("remove 3\n");
    deleteBST(&T,3);
    order(T);

    return 0;
}