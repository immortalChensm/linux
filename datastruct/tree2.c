//
// Created by 1655664358@qq.com on 2020/3/16.
//

#include <stdio.h>
#include <stdlib.h>
//孩子链表示法
#define MAX_SIZE 20
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}CTNode;

typedef struct CTBox
{
    char elemData;
    CTNode *firstChild;
}CTBox;

typedef struct CTree
{
    CTBox nodes[MAX_SIZE];
    int n,r;
}CTree;

CTree initTree(CTree tree)
{
    printf("please input tree number \n");
    scanf("%d",&(tree.n));
    for (int i = 0; i <tree.n ; ++i) {

        printf("please input %d node of value:\n",i+1);
        getchar();
        scanf("%c",&(tree.nodes[i].elemData));
        tree.nodes[i].firstChild = (CTNode*)malloc(sizeof(CTNode));
        tree.nodes[i].firstChild->next = NULL;

        printf("please input %c node of child number:\n",tree.nodes[i].elemData);
        int num=0;
        getchar();
        scanf("%d",&num);
        if (num){
            CTNode *p = tree.nodes[i].firstChild;
            for (int j = 0; j <num ; ++j) {

                CTNode *temp = (CTNode*)malloc(sizeof(CTNode));
                temp->next= NULL;
                printf("please input %c of %d child index:\n",tree.nodes[i].elemData,j+1);
                scanf("%d",&(temp->child));

                p->next = temp;
                p = p->next;
            }
        }
    }
    return tree;
}

void findKids(CTree tree,char a)
{
    int hasKid=0;
    for (int i = 0; i <tree.n ; ++i) {

        if (tree.nodes[i].elemData==a){

            CTNode *p = tree.nodes[i].firstChild->next;

            while (p){
                hasKid=1;
                printf("%d==%c",p->child,tree.nodes[p->child].elemData);
                p = p->next;
            }
            break;

        }
    }
    if (!hasKid){
        printf("this node is empty node\n");
    }
}
int main()
{
    CTree tree;
    for (int i = 0; i <MAX_SIZE ; ++i) {
        tree.nodes[i].firstChild = NULL;
    }

    tree = initTree(tree);
    tree.r = 0;
    //printf("%d\n",tree.n);
    //printf("%d\n",tree.n);
    //printf("tree:%c %c\n",tree.nodes[0].elemData,'C');//,tree.nodes[tree.nodes[0].firstChild->child].elemData
    printf("show %c node of child value\n",'A');
    findKids(tree,'A');

    return 0;
}