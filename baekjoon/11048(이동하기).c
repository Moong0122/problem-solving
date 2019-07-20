#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[1001][1001];
int candy[1001][1001];
int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2 ;
}
int getDP(int x, int y){
    if(x < 1 || y < 1)
        return 0;
    return dp[x][y];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&candy[i][j]);
            dp[i][j] = MAX(MAX(getDP(i,j-1),getDP(i-1,j-1)),getDP(i-1,j)) + candy[i][j];
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}