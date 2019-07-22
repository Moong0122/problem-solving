#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MIN(int num1, int num2){
    return num1 < num2 ? num1 : num2;
}
int dp[1001];
int cost[1001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = MIN(cost[j]+dp[i-j],dp[i]);
            if(dp[i] == 0)
                dp[i] = cost[j]+dp[i-j];
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}