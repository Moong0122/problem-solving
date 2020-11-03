// 스스로 + 피드백
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (find(words.begin(), words.end(), target) == words.end()) return answer;
    
    unordered_map<string, bool> m;
    for (auto& i : words) m[i] = false;
    
    queue <pair<int, string>> q;
    q.push({0, begin});
    
    while (!q.empty()) {
        int cnt = q.front().first;
        string partial = q.front().second;
        q.pop();
        
        if (m[partial]) continue;
        
        m[partial] = true;
        
        if (partial == target) {
            answer = cnt;
            break;
        }
        
        for (int i = 0; i < partial.size(); i++) {
            char sub = partial[i];
            for (int j = 'a'; j <= 'z'; j++) {
                partial[i] = j;
                if (m.find(partial) != m.end() && !m[partial]) {
                    q.push({cnt+1, partial});
                }
                
                partial[i] = sub;
            }
        }
        
    }
    
    return answer;
}
