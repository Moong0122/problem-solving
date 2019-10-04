#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct {
	int hh;
	int d;
	int s;
}location;

queue<location> q;
int m,n,h;
int checkZero = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int dz[2] = {-1,1};
int tomato[101][101][101];
int check[101][101][101];
void bfs();
void make_push(int height, int up, int side);
int main(){
	cin >> m >> n >> h;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin >> tomato[i][j][k]; // 높이(h) 세로(n) 가로(m)
				if(tomato[i][j][k] == 0)
					checkZero++;
				if(tomato[i][j][k] == 1){
					location L;
					make_push(i,j,k);
				}
			}
		}
	}
	if(checkZero == 0)
		cout << 0 << endl;
	else{
		bool find = false;
		bfs();
		int big = -1;
			for(int i=0;i<h;i++){
				for(int j=0;j<n;j++){
					for(int k=0;k<m;k++){
						if(check[i][j][k] > big)
							big = check[i][j][k];
						if(check[i][j][k] == 0 && tomato[i][j][k] == 0){
							find = true;
							break;
						}
					}
					if(find)
						break;
				}
				if(find)
					break;
			}
		if(find)
			cout << -1 << endl;
		else
			cout << big << endl;
	}
	return 0;
}
void bfs(){
	location tmp;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx = tmp.d + dx[i];
			int yy = tmp.s + dy[i];
			if(xx>=0 && yy >=0 && xx<n && yy<m && check[tmp.hh][xx][yy] == 0 && tomato[tmp.hh][xx][yy] == 0){
				make_push(tmp.hh,xx,yy);
				check[tmp.hh][xx][yy] = check[tmp.hh][tmp.d][tmp.s] + 1;
			}
		}
		for(int i=0;i<2;i++){
			int zz = tmp.hh + dz[i];
			if(zz>=0 && zz<h && check[zz][tmp.d][tmp.s] == 0 && tomato[zz][tmp.d][tmp.s] == 0){
				make_push(zz,tmp.d,tmp.s);
				check[zz][tmp.d][tmp.s] = check[tmp.hh][tmp.d][tmp.s] + 1;
			}
		}
	}
}
void make_push(int height, int up, int side){
	location l;
	l.hh = height;
	l.d = up;
	l.s = side;
	q.push(l);
}
