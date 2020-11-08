// 내가 푼 방법
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    vector<int> v;
    
    for (auto o : operations) {
        if (o[0] == 'I') {
            int number = stoi(o.substr(2));
            v.push_back(number);
        } else {
            if (v.empty()) continue;
            
            if (o[2] == '-') { // 최솟값을 삭제합니다.
                priority_queue<int, vector<int>, greater<int>> pq1(v.begin(), v.end());
                pq1.pop();
                v.clear();
                
                while (!pq1.empty()) {
                    v.push_back(pq1.top()); pq1.pop();
                }
            } else { // 최댓값을 삭제합니다.
                priority_queue<int, vector<int>> pq2(v.begin(), v.end());
                pq2.pop();
                v.clear();
                
                while (!pq2.empty()) {
                    v.push_back(pq2.top()); pq2.pop();
                }
            }
            
        }
    }
    
    if (v.size() != 0) {
        sort(v.begin(), v.end());
        answer[0] = v.back();
        answer[1] = v.front();
    }
    
    return answer;
}

// 새롭게 공부한 방법
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    multiset<int> m;
    
    for (auto o : operations) {
        if (o[0] == 'I') {
            m.insert(stoi(o.substr(2)));
        } else {
            if (m.empty()) continue;
            
            if (o[2] == '-') { // 최솟값 삭제
                m.erase(*m.begin());
            } else { // 최대값 삭제
                m.erase(*--m.end());
            }
        }
        
    }
    
    if (!m.empty()) {
        answer[0] = *--m.end();
        answer[1] = *m.begin();
    }
    
    return answer;
}
