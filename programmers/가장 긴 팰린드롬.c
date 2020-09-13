#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int size = strlen(s);
    int front, back, half;
    bool pass;
    
    for(int i = size ; i > 0 ; i--){ // 팰린드롬의 길이
        // 가능한 모든 가지수 나열해주기 for문 이용해서!
        for(int j = 0 ; j < size - i + 1; j++){ // 왔다갔다 할 수 있는 범위
            front = j;
            back = j + i - 1;
            pass = true;
            // for문을 새로 만드는 것보다 while문이 더 빠르게 나온다!
            while(front < back){
                if(s[front] != s[back]){
                    pass = false;
                    break;
                }
                front++;
                back--;
            }
            if(pass) return i;
        }
    }
    return answer;
}
