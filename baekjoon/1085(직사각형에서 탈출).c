#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int small = 1001;
    int x,y,w,h;
    scanf("%d%d%d%d",&x,&y,&w,&h);
    
    int arr[4] = {x,y,w-x,h-y};
    for(int i=0;i<4;i++){
        if(arr[i] < small)
            small = arr[i];
    }
    printf("%d\n",small);
    return 0;
}
