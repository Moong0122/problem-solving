#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int graph[51][51];
int check_visit[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x, int y);

int main(){
    int t,n,m,k;
    int a,b,cnt = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&m,&n,&k); //가로, 세로, 위치 개수
        for(int i=0;i<k;i++){
            scanf("%d%d",&a,&b);
            graph[b][a] = 1;
            check_visit[b][a] = 1;
        } //위치 입력 완료
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check_visit[i][j] == 0)
                    continue;
                else{
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        cnt = 0;
    }
    return 0;
}
void DFS(int x, int y){
    int xx, yy;
    check_visit[x][y] = 0; //새로 들어왔으니까 0으로 바꿔준다
    for(int i=0;i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];
        if(graph[xx][yy] == 1 && check_visit[xx][yy] == 1)
            DFS(xx,yy);
    }
    return;
}
//segmentation fault -> 잘못된 참
