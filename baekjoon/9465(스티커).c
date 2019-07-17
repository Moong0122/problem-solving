#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[2][100001], cost[2][100001];
int Max(int num1, int num2){
	return num1 > num2 ? num1 : num2 ;
}
int getDP(int x,int y){
	if(x<0 || y<1)
		return 0;
	else
		return dp[x][y];
}
int main(){
	int n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		for(int i=0;i<2;i++){
			for(int j=1;j<=a;j++){
				scanf("%d",&cost[i][j]);
			}
		}
		for(int i=1;i<=a;i++){
			dp[0][i] = Max(getDP(1,i-1),getDP(1,i-2))+cost[0][i];
			dp[1][i] = Max(getDP(0,i-1),getDP(0,i-2))+cost[1][i];
		}
		printf("%d\n",Max(dp[0][a],dp[1][a]));
		memset(dp,0,sizeof(dp));
		memset(cost,0,sizeof(cost));
	}

	return 0;
}
