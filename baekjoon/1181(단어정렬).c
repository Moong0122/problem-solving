#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct word{
    int len;
    char name[51];
}word;

int compare(const void *a, const void *b){
    if(((word*)a)->len > ((word*)b)->len)
        return 1;
    if(((word*)a)->len < ((word*)b)->len)
        return -1;
    else
        return strcmp(((word*)a)->name,((word*)b)->name);
}
int main(){
    int n;
    scanf("%d",&n);
    word W[n];

    for(int i=0;i<n;i++){
        scanf("%s",W[i].name);
        W[i].len = strlen(W[i].name);
    }
    qsort(W,n,sizeof(word),compare);
    for(int i = 0;i<n;i++){
        if(i>0 && strcmp(W[i-1].name,W[i].name)==0)
            continue;
        printf("%s\n", W[i].name);
    }
    return 0;
}
