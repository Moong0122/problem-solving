// 풀이
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i}); // 중요도, 번지
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        
        if (f.first == pq.top()) { // 출력되는 경우
            pq.pop();
            cnt++;
            
            if (f.second == location) break; // 내가 요청한 문서 차례라면
        } else {
            q.push(f);
        }
    }
    
    return cnt;
}
