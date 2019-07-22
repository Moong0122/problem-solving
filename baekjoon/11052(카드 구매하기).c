#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int *dp;
int *cost;

int main(){
    int n;
    scanf("%d",&n);
    dp = (int*)malloc(sizeof(int)* (n+1));
    cost = (int*)malloc(sizeof(int)* (n+1));
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            dp[i] = MAX(cost[j]+dp[i-j],dp[i]);
        }
    }
    printf("%d\n",dp[n]);
    free(dp);
    free(cost);
    return 0;
}