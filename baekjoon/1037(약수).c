#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int n, a, tmp, *arr;
    scanf("%d",&n);
    
    arr = (int*)malloc(sizeof(int) * n); //n개의 배열 생성
    
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        arr[i] = a;
    } //배열에 숫자 입력
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    printf("%d\n",arr[0]*arr[n-1]);
    free(arr);
    
    return 0;
}
