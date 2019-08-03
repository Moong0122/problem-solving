#include<stdio.h>
#include<string.h>

void DFS(int start, int size);
int map[101][101];
int answer[101];
int check_visit[101];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		DFS(i,n);
		for(int j=1;j<=n;j++){
			printf("%d ",check_visit[j]);
		}
		memset(check_visit,0,sizeof(check_visit));
		printf("\n");
	}
	return 0;
}
void DFS(int start, int size){
	for(int i=1;i<=size;i++){
		if(map[start][i] == 1 && check_visit[i] == 0){
			check_visit[i] = 1;
			DFS(i,size);
		}
	}
	return;
}
