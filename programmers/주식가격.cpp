#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0 ; i < prices.size() ; i++){
        int cnt = 0;
        for(int j = i+1 ; j < prices.size() ; j++){
            cnt++;
            if(prices[i] > prices[j]) break;
        }
        answer[i] = cnt;
    }
    
    return answer;
}

/*
 스택을 사용한 풀이
 
 #include <string>
 #include <vector>
 #include <stack>

 using namespace std;

 vector<int> solution(vector<int> prices) {
     vector<int> answer(prices.size() , 0);
     stack <int> s;
     int size = prices.size();
     
     for(int i = 0 ; i < size ; i++){
         // 스택이 비어있지 않고, 주식 가격이 떨어졌다면
         while(!s.empty() && prices[s.top()] > prices[i]){
             answer[s.top()] = i - s.top(); // 인덱스의 차이로 기간 구하기
             s.pop();
         }
         s.push(i);
     }
     // 이제 스택에 남아있는 인덱스 정리해주기
     // prices 벡터가 끝날때까지 주식 가격이 떨어지지 않은 값들이다
     while(!s.empty()){
         answer[s.top()] = size - s.top() - 1;
         s.pop();
     }
     return answer;
 }
 */
