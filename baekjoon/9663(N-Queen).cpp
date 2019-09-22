#include<iostream>
#include<math.h>
using namespace std;

int n,total = 0;
void dfs(int pos, int* a);
bool ischeck(int pos,int col, int* a);

int main(){
	cin >> n;
	int chess[n];

	dfs(0,chess);
	cout << total << endl;
	return 0;
}
void dfs(int pos, int* a){
	if(pos == n){
		total++;
		return;
	}
	for(int i=0;i<n;i++){
		if(ischeck(pos,i,a)){
			a[pos] = i;
			dfs(pos+1,a);
			a[pos] = 0;
		}
	}
	return;
}
bool ischeck(int pos,int col, int* a){
	for(int i=0;i<pos;i++){
		if(a[i] == col)
			return false;
		if(abs(i-pos) == abs(a[i]-col))
			return false;
	}
	return true;
}