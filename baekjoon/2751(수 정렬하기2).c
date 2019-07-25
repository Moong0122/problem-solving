//qsort 구현해보기 
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
int main(){
    int n, *arr;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, n,sizeof(int),compare);
    for (int i = 0; i < n; i++){
            printf("%d\n",arr[i]);
    }
        free(arr);
        return 0;
}