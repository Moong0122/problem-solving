// 1. 배열 선언해서 풀어보기 -> 메모리 사용 : 5020 KB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1000001];
int main(){
    int n;
    scanf("%d",&n);
    memset(arr, -1, sizeof(arr));
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i<=n ;i++){
        arr[i] = ((arr[i-1] % 15746) + (arr[i-2] % 15746)) % 15746;
    }
    printf("%d\n",arr[n]);
    
    return 0;
}

// 2. 배열 선언 X 변수만 선언해서 풀어보기 -> 메모리 사용 : 1116 KB
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    int a = 1, b=2, c = 0;
    if(n == 1)
        printf("1\n");
    else if(n == 2)
        printf("2\n");
    else{
        for(int i = 3; i<=n ;i++){
            c = (a + b) % 15746;
            if(i == n)
                break;
            a = (b % 15746);
            b = (c % 15746);
        }
        printf("%d\n",c);
    }
    return 0;
}
*/
