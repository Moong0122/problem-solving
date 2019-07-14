#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void divide(int a, int b);

int main(){
    int n, a,*arr;
    scanf("%d",&n);
    
    arr = (int*)malloc(sizeof(int) * n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        arr[i] = a;
    }
    
    for(int i=1;i<n;i++){
        if(arr[0] % arr[i] == 0)
        printf("%d/%d\n",arr[0]/arr[i],1);
        else{
            divide(arr[0],arr[i]);
        }
    }
    free(arr);
    return 0;
}

void divide(int a, int b){
    int big,small,ans,tmp;
    if(a>=b){
        big = a;
        small = b;
    }
    else{
        big = b;
        small = a;
    }
    
    while(1){
        if(big % small == 0){
            ans = small;
            break;
        }
        tmp = big % small;
        big = small;
        small = tmp;
    }
    printf("%d/%d\n",a/ans,b/ans);
}
