#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[12];
int main(){
    int n,a;
    scanf("%d",&n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<=11;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        printf("%d\n",dp[a]);
    }
    return 0;
}

