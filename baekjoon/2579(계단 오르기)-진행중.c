#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost[301];
int dp[301];
int step[301];

int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    dp[1] = cost[1];
    dp[2] = cost[1]+cost[2];
    step[1] = step[2] = 2;
    for(int i=3;i<=n;i++){
        step[i] = i;
        if(step[i-1] == i-1 && step[i-2] == i-1){
            dp[i] = dp[i-2]+cost[i];
            step[i-2] = i;
        }
        else{
            dp[i] = MAX(dp[i-1],dp[i-2])+cost[i];
            if(dp[i-1] > dp[i-2])
                step[i-1] = i;
            else
                step[i-2] = i;
        }
    }
    printf("%d\n",dp[n]);
}
