#include <vector>
#include <string>
using namespace std;

int cnt, n, m;
vector<vector<int> > k,l;

void spin(){
	// 벡터로 이루어진 이차원 배열 초기화 방법!
	vector<vector<int> > tmp(m,vector<int>(m,0));
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			tmp[j][m-i-1] = k[i][j];
	k = tmp;
}	

bool solution(vector<vector<int> > key, vector<vector<int> > lock)
{
	k = key; l = lock;
	m = k.size(); n = l.size();

	// lock배열에서 빈공간 개수 파악
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(l[i][j] == 0) cnt++;

	for(int r=0;r<4;r++){
		// 회전
		for(int i=-20;i<=20;i++){
			for(int j=-20;j<=20;j++){
				int count = 0, fail = 0;
				for(int y=0;y<m;y++){
					for(int x=0;x<m;x++){
						int dy = i+y, dx = j+x;
						if(dy >= 0 && dx >= 0 && dy < n && dx < n){
							if(l[dy][dx] == 1 && k[y][x] == 1) fail = 1;
							else if(l[dy][dx] == 0 && k[y][x] == 1) count++;
						}
					}
				}
				if(count == cnt && fail == 0) return true;
			}
		}
		spin();
		//
	}
	return false;
}
