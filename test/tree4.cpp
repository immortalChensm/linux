//
// Created by Administrator on 2020/6/15.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

#define TElemType char
//孩子链表示法
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}ChildPtr;

typedef struct {
    TElemType data;
    ChildPtr *firstChild;
}CTBox;

typedef struct {
    CTBox nodes[MAX_SIZE];
    int n,r;
}CTree;

CTree initTree(CTree tree)
{
    printf("node num:\n");
    scanf("%d",&(tree.n));

    for (int i = 0; i <tree.n ; i++) {

        printf("input %d node of value:\n",i+1);

        getchar();

        scanf("%c",&(tree.nodes[i].data));

        tree.nodes[i].firstChild = (ChildPtr*)malloc(sizeof(ChildPtr));
        tree.nodes[i].firstChild->next = NULL;
        tree.nodes[i].firstChild->child = -1;

        printf("input %c child num node:\n",tree.nodes[i].data);

        int num;

        scanf("%d",&num);

        if (num!=0){

            ChildPtr *p = tree.nodes[i].firstChild;
            for(int j=0;j<num;j++){

                ChildPtr *temp = (ChildPtr*)malloc(sizeof(ChildPtr));
                temp->next = NULL;

                printf("input %c child %d position value:",tree.nodes[i].data,j+1);
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
    int hasKids = 0;

    for (int i = 0; i <tree.n ; ++i) {

        if(tree.nodes[i].data == a){
            ChildPtr *p = tree.nodes[i].firstChild;
            p = p->next;
            while(p){
                hasKids = 1;
                printf("%c",tree.nodes[p->child].data);
                p = p->next;
            }
            break;
        }
    }
    if(hasKids==0){
        printf("no kids");
    }
}

void displayTree(CTree tree)
{

    for (int i = 0; i <tree.n ; ++i) {

        printf("%c",tree.nodes[i].data);
        ChildPtr *temp = tree.nodes[i].firstChild;
        temp = temp->next;
        while (temp){

            printf("%c of %d child is %c\n",tree.nodes[i].data,temp->child,tree.nodes[temp->child].data);

            temp = temp->next;
        }
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

    printf("show node\n");

    displayTree(tree);

    printf("find kids:");
    findKids(tree,'A');

    return 0;
}