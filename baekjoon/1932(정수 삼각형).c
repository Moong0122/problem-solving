#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[501][501];
int dp[501][501];
int max(int num1, int num2){
	return num1 > num2 ? num1 : num2;
}
int getDP(int x, int y){
	if(x<1 || y<1)
		return 0;
	else
		return dp[x][y];
}
int main(){
	int n;
	int bigest = -1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&cost[i][j]);
			dp[i][j] = max(getDP(i-1,j),getDP(i-1,j-1)) + cost[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[n][i] > bigest)
			bigest = dp[n][i];
	}
	printf("%d\n",bigest);

	return 0;
}
