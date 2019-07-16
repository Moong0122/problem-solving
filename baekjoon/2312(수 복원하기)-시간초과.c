#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printDivide(int number);
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		printDivide(a);
	}
	return 0;
}
void printDivide(int number){
	int i = 2;
	while(number!=1){
		int times = 0;
		while(1){
			if(number % i == 0){
				number /= i;
				times ++;
			}else
				break;
		}
		if(times == 0)
			continue;
		else
			printf("%d %d\n",i,times);
		i++;
	}
}