#include<iostream>
using namespace std;

int n,m;
int arr[9];
void dfs(int start, int pos){
	if(pos == m){
		for(int i=0;i<m;i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=start;i<=n;i++){
		arr[pos] = i;
		dfs(i,pos+1);
		arr[pos] = 0;
	}
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	dfs(1,0);
	return 0;
}