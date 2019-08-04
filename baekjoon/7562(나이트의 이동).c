#include<stdio.h>
#include<string.h>

typedef struct{
	int x;
	int y;
}pos;

pos P[90000];
int check_visit[301][301];
int dx[8] = {1,2,-1,-2,-1,-2,1,2};
int dy[8] = {2,1,2,1,-2,-1,-2,-1};
int front = 0, rear = 0;

void BFS(int x, int y, int end_x, int end_y, int len);
void Enqueue(int x, int y);
void makeclean();
pos Dequeue();

int main(){
	int n,side;
	int pox, poy, tar_x, tar_y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&side);
		scanf("%d%d",&pox, &poy);
		scanf("%d%d",&tar_x, &tar_y);
		BFS(pox, poy, tar_x, tar_y, side);
		printf("%d\n", check_visit[tar_x][tar_y]-1);
		// 첫 시작점을 1로 두고 시작하므로 -1을 해준다
		makeclean();
	}
}
void BFS(int x, int y, int end_x, int end_y, int len){
	pos tmp;
	Enqueue(x,y);
	check_visit[x][y] = 1;

	while(front < rear){
		tmp = Dequeue();
		if(tmp.x == end_x && tmp.y == end_y)
			break;
		for(int i=0;i<8;i++){
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if(xx>=0 && xx<len && yy>=0 && yy<len){
				if(check_visit[xx][yy]==0){
					check_visit[xx][yy] = check_visit[tmp.x][tmp.y] + 1;
					Enqueue(xx,yy);
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
	temp = P[front];
	front++;

	return temp;
}
void makeclean(){
	front = rear = 0;
	memset(check_visit,0,sizeof(check_visit));
}
