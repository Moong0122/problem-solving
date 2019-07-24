#include<stdio.h>

long dp[101][11];

int main(){
    int n;
    long sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1;j<=9;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    for(int i=0;i<=9;i++){
        sum += dp[n][i];
    }
    printf("%ld\n",sum % 1000000000);
    return 0;
}