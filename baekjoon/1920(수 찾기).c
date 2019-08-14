#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if(num1 < num2)
		return -1;
	if(num1 > num2)
		return 1;
	else
		return 0;
}
int search(int num,int size);
int A[100001];
int main(){
	int n,m,number;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	qsort(A,n,sizeof(int),compare);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&number);
		printf("%d\n",search(number,n));
	}
	return 0;
}
int search(int num, int size){
	int l,r,mid; 
	l = 0;
	r = size-1;

	if(num < A[l] || num > A[r])
		return 0;

	while(r>=l){
		mid = (l+r)/2;
		if(A[mid] == num)
			return 1;
		else if(num < A[mid]){
			r = mid -1;
		}
		else if(num > A[mid]){
			l = mid+1;
		}
	}
	return 0;
}
