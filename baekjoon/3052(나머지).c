#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[42];

int main(){
    
    int a, ans = 0;
    
    for(int i=0;i<10;i++){
        scanf("%d",&a);
        num[a%42]++;
    }
    for(int i=0;i<42;i++){
        if(num[i] != 0)
        ans++;
    }
    printf("%d\n",ans);
    
    return 0;
}
