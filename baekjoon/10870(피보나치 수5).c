#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibo(int num){
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return fibo(num-2) + fibo(num-1);
}

int main(){
    
    int n;
    scanf("%d",&n);
    printf("%d\n",fibo(n));
    
    return 0;
}
