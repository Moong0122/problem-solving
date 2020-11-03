#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto& it : scoville) q.push(it);

    while(1){
        int num1 = q.top(); q.pop();
        if(num1 >= K) break;
        if(q.empty()){ // 아무리 다 더해도 k를 넘지 못한다.
            answer = -1;
            break;
        }
        int num2 = q.top(); q.pop();
        q.push(num1 + num2 * 2);
        answer++;
    }
    return answer;
}

// 다시 풀어보기
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0, first, second;
    
    while (pq.top() < K) {
        
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        
        first = pq.top();
        pq.pop();
        
        second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    
    return answer;
}
