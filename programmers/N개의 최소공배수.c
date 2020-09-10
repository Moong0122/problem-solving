#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// 두 수의 최대공약수를 구해서 최소공배수까지 만들어주는 역햘이다.
int findMaxCommonNumber(int big, int small){
    int tmp;
    while(small != 0){
        tmp = big % small;
        big = small;
        small = tmp;
    }
    return big;
}

int solution(int arr[], size_t arr_len) {
    int tmp = arr[0], small, big, n;
    for(int i = 1 ; i < arr_len ; i++){
        // 큰수 작은수를 먼저 나누어준다.
        if(tmp > arr[i]){
            big = tmp;
            small = arr[i];
        }else{
            big = arr[i];
            small = tmp;
        }
        
        if(big % small == 0) tmp = big;
        else{
            n = findMaxCommonNumber(big, small);
            tmp = big * small / n;
        }
    }
    
    return tmp;
}
