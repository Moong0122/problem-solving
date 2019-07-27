#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int number[10001];

typedef struct result{
    int x;
    int y;
}result;

void check(int num){ 
    int i,j;
    for(i = 2;i*i<=10000;i++){
        if(number[i] == 0)
            continue;
            for(int j= i+i;j<=10000;j+=i){
            number[j] = 0;
        }
    }
}
int main(){
    result R;
    int n,input,min = 10000;
    scanf("%d",&n);

    for(int i=2;i<=10000;i++){
        number[i] = i;
    }
    check(1);
    for(int i=1;i<=n;i++){
        scanf("%d",&input);
        for(int j=2;j<=input/2;j++){
            if(number[j] !=0 && number[input-j] != 0){
                if((input-2*j)<min){
                    min = input-2*j;
                    R.x = j;
                    R.y = input-j;
                }
            }
        }
        printf("%d %d\n",R.x, R.y);
        R.x = R.y = 0;
        min = 10000;
    }
    return 0;
}
