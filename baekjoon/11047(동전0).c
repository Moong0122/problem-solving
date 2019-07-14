#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int N,K,*arr,n = 100, number,sum = 0;
    scanf("%d%d",&N,&K);
    
    arr= (int*)malloc(sizeof(int)*N);
    for(int i=0;i< N;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>K){
            if(i<n)
            n = i;
        }
    }
    if(n == 100)
    n = N;
    
    for(int i = n-1;i>=0;i--){
        number = K / arr[i];
        K = K % arr[i];
        sum += number;
        if(K == 0)
        break;
    }
    printf("%d\n",sum);
    
    free(arr);
    return 0;
}
