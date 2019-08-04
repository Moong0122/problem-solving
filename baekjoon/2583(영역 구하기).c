#include<stdio.h>
#include<stdlib.h>

typedef struct pos{
    int x;
    int y;
}pos;

void draw(int a, int b, int c, int d);
void BFS(int x, int y);
void Enqueue(int x, int y);
int compare(const void *a, const void *b);
pos Dequeue();

int graph[101][101];
int check_visit[101][101];
int sort[10000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
pos P[10000];
int front = 0, rear = 0,cnt = 0;
int m,n;

int main(){
    int k,pos = 0;
    int a,b,c,d;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        draw(a,b,c,d);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j] == 0 && check_visit[i][j] == 0){
                BFS(i,j);
                sort[pos] = cnt;
                cnt = 0;
                pos++;
            }
        }
    }
    qsort(sort,pos,sizeof(int),compare);
    printf("%d\n",pos);
    for(int i=0;i<pos;i++){
        printf("%d ",sort[i]);
    }
}
void draw(int a, int b, int c, int d){
    for(int i=b+1;i<=d;i++){
        for(int j=a+1;j<=c;j++){
            graph[i][j] = 1;
        }
    }
}
void BFS(int x, int y){
    pos tmp;
    Enqueue(x,y);
    check_visit[x][y] = 1;
    cnt++;
    
    while(front < rear){
        tmp = Dequeue();
        for(int i=0;i<4;i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];
            if(xx > 0 && xx <= m && yy > 0 && yy <= n){
                if(graph[xx][yy] == 0 && check_visit[xx][yy] == 0){
                    Enqueue(xx,yy);
                    check_visit[xx][yy] = 1;
                    cnt++;
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
int compare(const void *a, const void *b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    if(num1 < num2)
        return -1;
    if(num1 > num2)
        return 1;
    else
        return 0;
}
