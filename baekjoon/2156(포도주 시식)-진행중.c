#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[10001];
int grape[10001];

int MAX(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}
int getDP(int x){
    if(x<1)
        return 0;
    else
        return dp[x];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&grape[i]);
        dp[i] = MAX((getDP(i-2)+grape[i]), (getDP(i-3)+grape[i-1]+grape[i]));
        grape[i] = 0;
    }
    printf("%d\n",dp[n]);
}
