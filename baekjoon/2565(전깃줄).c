#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int a;
	int b;
}point;

int dp[101];
point P[101];

int compare(const void *x, const void *y){
	if(((point*)x)->a > ((point*)y)->a)
		return 1;
	if(((point*)x)->a < ((point*)y)->a)
		return -1;
	else
		return ((point*)x)->b > ((point*)y)->b;
}
int main(){
	int n,max = -1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&P[i].a,&P[i].b);
	}
	qsort(P,n,sizeof(point),compare);
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(P[i].b > P[j].b && dp[i] <= dp[j])
				dp[i] = dp[j]+1;
		}
		if(dp[i] > max)
			max = dp[i];
	}
	printf("%d\n", n-max);
    return 0;
}
