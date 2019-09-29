#include<iostream>
#include<vector>
using namespace std;

int r,c;
int big = -1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char board[21][21];
vector<char> al;
void dfs(int goX, int goY,int pos);
bool check(char c);
int main(){
	cin >> r >> c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> board[i][j];
		}
	}
	dfs(1,1,0);
	cout << big+1 << endl;
	return 0;
}
void dfs(int goX, int goY,int pos){
	al.push_back(board[goX][goY]);

	for(int i=0;i<4;i++){
		int xx = goX + dx[i];
		int yy = goY + dy[i];
		if(xx > 0 && yy > 0 && xx <=r && yy <= c){
			if(check(board[xx][yy])){
			dfs(xx,yy,pos+1);
			al.pop_back();
			}
		}
	if(pos > big)
		big = pos;
	}
}
bool check(char c){
	int len = al.size();
	for(int i=0;i<len;i++){
		if(al[i] == c)
			return false;
	}
	return true;
}