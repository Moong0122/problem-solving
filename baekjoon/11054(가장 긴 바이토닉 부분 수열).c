#include<stdio.h>
#include<string.h>

int cost[1001];
int dp[1001];
int compare[1001];
int main(){
	int n;
	int max = -1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
		dp[i] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=i;l++){
			for(int ll=1;ll<l;ll++){
				if(cost[l] > cost[ll] && dp[l] <= dp[ll])
					dp[l] = dp[ll] + 1;
			}
			if(dp[l] > max)
			max = dp[i];
		}
		for(int s=i;s<=n;s++){
			for(int ss=i;ss<s;ss++){
				if(cost[s] < cost[ss] && dp[s] <= dp[ss])
					dp[s] = dp[ss] + 1;
			}
			if(dp[s] > max)
			max = dp[s];
		}
		compare[i] = max;
		for(int r=1;r<=n;r++){
			dp[r]=1;
		}
		max = -1;
	}
	int mmax = compare[1];
	for(int i=2;i<=n;i++){
		if(compare[i] > mmax)
			mmax = compare[i];
	}
	printf("%d\n", mmax);
    return 0;
}



