#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int *arr;
    int pointer = -1;
    int n,a,sum = 0;
    scanf("%d",&n);
    
    arr = (int*)malloc(n*sizeof(int)); //배열 설정시 malloc을 사용하는 방법도 있다
    
    while(n--){
        scanf("%d",&a);
        if(a == 0){
            pointer--;
        }
        else{
            pointer++;
            arr[pointer] = a;
        }
    }
    
    for(int i=0;i<pointer+1;i++){
        sum += arr[i];
    }
    
    printf("%d\n",sum);
    
    free(arr);
    return 0;
}
