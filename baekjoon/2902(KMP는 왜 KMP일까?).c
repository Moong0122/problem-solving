#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char arr[101];

int main(){
    scanf("%s",arr);
    int len = strlen(arr);

    for(int i=0;i<len;i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z')
            printf("%c", arr[i]);
    }
    printf("\n");
    return 0;
}
