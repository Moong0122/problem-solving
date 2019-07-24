#include<stdio.h>
#include<string.h>

char arr[1001];
char uc[4] = {'U','C','P','C'};

int main(){
    int cnt = 0;
    fgets(arr, sizeof(arr),stdin);
    for(int i=0;i<=strlen(arr);i++){
        for(int j= cnt ; j<4 ; j++){
            if(arr[i] == uc[j])
                cnt++;
            else
                break;
        }
    }
    if(cnt == 4)
        printf("I love UCPC\n");
    else
        printf("I hate UCPC\n");
    return 0;
}
