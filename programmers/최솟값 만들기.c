#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    int index, tmp;
    
    for(int i = 0 ; i < A_len ; i++){ // 오름차순 큰값이 뒤로
        index = i;
        for(int j = i+1 ; j < A_len ; j++){
            if(A[j] < A[index]) index = j;
        }
        tmp = A[index];
        A[index] = A[i];
        A[i] = tmp;
    }
    
    for(int i = 0 ; i < B_len ; i++){ // 내림차순 작은게 뒤로
        index = i;
        for(int j = i+1 ; j < B_len ; j++){
            if(B[j] > B[index]) index = j;
        }
        tmp = B[index];
        B[index] = B[i];
        B[i] = tmp;
    }
    
    for(int i = 0 ; i < A_len ; i++) answer += A[i] * B[i];
    return answer;
}
