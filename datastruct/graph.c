//
// Created by 1655664358@qq.com on 2020/3/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_VERtEX_NUM 20
#define VRType int
#define InfoType char
#define VerTexType char
typedef enum{DG=1,DN,UDG,UDN}GraphKind;

typedef struct {
    VRType adj;
    InfoType *info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
//arc 弧
//AdjMatrix 矩阵数组
//VerTex 顶点

//有向图：顶点间的关系 <v1,v2>方向是单向的  有向网：顶点间的弧有权值
//无向图：顶点间的关系(v1,v2)方向是双向的，无向网：顶点间的边有权值

typedef struct
{
    VerTexType vex[MAX_VERtEX_NUM][10];//顶点数组  存储每个顶点的值
    AdjMatrix arcs;//孤矩阵  存储顶点间的关系数组
    int vexnum,arcnum;//顶点数量，孤数量
    GraphKind kind;//图类型 图或是网【有向或是无向】
}MGraph;

int LocateVex(MGraph *G,VerTexType *v)
{
    int i=0;
    for (;i<G->vexnum;i++) {
        if (strcasecmp(G->vex[i],v)==0){
            break;
        }
    }
    if (i>G->vexnum){
        printf("not exist arc\n");
        return -1;
    }
    return i;
}
//有向图
void CreateDG(MGraph *G)
{
    printf("input vexnum and arcnum:\n");
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //printf("%d\n",G->vexnum);
   // printf("%d\n",G->arcnum);
    for (int i = 0; i <G->vexnum ; ++i) {
        //scanf("%s",&(G->vex[i]));
        char temp[10];
        scanf("%s",temp);
        strcpy(G->vex[i],temp);
    }

    for (int k = 0; k <G->vexnum ; ++k) {
        for (int i = 0; i <G->vexnum ; ++i) {
            G->arcs[k][i].adj=0;
            G->arcs[k][i].info="";
        }
    }
    printf("please input arc between vex:\n");
    //printf("%s\n",G->vex[0]);
    for (int j = 0; j <G->arcnum ; ++j) {
        char v1[5],v2[5];
        scanf("%s",v1);
        scanf("%s",v2);

        //printf("%s-%s\n",v1,v2);
        int n = LocateVex(G,v1);
        int m = LocateVex(G,v2);
        if (n==-1||m==-1){
            return;
        }
        //printf("m=%d-n=%d\n",m,n);
        G->arcs[n][m].adj=1;
    }
}

void PrintMGraph(MGraph *G)
{
    for (int i = 0; i <G->vexnum ; ++i) {
        for (int j = 0; j <G->vexnum ; ++j) {

            printf("%d",G->arcs[i][j].adj);
        }
        printf("\n");
    }
}
void CreateGraph(MGraph *G)
{

    printf("input mgraph kind\n");
    scanf("%d",&(G->kind));
    switch (G->kind){

        case DG:
            return CreateDG(G);
            break;
        case DN:
            break;
        case UDG:
            break;
        case UDN:
            break;
        default:
            break;
    }
}

int main()
{
    MGraph G;
    CreateGraph(&G);
    PrintMGraph(&G);
    return 0;
}