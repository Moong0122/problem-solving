#include<iostream>
#include<queue>
using namespace std;

typedef struct{
	int x;
	int y;
}location;

int graph[50][50];
int check_visit[50][50];
location l[2501];
int front, rear;
int dx[8] = {-1,1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};
location L[2501];

void BFS(int x, int y, int h, int w);
void Enqueue(int x, int y);
void makeclear(int h, int w);
location Dequeue();

int main(){
	int w,h,cnt;
	cin >> w >> h;

	while(w != 0 && h != 0){
		front = 0;
		rear = 0;
		cnt = 0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				cin >> graph[i][j];
			}
		}
		//입력완료
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(graph[i][j] == 1 && check_visit[i][j] == 0){
					BFS(i,j,h,w);
					cnt++;
				}
			}
		}
		//BFS 확인 완료
		cout << cnt << endl;
		makeclear(h, w);
		cin >> w >> h;
	}
}
void BFS(int x, int y, int h, int w){
	location temp;

	Enqueue(x,y);
	check_visit[x][y] = 1;

	while(front < rear){
		temp = Dequeue();
		for(int i=0;i<8;i++){
			int xx = temp.x + dx[i];
			int yy = temp.y + dy[i];
			if(xx > 0 && yy > 0 && xx <=h && yy <=w){
				if(graph[xx][yy] == 1 && check_visit[xx][yy] == 0){
					check_visit[xx][yy] = 1;
					Enqueue(xx,yy);
				}
			}
		}
	}
}
void Enqueue(int x, int y){
	l[rear].x = x;
	l[rear].y = y;
	rear++;
}
location Dequeue(){
	location tmp;
	tmp.x = l[front].x;
	tmp.y = l[front].y;
	front++;

	return tmp;
}
void makeclear(int h, int w){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			graph[i][j] = 0;
			check_visit[i][j] = 0;
		}
	}
}


// 다른 방법!
//void DFS(int x, int y, int h, int w){
//    check_visit[x][y] = 1;
//
//    for(int i=0;i<8;i++){
//        int xx = x + dx[i];
//        int yy = y + dy[i];
//        if(xx > 0 && yy > 0 && xx < h && yy < w){
//            if(graph[xx][yy] == 1 && check_visit[xx][yy] == 0)
//                DFS(xx,yy);
//        }
//    }
//}
