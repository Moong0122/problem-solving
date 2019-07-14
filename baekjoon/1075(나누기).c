#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int N,F,n,s,result;
    scanf("%d%d",&N,&F);
    
    s = N % 100;
    
    for(int i = N - s;i < N + (100-s);i++){
        if(i % F == 0){
            result = i;
            break;
        }
    }
    if(result % 100 < 10)
    printf("0%d\n",result % 100);
    else
    printf("%d\n",result % 100);
    
    return 0;
}
