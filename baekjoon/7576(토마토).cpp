#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m,n; //가로 세로
int tomato[1001][1001];
int check_vist[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int> > checkOne;
void dfs();
int main(){
	int checkZero = 0;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> tomato[i][j];
			if(tomato[i][j] == 0)
				checkZero++;
			if(tomato[i][j] == 1)
				checkOne.push(make_pair(i,j));
		}
	}
	if(checkZero == 0)
		cout << 0 << endl;
	else{
		dfs();
		int big = 0;
		bool notTomato = false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(tomato[i][j] == 0 && check_vist[i][j] > big)
					big = check_vist[i][j];
				if(tomato[i][j] == 0 && check_vist[i][j] == 0){
					notTomato = true;
					break;
				}
			}
		}
		if(notTomato)
			cout << -1 << endl;
		else
			cout << big << endl;
	}
	return 0;
}
void dfs(){
	pair<int,int> p;
	while(!checkOne.empty()){
		p = checkOne.front();
		checkOne.pop();
		for(int i=0;i<4;i++){
			int xx = p.first + dx[i];
			int yy = p.second + dy[i];
			if(xx > 0 && xx <= n && yy > 0 && yy <=m){
				if(tomato[xx][yy] == 0 && check_vist[xx][yy] == 0){
					check_vist[xx][yy] = check_vist[p.first][p.second] + 1;
					checkOne.push(make_pair(xx,yy));
				}
			}
		}
	}
}
