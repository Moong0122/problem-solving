#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(j<n-i-1)
                printf(" ");
            else if(j<n+i)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}