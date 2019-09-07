#include<iostream>
using namespace std;

int paper[129][129];
void check(int x, int y, int size);

int blue = 0;
int white = 0;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> paper[i][j];
		}
	}
	check(1,1,n);
	cout << white << endl;
	cout << blue << endl;
    return 0;
}
void check(int x, int y, int size){
	int color = paper[x][y];
	for(int i = x ; i < x+size ; i++){
		for(int j= y; j < y+size;j++){
			if(paper[i][j] != color){
				check(x,y,size/2);
				check(x+size/2,y,size/2);
				check(x,y+size/2,size/2);
				check(x+size/2,y+size/2,size/2);
				return;
			}
		}
	}
	if(color == 1)
		blue++;
	else
		white++;
}
