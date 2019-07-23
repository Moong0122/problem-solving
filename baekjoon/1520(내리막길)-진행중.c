#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[501][501];
int dp[501][501];

int getDP(int x, int y){
    if(cost[x][y] < cost[x+1][y])
        dp[x][y] += dp[x+1][y];
    if(cost[x][y] < cost[x][y+1])
        dp[x][y] += dp[x][y+1];
    if(cost[x][y] < cost[x][y-1])
        dp[x][y] += dp[x][y-1];
    if(cost[x][y] < cost[x-1][y])
        dp[x][y] += dp[x-1][y];
    
    return dp[x][y];
}
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("------------------------------\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 && j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = getDP(i,j);
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
