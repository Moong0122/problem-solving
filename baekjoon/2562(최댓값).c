#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int arr[9];
    int n, number;
    int max = 0;
    
    /*
     * int *arr;
     * arr = (int*)malloc(9*sizeof(int));
     */
    
    for(int i=0; i<9 ;i++){
        scanf("%d",&n);
        arr[i] = n;
        
        if(n >= max){
            max = n;
            number = i;
        }
    }
    
    printf("%d\n",max);
    printf("%d\n",number+1);
    
    return 0;
}
