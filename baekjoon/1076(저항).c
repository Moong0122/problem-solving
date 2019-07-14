#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    int cnt = 0;
    long long result = 0;
    char *color[10];
    for(int i=0;i<10;i++){
        color[i] = (char*)malloc(7);
    }
    color[0] = "black";
    color[1] = "brown";
    color[2] = "red";
    color[3] = "orange";
    color[4] = "yellow";
    color[5] = "green";
    color[6] = "blue";
    color[7] = "violet";
    color[8] = "grey";
    color[9] = "white";
    
    
    char *arr[3];
    for(int i=0;i<3;i++){
        arr[i] = (char*)malloc(7);
        scanf("%s",arr[i]);
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            if(strcmp(arr[i],color[j])==0){
                cnt++;
                if(cnt == 1)
                    result += j*10;
                else if(cnt == 2)
                    result += j;
                else if(cnt == 3)
                    result *= pow(10,j);
                break;
            }
        }
    }
    printf("%lld\n",result);
    return 0;
}
