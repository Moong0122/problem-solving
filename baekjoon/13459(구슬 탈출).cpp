#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct{
	int cnt,
		rx,
		ry,
		bx,
		by;
}pos;

bool goalRed, goalBlue;
int n,m, answer = -1;
char board[11][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
queue<pos> q;
void bfs();
pair<int,int> movingBall(char c, pos P, int mx, int my);
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	pos p;
	p.cnt = 0;

	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> board[i][j];
			if(board[i][j] == 'R'){
				p.rx = i;
				p.ry = j;
			}
			if(board[i][j] == 'B'){
				p.bx = i;
				p.by = j;
			}
		}
	}
	q.push(p);
	bfs();
	if(answer != -1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
void bfs(){
	bool out = false;
	while(!q.empty()){
		pos tmp = q.front();
		q.pop();

		if(tmp.cnt == 10)
			break;

		// 상, 하, 우, 좌
		for(int i=0;i<4;i++){
			pos nextState;
			goalRed = false;
			goalBlue = false;
			nextState.cnt = (tmp.cnt+1);
			pair<int,int> red = movingBall('R',tmp,dx[i],dy[i]);
			pair<int,int> blue = movingBall('B',tmp,dx[i],dy[i]);

			if(goalRed && !goalBlue){
				out = true;
				answer = nextState.cnt;
				break;
			}else if(!goalRed && !goalBlue){
				nextState.rx = red.first;
				nextState.ry = red.second;			
				nextState.bx = blue.first;
				nextState.by = blue.second;				
				q.push(nextState);
			}
		}
		if(out)
			break;
	}
}
pair<int,int> movingBall(char c, pos P, int mx, int my){
	int sx,sy;
	bool block = false;

	if(c == 'R'){
		sx = P.rx;
		sy = P.ry;
	}else if(c == 'B'){
		sx = P.bx;
		sy = P.by;
	}

	while(board[sx + mx][sy + my] != '#'){
		sx += mx;
		sy += my;
		if(c == 'R' && sx == P.bx && sy == P.by)
			block = true;
		else if(c == 'B' && sx == P.rx && sy == P.ry)
			block = true;

		if(c == 'R' && board[sx][sy] == 'O')
			goalRed = true;
		else if(c == 'B' && board[sx][sy] == 'O')
			goalBlue = true;
	}

	if(block){
		sx -= mx;
		sy -= my;
	}

	pair<int,int> temp = make_pair(sx,sy);
	return temp;
}