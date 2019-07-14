#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int x[3], y[3];
int main(){
    int a,b,Xcheck = 0,Xcnt = 0,Ycheck = 0,Ycnt = 0;
    for(int i=0;i<3;i++){
        scanf("%d%d",&a,&b);
        x[i] = a;
        y[i] = b;
    }
    for(int i=1;i<3;i++){
        if(x[i] == x[0])
            Xcnt++;
        if(x[i] != x[0])
            Xcheck = i;
        if(y[i] == y[0])
            Ycnt++;
        if(y[i] != y[0])
            Ycheck = i;
    }
    if(Xcnt == 0)
        printf("%d ",x[0]);
    if(Xcnt != 0)
        printf("%d ",x[Xcheck]);
    if(Ycnt == 0)
        printf("%d\n",y[0]);
    if(Ycnt != 0)
        printf("%d\n",y[Ycheck]);
    return 0;
}
