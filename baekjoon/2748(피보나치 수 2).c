#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long *arr;

long long fibo(int number){
	if(number == 0)
		return 0;
	if(number == 1)
		return 1;

	if(arr[number] != -1)
		return arr[number];

	arr[number] = fibo(number-1)+fibo(number-2);

	return arr[number];
}
int main(){
	int n;
	long long answer;
	scanf("%d",&n);
	arr = (long long*)malloc(sizeof(long long)*(n+1));
	memset(arr,-1,sizeof(long long)*(n+1));
	printf("%lld\n",fibo(n));	

	free(arr);
	return 0;
}
