#include<stdio.h>
#include<string.h>

typedef struct{
    int x;
    int y;
}pos;

void BFS(int x, int y, char color, int size);
void Enqueue(int x, int y);
pos Dequeue();
void makeclear();

pos P[10000];
char graph[101][101];
int check_visit[101][101];

int dx[4] = {-1,1,0,0,};
int dy[4] = {0,0,-1,1};
int front = 0, rear = 0;

int main(){
    int n,part = 0,part_RG = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&graph[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check_visit[i][j] == 1)
                continue;
            else{
                BFS(i,j,graph[i][j],n);
                part++;
            }
        }
    }
    makeclear();
    for(int i = 1; i<=n ;i++){
        for(int j = 1; j<=n ;j++){
            if(graph[i][j] == 'R')
                graph[i][j] = 'G';
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check_visit[i][j] == 1)
                continue;
            else{
                BFS(i,j,graph[i][j],n);
                part_RG++;
            }
        }
    }
    printf("%d %d\n",part, part_RG);
    return 0;
}
void BFS(int x, int y, char color, int size){
    pos Tmp;
    Enqueue(x,y);
    check_visit[x][y] = 1;
    while(front<rear){
        Tmp = Dequeue();
        for(int i=0;i<4;i++){
            int xx = Tmp.x + dx[i];
            int yy = Tmp.y + dy[i];
            if(xx>0 && xx<=size && yy>0 && yy<=size){
                if(graph[xx][yy] == color && check_visit[xx][yy] == 0){
                    Enqueue(xx,yy);
                    check_visit[xx][yy] = 1;
                }
            }
        }
    }
}
void Enqueue(int x, int y){
    P[rear].x = x;
    P[rear].y = y;
    rear++;
}
pos Dequeue(){
    pos temp;
    temp.x = P[front].x;
    temp.y = P[front].y;
    front++;
    return temp;
}
void makeclear(){
    front = rear = 0;
    memset(check_visit,0,sizeof(check_visit));
}
