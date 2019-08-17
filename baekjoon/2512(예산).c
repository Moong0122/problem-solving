#include<stdio.h>
#include<stdlib.h>

int cost[10001];
int compare(const void *a, const void *b);
int binarySearch(int target, int size);
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&cost[i]);
	}
	qsort(cost,n,sizeof(int),compare);
	scanf("%d",&m);
	printf("%d\n",binarySearch(m,n));
}
int compare(const void *a, const void *b){
	return *(int*)a > *(int*)b;
}
int binarySearch(int target, int size){
	int l,r,mid, total;
	r = cost[size-1];
	l = 0;

	while(l<=r){
		total = 0;
		mid = (r+l)/2;
		for(int i=0;i<size;i++){
			if(cost[i] < mid)
				total += cost[i];
			else
				total += mid;
		}
		if(total == target)
			return mid;
		else if(total > target)
			r = mid - 1;
		else if(total < target)
			l = mid + 1;
	}
	return r;
}