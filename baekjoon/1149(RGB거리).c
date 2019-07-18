#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[1001][4];
int dp[1001][4];

int MIN(int num1, int num2){
	return num1 < num2 ? num1 : num2;
}
int main(){
	int n, min;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&cost[i][j]);
		}
		dp[i][1] = MIN(dp[i-1][2],dp[i-1][3])+cost[i][1];
		dp[i][2] = MIN(dp[i-1][1],dp[i-1][3])+cost[i][2];
		dp[i][3] = MIN(dp[i-1][1],dp[i-1][2])+cost[i][3];
	}
	min = dp[n][1];
	for(int i=2;i<=3;i++){
		if(dp[n][i] < min)
			min = dp[n][i];
	}
	printf("%d\n",min);
	return 0;
}
