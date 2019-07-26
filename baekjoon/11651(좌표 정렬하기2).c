#include<stdio.h>
#include<stdlib.h>

typedef struct lo{
    int x;
    int y;
}location;

int compare(const void *a, const void *b){
    location *pa, *pb;
    pa = (location*)a;
    pb = (location*)b;
    if(pa->y < pb->y)
        return -1;
    else if(pa->y > pb->y)
        return 1;
    else{
        if(pa->x < pb->x)
            return -1;
        else if(pa->x > pb->x)
            return 1;
        else
            return 0;
    }
}
int main(){
    int n,start,cnt = 0;
    scanf("%d",&n);
    location L[n];

    for(int i = 0;i<n;i++){
        scanf("%d%d",&L[i].x,&L[i].y);
    }
    qsort(L,n,sizeof(location),compare);
    for(int i=0;i<n;i++){
        printf("%d %d\n", L[i].x, L[i].y);
    }
}