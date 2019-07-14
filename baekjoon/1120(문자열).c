#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    char x[50], y[50];
    int cnt = 0, small = 51;
    scanf("%s",x);
    scanf("%s",y);
    
    for(int i=0;i<strlen(y)-strlen(x)+1;i++){
        for(int j=0;j<strlen(x);j++){
            if(x[j] != y[j+i])
                cnt++;
        }
        if(cnt<small)
            small = cnt;
        cnt = 0;
    }
    printf("%d\n",small);
    
    return 0;
}
