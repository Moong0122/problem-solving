#include<stdio.h>
#include<stdlib.h>

int arr[10];
int main(){
    int n;
    scanf("%d",&n);
    while(1){
        if(n == 0)
            break;
        arr[n%10]++;
        n /= 10;
    }
    for(int i=9;i>=0;i--){
        while(arr[i] != 0){
            printf("%d",i);
            arr[i]--;
        }
    }
    return 0;
}