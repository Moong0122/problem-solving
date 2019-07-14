#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int arr[1001];

int main(){
    int n,k;
    int i,j;
    int total = 0;
    scanf("%d%d",&n,&k);
    
    while(1){
        for(i=2;i<=n;i++){
            if(arr[i] == 0)
                break;
        }
        for(j=2;j<=n;j++){
            if(arr[j] == 0 && j % i == 0){
                arr[j] = -1;
                total++;
                if(total == k)
                    break;
            }
        }
        if(total == k)
            break;
    }
    printf("%d\n",j);
    
    return 0;
}
