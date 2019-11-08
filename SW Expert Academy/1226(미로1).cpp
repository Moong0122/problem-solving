#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int maze[17][17];
int check_visit[17][17];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int answer;

void dfs(int inx,int iny,int fx,int fy);
void makeclear();
int main(){
	int input;

	while(1){
		cin >> input;
		string line;
		int start_i, start_j, target_i, target_j;
		for(int i=1;i<=16;i++){
			cin >> line;
			for(int j=1;j<=16;j++){
				maze[i][j] = line[j-1]-48;
				if(maze[i][j] == 2){
					start_i = i;
					start_j = j;
				}
				if(maze[i][j] == 3){
					target_i = i;
					target_j = j;
				}
			}
		}
		dfs(start_i,start_j,target_i,target_j);
		cout << "#" << input << " " << answer << endl;
		makeclear();
		if(input == 10)
			break;
	}
	return 0;
}
void dfs(int inx,int iny,int fx,int fy){
	check_visit[inx][iny] = 1;
	for(int i = 0;i<4;i++){
		int x = inx + dx[i];
		int y = iny + dy[i];
		if(x == fx && y == fy){
			answer = 1;
			return;
		}
		if(maze[x][y] == 0 && check_visit[x][y] == 0)
			dfs(x,y,fx,fy);
	}
}
void makeclear(){
	memset(maze,0,sizeof(maze));
	memset(check_visit,0,sizeof(check_visit));
	answer = 0;
}