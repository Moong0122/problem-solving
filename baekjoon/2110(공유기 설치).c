#include<stdio.h>
#include<stdlib.h>

int wifi[200001];
int compare(const void *a, const void *b);
int binarySearch(int target, int size);
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%d",&wifi[i]);
	}
	qsort(wifi,n,sizeof(int),compare);
	printf("%d\n",binarySearch(c,n));
	return 0;
}
int compare(const void *a, const void *b){
	return *(int*)a > *(int*)b;
}
int binarySearch(int target, int size){
	int l,r,mid,start,cnt,ans;
	l = 1;
	r = wifi[size - 1];
	while(l<=r){
		cnt = 1;
		mid = (l+r)/2;
		start = wifi[0];
		for(int i=1;i<size;i++){
			if(wifi[i] - start >= mid){
				cnt++;
				start = wifi[i];
			}
		}
		if(cnt >= target){
			ans = mid;
			l = mid+1;
		}
		else if(cnt < target)
			r = mid-1;
	}
	return ans;
}