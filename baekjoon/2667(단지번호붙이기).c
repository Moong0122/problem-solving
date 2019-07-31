#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int graph[26][26];
int check_visit[26][26];
int number[170];
int cnt;

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
void DFS(int x,int y, int size);
int main(){
    int n;
    int temp = 0;
    char al[26]; //최대 25개까지 한줄에 쓸수 있으므로
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%s",al);
        for(int j=1;j<=n;j++){
            graph[i][j] = al[j-1] -'0'; // al배열은 0부터 시작하니까
            check_visit[i][j] = graph[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check_visit[i][j] == 0) // 벽이거나 이미 검사를 했거나
                continue;
            else{
                DFS(i,j,n);
                number[temp] = cnt;
                temp++;
                cnt = 0;
            }
        }
    }
    qsort(number,temp,sizeof(int),compare);

    printf("%d\n",temp);
    for(int i=0;i<temp;i++){
        printf("%d\n",number[i]);
    }
    return 0;
}
void DFS(int x, int y, int size){
    cnt++;
    check_visit[x][y] = 0;
    if(graph[x+1][y] == 1 && check_visit[x+1][y] == 1)
        //연결되어 있지만 아직 방문은 하지 않았다면 
        DFS(x+1,y,size);
    if(graph[x-1][y] == 1 && check_visit[x-1][y] == 1)
        DFS(x-1,y,size);
    if(graph[x][y+1] == 1 && check_visit[x][y+1] == 1)
        DFS(x,y+1,size);
    if(graph[x][y-1] == 1 && check_visit[x][y-1] == 1)
        DFS(x,y-1,size);
    return;
}
/*
 int dx[4] = {-1,1,0,0};
 int dy[4] = {0,0,1,-1};
 
 void DFS(int x, int y, int size){
 cnt++;
 check_visit[x][y] = 0;
 for(int i=0;i<4;i++){
 int xx = x+dx[i], yy = y+dy[i];
 if(graph[xx][yy] == 1 && check_visit[xx][yy] == 1)
 DFS(xx,yy,size);
 }
 return;
 }
 */
