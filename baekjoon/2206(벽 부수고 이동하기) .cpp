#include<iostream>
#include<queue>
using namespace std;

typedef struct{
	int x,y,w;
}map;

int n,m;
int mmap[1001][1001];
int dist[1001][1001][2];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int bfs();
void pushElement(int a, int b, int c);
queue<map> q;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for(int i=1;i<=n;i++){
		string str;
		cin >> str;
		for(int j=1;j<=m;j++){
			mmap[i][j] = str[j-1] - 48;
		}
	}
	cout << bfs() << endl;
	return 0;
}
int bfs(){
	pushElement(1,1,0);
	dist[1][1][0] = 1;

	while(!q.empty()){
		int x = q.front().x, y =q.front().y, w = q.front().w;
		q.pop();

		if(x == n && y == m)
			return dist[x][y][w];

		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx>=1 && yy>=1 && xx<=n && yy<= m && dist[xx][yy][w] == 0){
				if(mmap[xx][yy] == 0){
					dist[xx][yy][w] = dist[x][y][w] + 1;
					pushElement(xx,yy,w);
				}
				if(mmap[xx][yy] == 1 && w == 0){
					dist[xx][yy][1] = dist[x][y][w] + 1;
					pushElement(xx,yy,1);
				}
			}
		}
	}
	return -1;
}
void pushElement(int a, int b, int c){
	map tmp;
	tmp.x = a;
	tmp.y = b;
	tmp.w = c;
	q.push(tmp);
}
