#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char chass[8][8];
    int cnt = 0;
    for(int i = 0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf(" %c",&chass[i][j]);
            if(chass[i][j] == 'F' && (i+j) % 2 == 0)
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
