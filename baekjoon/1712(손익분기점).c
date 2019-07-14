#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int a,b,c, i = 0;
    scanf("%d%d%d",&a,&b,&c);
    
    if(b >= c)
    printf("-1\n");
    else{
        i = a / (c-b) + 1;
        printf("%d\n",i);
    }
}
