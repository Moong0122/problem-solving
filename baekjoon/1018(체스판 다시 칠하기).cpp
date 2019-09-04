#include<iostream>
#include<vector>
using namespace std;

vector <int> v;
char chass[51][51];

void firstwhite(int x, int y);
void firstblack(int x, int y);

int main(){
	int n,m;
	string s;
	cin >> n >> m;

	for(int i=0;i<n;i++){
		cin >> s;
		for(int j=0;j<m;j++){
			chass[i][j] = s[j];
		}
	}
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			firstwhite(i,j);
			firstblack(i,j);
		}
	}
	int len = v.size();
	int min = v[0];
	for(int i=1;i<len;i++){
		if(v[i] < min)
			min = v[i];
	}
	cout << min << endl;
	return 0;
}
void firstwhite(int x, int y){
	int cnt = 0;
	for(int i=x;i<x+8;i++){
		for(int j=y;j<y+8;j++){
			if((i+j)%2 == 0 && chass[i][j] == 'B')
				cnt++;
			else if((i+j)%2 == 1 && chass[i][j] == 'W')
				cnt++;
		}
	}
	v.push_back(cnt);
}
void firstblack(int x, int y){
	int cnt = 0;
	for(int i=x;i<x+8;i++){
		for(int j=y;j<y+8;j++){
			if((i+j)%2 == 0 && chass[i][j] == 'W')
				cnt++;
			else if((i+j)%2 == 1 && chass[i][j] == 'B')
				cnt++;
		}
	}
	v.push_back(cnt);
}
