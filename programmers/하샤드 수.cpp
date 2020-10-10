// 처음 풀었을 때
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    bool answer = true;
    string str = to_string(x);
    
    for(int i = 0 ; i < str.size() ; i++){
        sum += str[i] - 48;
    }
    
    if(x % sum == 0) return true;
    return false;
}

/* 피드백
 
 기본 피드백
 * if, while, for 문장과 괄호 사이에 빈칸 추가
 * +,-,*,/,= 등 연산자 양 옆에 빈 칸 추가
 * if, while, for 문장 블록 뒤에 가급적 빈 줄 추가
 * if, else 문에 하나의 문장만 있더라도 가급적 다음 줄에
 * 함수 하나에 return 문장은 가급적 하나만
 
 풀이 피드백
 문자열 이용 방법은 편하지만 성능이 낮다!
 내가 처음에 사용했던 방법이 문자열을 이용한 방법인데 앞으로는 %,/을 이용해서 풀어야겠다.
 */

// 피드백 후
#include <string>
#include <vector>
using namespace std;

bool solution(int x){
    int num = x; // 현재
    int remain =  0; // 나머지
    int sum = 0; // 각 자리 수의 합
    bool answer = true;
    
    while(num != 0){
        remain = num % 10;
        num /= 10;
        sum += remain;
    }
    
    if(x % sum != 0){
        answer = false;
    }
    
    return answer;
}
