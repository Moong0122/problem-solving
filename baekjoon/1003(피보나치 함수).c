#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int zero = 0, one = 0;
int arr[41];
int fibo(int number){
    if(number == 0){
        zero += 1;
        return 0;
    }if(number == 1){
        one += 1;
        return 1;
    }if(arr[number] != -1)
        return arr[number];
    
    return arr[number] = fibo(number-1) + fibo(number - 2);
}
int main(){
    int n,a;
    scanf("%d",&n);
    memset(arr, -1, sizeof(arr));
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        int total = fibo(a);
        printf("%d %d\n",zero,one);
        zero = one = 0;
    }
    return 0;
}