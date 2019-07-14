#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int a,b,v, total = 0;
    scanf("%d%d%d",&a,&b,&v);
    
    if((v-b) % (a-b) == 0)
    total = (v-b)/(a-b);
    else
    total = (v-b)/(a-b) + 1;
    
    printf("%d\n",total);
    return 0;
}
