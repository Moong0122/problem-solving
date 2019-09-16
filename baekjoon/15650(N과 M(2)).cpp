#include<cstdio>
using namespace std;

int n,m;
bool check_visit[9];
int arr[9];

void DFS(int start, int pos){
	if(pos == m){
		for(int i=0;i<m;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=start;i<=n;i++){
		if(!check_visit[i]){
			check_visit[i] = true;
			arr[pos] = i;
			DFS(i,pos+1);
			check_visit[i] = false;
			arr[pos] = 0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	DFS(1,0);
	return 0;
}