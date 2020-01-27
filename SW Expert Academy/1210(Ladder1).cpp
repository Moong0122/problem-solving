#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int ladder[100][100];
int check[100][100];
int startX;
void BFS(int y, int x);
int main(){
	for(int testCase = 1; testCase <= 10 ; testCase++){

		int a;
		cin >> a;
		int targetY, targetX;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				cin >> ladder[i][j];
				if(ladder[i][j] == 2){
					targetY = i;
					targetX = j;
				}
			}
		}
		// 입력 완료
		BFS(targetY, targetX);
		cout << "#" << testCase << " " << startX << endl;
		// 출력 완료
		memset(ladder,0,sizeof(ladder));
		memset(check,0,sizeof(check));

	}
	return 0;
}
void BFS(int y, int x){
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	check[y][x] = 1;

	while(!q.empty()){
		int yy = q.front().first;
		int xx = q.front().second;
		if(yy == 0){
			startX = xx;
			break;
		}
		q.pop();
		if(xx - 1 >= 0 && ladder[yy][xx-1] == 1 && check[yy][xx-1] == 0){
			q.push(make_pair(yy,xx-1));
			check[yy][xx-1] = 1;
			continue;
		}
		if(xx + 1 < 100 && ladder[yy][xx+1] == 1 && check[yy][xx+1] == 0){
			q.push(make_pair(yy,xx+1));
			check[yy][xx+1] = 1;
			continue;
		}
		if(yy-1 >= 0 && ladder[yy-1][xx] == 1 && check[yy-1][xx] == 0){
			q.push(make_pair(yy-1,xx));
			check[yy-1][xx] = 1;
			continue;
		}
	}
}
