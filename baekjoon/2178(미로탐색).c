#include<stdio.h>

int graph[101][101];
int check_visit[101][101];
int dx[4] = {-1,1,0,0,}; 
int dy[4] = {0,0,1,-1}; 
int x[1000];
int y[1000];

void BFS(int num1, int num2);

int main(){
	int n,m;
	char al[101];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",al);
		for(int j=1;j<=m;j++){
			graph[i][j] = al[j-1] - '0';
		}
	}
	BFS(1,1);
	printf("%d\n",check_visit[n][m]);
	return 0;
}
void BFS(int num1, int num2){
	int front = 0, rear = 0, pop_x = 0, pop_y =0;
	x[rear] = num1;
	y[rear] = num2;
	rear++;
	check_visit[num1][num2] = 1;
	while(front < rear){
		pop_x = x[front];
		pop_y = y[front];
		front++;
		for(int i=0;i<4;i++){
			int xx = pop_x + dx[i];
			int yy = pop_y + dy[i];
			if(0<=xx && 0<=yy && graph[xx][yy] == 1 && check_visit[xx][yy] == 0){
				check_visit[xx][yy] = check_visit[pop_x][pop_y] + 1;
				x[rear] = xx;
				y[rear] = yy;
				rear++;
			}
		}
	}
}
