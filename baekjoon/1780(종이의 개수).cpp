#include<iostream>
using namespace std;

int map[2400][2400];
void check(int x, int y, int size);
int oneminus = 0;
int zero = 0;
int one = 0;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> map[i][j];
		}
	}
	check(1,1,n);
	cout << oneminus << endl << zero << endl << one << endl;
	return 0;
}
void check(int x, int y, int size){
	int color = map[x][y];
	bool flag = true;
	for(int i=x;(i<x+size)&&flag;i++){
		for(int j=y;(j<y+size)&&flag;j++){
			if(color != map[i][j])
				flag = false;
		}
	}
	if(flag){
		if(color == -1)
			oneminus++;
		else if(color == 0)
			zero++;
		else
			one++;
	}else{
		int len = size/3;
		check(x,y,len);
		check(x,y+len,len);
		check(x,y+2*len,len);
		check(x+len,y,len);
		check(x+len,y+len,len);
		check(x+len,y+2*len,len);
		check(x+2*len,y,len);
		check(x+2*len,y+len,len);
		check(x+2*len,y+2*len,len);
	}
}
