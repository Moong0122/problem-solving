#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    
    int n,i = 2;
    scanf("%d",&n);
    
    while(1){
        if(n == 1)
            break;
        
        if(n % i == 0){
            printf("%d\n",i);
            n /= i;
        }else
            i++;
    }
    
    return 0;
}
