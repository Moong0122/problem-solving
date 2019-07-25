#include<stdio.h>
#include<stdlib.h>

typedef struct lo{
    int x;
    int y;
}location;

int compare(const void *a, const void *b){
    if (((location*)a)->x > ((location*)b)->x)
        return 1;
    if (((location*)a)->x < ((location*)b)->x)
        return -1;
    else
        return ((location*)a)->y > ((location*)b)->y;
} 
/* compare 방법 2
 int compare(const void *a, const void *b){
    return ((location*)a)->x != ((location*)b)->x ? ((location*)a)->x > ((location*)b)->x : ((location*)a)->y > ((location*)b)->y;
 }
*/
int main(){
    int n;
    scanf("%d",&n);
    location L[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&L[i].x,&L[i].y);
    }
    qsort(L,n,sizeof(location),compare);
    for(int i=0;i<n;i++){
        printf("%d %d\n",L[i].x,L[i].y);
    }
    return 0;
}
