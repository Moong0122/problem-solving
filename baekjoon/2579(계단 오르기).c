#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[301];
int dp[301];

int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int getDP(int x){
    if(x < 1)
        return 0;
    else
        return dp[x];
}
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        dp[i] = MAX(cost[i]+getDP(i-2),cost[i]+cost[i-1]+getDP(i-3));
    }
    printf("%d\n",dp[n]);
}
