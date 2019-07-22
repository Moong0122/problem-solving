#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[1001];
int dp[1001];

int main(){
    int n, max = -1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(cost[i] < cost[j] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
        if(dp[i] > max)
            max = dp[i];
    }
    printf("%d\n",max);
    return 0;
}
