#include<stdio.h>
#include<stdlib.h>

int tree[1000001];
int compare(const void *a, const void *b);
int binarySearch(long long target, int size);
int main(){
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&tree[i]);
	}
	qsort(tree,n,sizeof(int),compare);
	printf("%d\n",binarySearch(m,n));
}
int compare(const void *a, const void *b){
	return *(int*)a > *(int*)b;
}
int binarySearch(long long target, int size){
	int r,l,mid,ans = 0;
	long long len = 0;
	r = tree[size-1];
	l = 0;

	while(l<=r){
		len = 0;
		mid = (r+l)/2;
		for(int i=0;i<size;i++){
			if(mid > tree[i])
				continue;
			len += (tree[i] - mid);
		}
		if(len == target)
			return mid;
		else if(len < target)
			r = mid -1;
		else if(len > target)
			l = mid +1;
	}
	return r;
}
