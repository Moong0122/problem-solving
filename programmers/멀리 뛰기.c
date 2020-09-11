#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long* arr;
long long fibo(int number){
    if(number == 0 || number == 1) return 1;
    
    if(arr[number] != -1) return arr[number];
    
    arr[number] = ( fibo(number-1) + fibo(number-2) ) % 1234567;
    return arr[number];
}
long long solution(int n) {
    long long answer;
    
    arr = (long long*)malloc(sizeof(long long) * (n+1));
    memset(arr, -1, sizeof(long long) * (n+1));
    
    answer = fibo(n);
    free(arr);
    return answer;
}
