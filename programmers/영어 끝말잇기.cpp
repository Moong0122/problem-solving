// 스스로
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> s;
    string before;
    
    for (int i = 0; i < words.size(); i++) {
        if (!s.empty() && (before.back() != words[i].front() || s.find(words[i]) != s.end())) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        s.insert(words[i]);
        before = words[i];
    }
    
    return answer;
}

// 피드백
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> s;
    
    s.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (words[i-1].back()!= words[i].front() || s.find(words[i]) != s.end()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        s.insert(words[i]);
    }
    
    return answer;
}

