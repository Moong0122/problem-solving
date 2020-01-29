#include<iostream>
using namespace std;

int n,m,h,ans = 4;
bool grid[31][11];

bool ladder();
void solve(int level, int x, int y);
int main(){
	cin >> n >> m >> h;
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		grid[a][b] = 1;
	}
	solve(0,0,0);
	if(ans < 4) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
bool ladder(){
	for(int i=1;i<=n;i++){
		// i번째 세로줄을 나타내는 k
		int k=i;
		// for문을 통해서 사다리를 타고 밑으로 내려가는 것을 구현
		for(int j=1;j<=h;j++){
			if(grid[j][k]) k+=1;
			else if(k>1 && grid[j][k-1]) k -=1;
		}
		if(i != k) return false;
	}
	return true;
}
void solve(int level, int x, int y){
	if(ans <= level) return;
	if(ladder()){
		if(ans > level) ans = level;
		return;
	}
	if(level == 3) return;
	for(int i=x;i<=h;i++,y=1){
		for(int j=y;j<=n-1;j++){
			if(grid[i][j]){
				j+=1;
			}else{
				grid[i][j] = 1;
				solve(level+1,i,j+2);
				grid[i][j] = 0;
			}
		}
	}
}
