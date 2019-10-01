#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int height[101][101];
bool check_visit[101][101];
void dfs(int x, int y,int limit);
int main(){
	int large = -1, result = -1, cnt;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> height[i][j];
			if(height[i][j] > large)
				large = height[i][j];
		}
	}
	int start=0;
	while(start <= large){
		cnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(height[i][j]>start && !check_visit[i][j]){
					dfs(i,j,start);
					cnt++;
				}
			}
		}
		if(cnt > result)
			result = cnt;
		memset(check_visit,false,sizeof(check_visit));
		start++;
	}
	cout << result << endl;
	return 0;
}
void dfs(int x, int y,int limit){
	check_visit[x][y] = true;
	for(int i=0;i<4;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx >= 1 && yy >= 1 && xx <= n && yy <= n){
			if(height[xx][yy] > limit && !check_visit[xx][yy])
				dfs(xx,yy,limit);
		}
	}
}
