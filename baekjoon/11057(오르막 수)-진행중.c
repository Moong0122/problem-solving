#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1002][11];

int main(){

    int n,sum = 0;
    scanf("%d",&n);

    for(int i=1;i<=n+1;i++){
        for(int j=0;j<10;j++){
            if(i == 1){
                arr[i][j] = 1; 
                sum += 1;
            }else{
                if(j == 0){
                    arr[i][j] = sum;
                }
                else{
                    arr[i][j] = arr[i][j-1] - arr[i-1][j-1];
                    sum += arr[i][j];
                }
            }
        }
    }
    printf("%d\n",arr[n+1][0]);
    return 0;
}
// 1 -> 1,1,1,1,1,1,1,1,1,1 [10개]
// 2 -> 0(0~9 10개) 1(1~9 9개) 2(2~9 8개) 3(4~9 7개) ... 9(9 1개) [55개]
// 10 * (10 + 1) / 2
// 3 -> 0(55개) 1(45개)
// a+b