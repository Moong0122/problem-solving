#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr;
    int j,tmp;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        tmp = arr[i];
        for(j=i; j>0 && arr[j-1] > tmp;j--){
                arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}
