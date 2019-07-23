#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int cost[100001];
int dp[100001];
int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int main(){
    int n, max = -1001;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        dp[i] = MAX(cost[i],dp[i-1]+cost[i]);
        if(dp[i] > max)
            max = dp[i];
    }
    printf("%d\n",max);
    return 0;
}
//수를 한개 이상 선택해야 한다
