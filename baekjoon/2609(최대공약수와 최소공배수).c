#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int a,b,num = 0, result = 0;
    scanf("%d%d",&a,&b);
    
    if(a >= b)
    num = b;
    else
    num = a;
    
    for(int i=1;i<=num;i++){
        if(a % i==0 && b % i==0)
        result = i;
    }
    printf("%d\n",result);
    printf("%d\n",a * b/result);
    
    return 0;
}

/* 다른 방법
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 
 int main()
 {
    int a,b,big,small,mok,nmg,gcm,lcm;
    scanf("%d %d",&a,&b);
    if(a>=b){
        big = a;
        small = b;
    }else{
        small = a;
        big = b;
    }
 
 while(1){
    mok = big/small;
    nmg = big%small;
    if(nmg==0){
        gcm = small;
        lcm = a*b  / gcm;
    printf("%d\n",gcm);
    printf("%d\n",lcm);
    break;
    }
    big = small;
    small = nmg;
    }
    return 0;
 }
 */
