#include<stdio.h>

int graph[101][101];
int check_visit[101];
int queue[101];

void BFS(int start, int size);

int main(){
    int n,m,a,b,sum = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    BFS(1,n);
    for(int i = 1;i<=n;i++){
        sum += check_visit[i];
    }
    printf("%d\n", sum-1);
    //sum은 1번 컴퓨터를 포함하므로!
    return 0;
}
void BFS(int start, int size){
    int front = 0, rear = 0, pop, i;
    queue[rear] = start;
    rear++;
    check_visit[start] = 1;

    while(front<rear){
        pop = queue[front];
        front++;

        for(i = 1;i<=size;i++){
            if(graph[pop][i] == 1 && check_visit[i] == 0){
                queue[rear] = i;
                rear++;
                check_visit[i] = 1; //체크!!
            }
        }
    }
}