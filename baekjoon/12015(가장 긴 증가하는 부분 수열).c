#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[1000001];
int dp[1000001];
int main(){
    int n, lower_bound = 0;
    scanf("%d",&n);
    memset(dp,1000001,sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        if(dp[lower_bound] < cost[i])
            dp[++lower_bound] = cost[i];
        else if(cost[i] < dp[lower_bound]){
            int l = 0;
            int r = lower_bound;
            int mid = 0;
            while(l<r){
                mid = (l+r) / 2;
                if(dp[mid] < cost[i])
                    l = mid + 1;
                else
                    r = mid;
            }
            dp[r] = cost[i];
        }
    }
    printf("%d\n",lower_bound + 1);
    return 0;
}