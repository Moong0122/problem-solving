#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    long a = 1, b = 1, c = 0;
    scanf("%d",&n);
    
    if(n == 1)
        printf("1\n");
    else if(n == 2)
        printf("1\n");
    else{
        for(int i=3;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        printf("%ld\n",c);
    }
    return 0;
}
