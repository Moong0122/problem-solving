#include<iostream>
using namespace std;

int map[65][65];
void check(int x, int y, int size);
int main(){
	int n;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		for(int j=0;j<n;j++){
			map[i][j+1] = s[j] - 48;
		}
	}
	check(1,1,n);
	return 0;
}
void check(int x, int y, int size){
	int color = map[x][y];
	for(int i=x;i<x+size;i++){
		for(int j=y;j<y+size;j++){
			if(color != map[i][j]){
				cout << "(";
				check(x,y,size/2);
				check(x,y+size/2,size/2);
				check(x+size/2,y,size/2);
				check(x+size/2,y+size/2,size/2);
				cout << ")";
				return;
			}
		}
	}
	if(color == 0)
		cout << "0";
	else
		cout << "1";
}


//void quadTree(int x, int y, int size){
//    int color = map[x][y];
//    bool flag = true;
//    for(int i=x;(i<x+size)&&flag;i++){
//        for(int j=y;(j<y+size)&&flag;j++){
//            if(color != map[i][j])
//                flag = false; // 이제 이 포문을 바로 빠져나올 수 있게 된다
//        }
//    }
//    if(flag)
//        cout << color;
//    else{
//        cout << "(";
//        check(x,y,size/2);
//        check(x,y+size/2,size/2);
//        check(x+size/2,y,size/2);
//        check(x+size/2,y+size/2,size/2);
//        cout << ")";
//    }
//}
