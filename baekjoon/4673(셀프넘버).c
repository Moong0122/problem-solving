#include<stdio.h>

int arr[10001];

int main(){
	int num;
	for(int i=1;i<=10000;i++){
		arr[i] = 1;
	}
	for(int i=1;i<=10000;i++){
		int sum = 0,cnt = 0;

		if(arr[i] != 0)
			printf("%d\n",i);
		
		num = i;
		while(num != 0){
			sum += num % 10;
			num /=10;
		}
		arr[i+sum] = 0;
	}
	return 0;
}
