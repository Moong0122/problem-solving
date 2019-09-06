#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
using namespace std;

int ice[301][301];
int icecheck[301][301];
int check_visit[301][301];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void ice_check(int h, int w);
void BFS(int x, int y, int h, int w);
void makeclear();
int main(){
	int h,w;
	cin >> h >> w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> ice[i][j];
		}
	}
	int zero,cnt = 0;
	int year = 0;

	while(1){
		zero = 0;
		cnt = 0;
		year++;
		ice_check(h,w);
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(ice[i][j] == 0){
					zero++;
					continue;
				}
				ice[i][j] -= icecheck[i][j];
				if(ice[i][j] < 0){
					ice[i][j] = 0;
					zero++;
				}
			}
		}
		// 얼음 제거 과정 완료
		for(int i=2;i<=h;i++){
			for(int j=2;j<=w;j++){
				if(ice[i][j] !=0 && check_visit[i][j] == 0){
					BFS(i,j,h,w);
					cnt++;
				}
			}
		}
		if(cnt >=2 || zero == h*w)
			break;
		makeclear();
	}
	if(zero == h*w)
		cout << "0" << endl;
	else
		cout << year << endl;
    return 0;
}
void ice_check(int h, int w){
	for(int i=2;i<=h;i++){
		for(int j=2;j<=w;j++){
			for(int k = 0;k<4;k++){
				int xx = i + dx[k];
				int yy = j + dy[k];
				if(ice[xx][yy] == 0)
					icecheck[i][j]++;
			}
		}
	}
}
void BFS(int x, int y, int h, int w){
	pair <int, int> p;

	queue < pair<int, int> > q;
	check_visit[x][y] = 1;
	q.push(make_pair(x,y));

	while(!q.empty()){
		p = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx = p.first + dx[i];
			int yy = p.second + dy[i];
			if(ice[xx][yy] != 0 && check_visit[xx][yy] == 0){
				q.push(make_pair(xx,yy));
				check_visit[xx][yy] = 1;
			}
		}
	}
}
void makeclear(){
	memset(check_visit,0,sizeof(check_visit));
	memset(icecheck,0,sizeof(icecheck));
}


//다른 방법(DFS)
//void DFS(int x, int y, int h, int w){
//    check_visit[x][y] = 1;
//    for(int i=0;i<4;i++){
//        int xx = x + dx[i];
//        int yy = y + dy[i];
//        if(ice[xx][yy] != 0 && check_visit[xx][yy] == 0)
//            DFS(xx, yy, h,w);
//    }
//}
