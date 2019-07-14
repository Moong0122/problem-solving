#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int n;
    scanf("%d",&n);
    int a = 1;
    
    for(int i=1;i<=n;i++){
        a *= i;
    }
    
    printf("%d\n",a);
    
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fac(int num){
    
    if(num == 1)
    return 1;
    
    return num * fac(num-1);
}

int main(){
    
    int n;
    
    scanf("%d",&n);
    printf("%d\n",fac(n));
    
    return 0;
}
 */
