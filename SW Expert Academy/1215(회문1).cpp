#include<iostream>
using namespace std;

char map[9][9];
int total;

void checkside(int start,int left,int right,int size);
void checkdown(int start,int left,int right,int size);

int main(){
	int n;
	for(int s=1;s<=10;s++){ // 총 10개의 테스트 케이스가 주어진다
		total = 0;
		cin >> n; // 회문의 길이
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin >> map[i][j];
			}
		}

		for(int i=1;i<=8;i++){
			for(int j=1;j<=(9-n);j++){
				checkside(i,j,j+(n-1),n);
				checkdown(i,j,j+(n-1),n);
			}
		}
		cout << "#" << s << " " << total << endl;
	}
	return 0;
}
void checkside(int start,int left,int right,int size){ //left, right 는 위치를 가리키는 포인터 역할이다
	bool flag = true;
	while(left <= right && flag){
		if(map[start][left] == map[start][right]){
			left++;
			right--;
		}else
			flag = false;
	}
	if(flag)
		total++;
}
void checkdown(int start,int left,int right,int size){ //left, right 는 위치를 가리키는 포인터 역할이다
	bool flag = true;
	while(left <= right && flag){
		if(map[left][start] == map[right][start]){
			left++;
			right--;
		}else
			flag = false;
	}
	if(flag)
		total++;
}