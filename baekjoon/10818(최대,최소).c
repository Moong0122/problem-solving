#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n,a;
    int min = 1000001, max = -1000001;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a <= min){
            min = a;
        }
        if(a >= max){
            max = a;
        }
    }
    printf("%d %d\n",min,max);
    
    return 0;
}
