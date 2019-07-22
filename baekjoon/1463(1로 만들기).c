#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[1000001];
int MIN(int num1, int num2){
    return num1 < num2 ? num1 : num2;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0)
            dp[i] = MIN(dp[i/2]+1, dp[i]);
        if(i % 3 == 0)
            dp[i] = MIN(dp[i/3]+1, dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}