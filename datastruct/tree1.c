//
// Created by 1655664358@qq.com on 2020/3/11.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX 20
typedef struct{
    char data;
    int parent;
}PTNode;

typedef struct{
    PTNode node[MAX];
    int n;
}PTree;

PTree initTree(PTree tree)
{
    int i,j;
    char ch;

    printf("node number:\n");
    scanf("%d",&(tree.n));

    for (i = 0;  i<tree.n ; i++) {

        getchar();
        scanf("%c %d",&ch,&j);
        tree.node[i].data=ch;
        tree.node[i].parent=j;
    }

    return tree;
}

void findNode(PTree tree)
{
    char a;
    int isfind=0;
    printf("find data\n");
    getchar();
    scanf("%c",&a);

    for (int i = 0; i <tree.n ; ++i) {

        if (tree.node[i].data==a){
            isfind = 1;
            int ad = tree.node[i].parent;
            printf("%c father is :%c,position is:%d\n",tree.node[i].data,tree.node[ad].data,ad);
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


    for (int i = 0; i <MAX ; ++i) {
        tree.node[i].data = ' ';
        tree.node[i].parent=0;
    }

    tree = initTree(tree);
    findNode(tree);
    return 0;
}