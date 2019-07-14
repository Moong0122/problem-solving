#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int **graph;

int main(){
    int n;
    scanf("%d",&n);
    graph = (int**)malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++){
        graph[i] = (int*)malloc(sizeof(int)*n);
        memset(graph[i],0,sizeof(int)*n);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}