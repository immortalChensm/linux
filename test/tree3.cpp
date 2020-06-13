//
// Created by Administrator on 2020/6/13.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
//双亲表示法
typedef char ElemType;

typedef struct Snode
{
    ElemType data;
    int parent;
}PNode;

typedef struct
{
    PNode tnode[MAX_SIZE];
    int n;
}PTree;

PTree InitPNode(PTree tree)
{
    int i,j;
    char ch;

    printf("node num:\n");
    scanf("%d",&(tree.n));

    printf("input data and parent :\n");

    for(i=0;i<tree.n;i++){
        getchar();

        scanf("%c %d",&ch,&j);

        tree.tnode[i].data = ch;
        tree.tnode[i].parent = j;
    }
    return tree;
}

void FindParent(PTree tree)
{
    char a;
    int isfind = 0;
    printf("input find data:\n");

    getchar();

    scanf("%c",&a);

    for (int i = 0; i <tree.n ; ++i) {

        if (tree.tnode[i].data == a){
            isfind = 1;
            int ad = tree.tnode[i].parent;
            printf("%c father is %c,pos %d\n",a,tree.tnode[ad].data,ad);
            break;
        }
    }

    if (isfind==0){
        printf("not found\n");
    }

}

int main()
{
    PTree tree;

    for (int i = 0; i < MAX_SIZE; ++i) {

        tree.tnode[i].data = ' ';
        tree.tnode[i].parent = 0;
    }

    tree = InitPNode(tree);
    FindParent(tree);

    return 0;
}