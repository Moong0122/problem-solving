#include<stdio.h>

int arr[1000001];
int main(){
    int max = -1;
    int n, one = 0, two = 0;
    for(int i=2;i<=1000000;i++){
        arr[i] = i;
    }
    for(int i=2;i*i<=1000000;i++){
        if(arr[i] == 0)
            continue;
        for(int j=i+i;j<=1000000;j+=i){
            arr[j] = 0;
        }
    }
    while(1){
        scanf("%d",&n);
        if(n == 0)
            break;
        for(int i = 2;i<=n/2;i++){
            if(arr[i] != 0 && arr[n-i] != 0){
                one = i;
                two = n-i;
                break;
            }
        }
        if(one == 0 && two == 0)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n",n,one,two);
    }
    return 0;
}
