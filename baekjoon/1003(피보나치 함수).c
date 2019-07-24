#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[41];

int main(){
    int n,a;
    scanf("%d",&n);
    dp[1] = 1;
    for(int i = 2;i<=40;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a == 0)
            printf("1 0\n");
        else
            printf("%d %d\n",dp[a-1],dp[a]);
    }
    return 0;
}