#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[10001];
int dp[10001];
int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int getDP(int x){
    if(x<1)
        return 0;
    return dp[x];
}
int getCost(int x){
    if(x<1)
        return 0;
    return cost[x];    
}
int main(){
    int n, max = -1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        dp[i] = MAX(MAX(cost[i]+getDP(i-2), cost[i]+cost[i-1]+getDP(i-3)),cost[i-1]+getCost(i-2)+getDP(i-4));
    }
    printf("%d\n",dp[n]);
    return 0;
}