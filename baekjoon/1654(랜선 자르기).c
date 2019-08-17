#include<stdio.h>
#include<stdlib.h>

int len[1000001];
int compare(const void *a, const void *b);
long long binarySearch(int target, int size);
int main(){
	int k,n; // 4 11
	scanf("%d%d",&k,&n);
	for(int i=0;i<k;i++){
		scanf("%d",&len[i]);
	}
	qsort(len,k,sizeof(int),compare);
	printf("%lld\n",binarySearch(n,k));
}
int compare(const void *a, const void *b){
	return *(int*)a > *(int*)b;
}
long long binarySearch(int target, int size){
	long long l,r,mid,divide,answer;
	l = 1;
	r = len[size-1];

	while(l<=r){
		divide = 0;
		mid = (l+r)/2;
		for(int i=0;i<size;i++){
			divide += (len[i]/mid);
		}
		if(divide >= target){
			answer = mid;
			l = mid+1;
		}
		else if(divide < target)
			r = mid-1;
	}
	return answer;
}