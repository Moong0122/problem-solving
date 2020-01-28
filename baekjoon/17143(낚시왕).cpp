#include<iostream>
#include<string.h>
using namespace std;
const int MAX = 101;

typedef struct{
	int spd, dir, size;
}fish_info;

fish_info fish[10001];
int sea[MAX][MAX];
int check[MAX][MAX];
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,1,-1};
int r,c,m,total_size;
void catchFish(int where);
void moveFish(int num, int y, int x);
int main(){
	cin >> r >> c >> m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin >> a >> b >> fish[i].spd >> fish[i].dir >> fish[i].size;
		sea[a][b] = i;
 	}
 	// 물고기 sea에 위치 완료
 	for(int person = 1 ; person <= c ; person++){
 		// 상어 잡기
 		catchFish(person);
 		// 상어 이동
 		for(int i=1;i<=r;i++){
 			for(int j=1;j<=c;j++){
 				if(sea[i][j] > 0)
 					moveFish(sea[i][j], i, j);
 			}
 		}
 		// 배열 복사
 		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				sea[i][j] = check[i][j];
			}
		}
		memset(check,0,sizeof(check));
		//
 	}
 	cout << total_size << endl;
 	return 0;
}
void catchFish(int where){
	for(int i=1;i<=r;i++){
		if(sea[i][where] > 0){
			total_size += fish[sea[i][where]].size;
			sea[i][where] = 0;
			break;
		}
	}
}
void moveFish(int num, int y, int x){
	int speed = fish[num].spd;
	int direction = fish[num].dir;
	int ssize = fish[num].size;
	int yy = dy[direction];
	int xx = dx[direction];

	// check배열에서 물고기 위치
	while(speed > 0){
		// 만약 다음에 이동할 칸의 범위가 벗어날 경우, 방향 전환시켜주기
		if(y+yy < 1 || y+yy > r || x+xx < 1 || x+xx > c){
			if(direction % 2 == 0)
				direction--;
			else
				direction++;
			fish[num].dir = direction;
			yy = dy[direction];
			xx = dx[direction];
		}
		// 이동
		y += yy;
		x += xx;
		speed--;
	}
	// check 배열에 물고기 위치시키기
	if(check[y][x] > 0){
		if(fish[check[y][x]].size < ssize)
			check[y][x] = num;
	}else
		check[y][x] = num;
}