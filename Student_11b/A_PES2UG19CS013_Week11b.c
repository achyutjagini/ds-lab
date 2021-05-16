#include<stdio.h>
#include "bfs.h"

int f=-1,r=-1;

void qInsert(int[],int);
int qDelete(int[]);
int qIsEmpty();
void bfs(int**,int,int,int[],int[]);

int check_path(int **graph, int n, int v, int u)
{
    int visited[n+1], q[n+1];
    bfs(graph,n,v,visited,q);
    return visited[u];
}

void qInsert(int q[], int v){
    q[++r]=v;
    if(qIsEmpty())f=0;
}

int qDelete(int q[]){
    int w=q[f];
    if(f==r)f=r=-1;
    else f++;
    return w;
}

int qIsEmpty(){
    return f==-1;
}

void bfs(int **graph, int n, int v, int visited[], int q[]){
    for(int i=0;i<n+1;i++)visited[i]=0;
    int w;
    visited[v]=1;
    qInsert(q,v);
    while(!qIsEmpty()){
        w=qDelete(q);
        for(int i=1;i<=n;i++){
            if(graph[w][i]==1 && visited[i]==0){
                visited[i]=1;
                qInsert(q,i);
            }
        }
    }
}

