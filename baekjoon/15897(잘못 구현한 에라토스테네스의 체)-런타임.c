#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int n;
    long long total = 0;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j+=i){
            arr[j] += 1;
            total++;
        }
    }
    printf("%lld\n", total);
    return 0;
}