#include<iostream>
using namespace std;

int n;
int mmax = -1000000000;
int mmin = 1000000000;

int number[12];
int buho[12];
int cal[12];
bool check[12];

void dfs(int pos);
void calculation(int pos, int num);
int main(){
	int a,start = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> number[i];
	}
	for(int i=1;i<=4;i++){
		cin >> a;
		for(int j=0;j<a;j++){
			buho[start++] = i;
		}
	}
	cal[0] = number[0];
	dfs(0);
	cout << mmax << endl << mmin << endl;
	return 0;
}
void dfs(int pos){
	if(pos == n-1){
		if(cal[pos] < mmin)
			mmin = cal[pos];
		if(cal[pos] > mmax)
			mmax = cal[pos];
		return;
	}
	for(int i=0;i<n-1;i++){
		if(!check[i]){
			check[i] = true;
			calculation(pos,i);
			dfs(pos+1);
			cal[pos+1] = 0;
			check[i] = false;
		}
	}
	return;
}
void calculation(int pos, int num){
	switch(buho[num]){
		case 1:
			cal[pos+1] = cal[pos] + number[pos+1];
			break;
		case 2:
			cal[pos+1] = cal[pos] - number[pos+1];
			break;
		case 3:
			cal[pos+1] = cal[pos] * number[pos+1];
			break;
		case 4:
			if(cal[pos] < 0){
				cal[pos+1] = -1 * cal[pos] / number[pos+1];
				cal[pos+1] *= -1;
			}
			else
				cal[pos+1] = cal[pos] / number[pos+1];
			break;
	}
}
