#include<cstdio>
using namespace std;

int n,m;
int arr[8];

void dfs(int pos){
	if(pos == m){
		for(int i=0;i<m;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){ // 1부터 n까지의 자연수를 확인하면서
		arr[pos] = i;
		dfs(pos+1);
		arr[pos] = 0;
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	dfs(0);
	return 0;
}
