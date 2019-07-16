#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int e,s,m,cnt = 0;
    int a = 0,b=0,c=0;
    scanf("%d%d%d",&e,&s,&m);
    while(1){
        cnt++;
        if(a++ == 15)
            a = 1;
        if(b++ == 28)
            b = 1;
        if(c++ == 19)
            c = 1;
        if(a == e && b == s && c == m)
            break;
    }
    printf("%d\n",cnt);
    return 0;
}
