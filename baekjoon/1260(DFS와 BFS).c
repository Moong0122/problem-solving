#include<stdio.h>
#include<string.h>

int graph[1001][1001];
int check_visit[1001];
int queue[1001];

void DFS(int visit, int size);
void BFS(int visit, int size);

int main(){
    int a,b;
    int n,m,v;
    scanf("%d%d%d",&n,&m,&v);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    DFS(v,n);
    printf("\n");
    memset(check_visit,0,sizeof(check_visit));
    BFS(v,n);
    printf("\n");
    return 0;
}
void DFS(int visit, int size){
    int i;
    check_visit[visit] = 1;
    printf("%d ", visit);

    for(i = 1;i<=size;i++){
        if(graph[visit][i] == 1 && check_visit[i] == 0)
            DFS(i,size);
    }
    return;
}
void BFS(int visit, int size){
    int front = 0, rear = 0,i,pop;
    //
    queue[rear] = visit;
    check_visit[visit] = 1;
    rear++;
    //
    printf("%d ", visit);

    while(front < rear){
        pop = queue[front];
        front++;

        for(i = 1;i<=size;i++){
            if(graph[pop][i] == 1 && check_visit[i] == 0){
                printf("%d ", i);
                queue[rear] = i;
                rear++;
                check_visit[i] =1 ;
            }
        }
    }
    return;
}