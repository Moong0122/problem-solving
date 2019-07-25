#include<stdio.h>
#include<stdlib.h>

int arr[10001];
int main(){
    int n, a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        arr[a]++;
    }
    for(int i=1;i<10001;i++){
        while(arr[i] != 0){
            printf("%d\n", i);
            arr[i]--;
        }
    }
    return 0;
}
