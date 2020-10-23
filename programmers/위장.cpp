#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, vector<string>> m;
    
    for(auto& i : clothes) m[i[1]].push_back(i[0]);
    
    for(auto& i : m) answer *= (i.second.size() + 1);
    
    return answer - 1;
}

// 다시 처음 풀었을 때 (피드백 따로 없음)
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map <string, int> m;
    
    for (auto& i : clothes) {
        m[i[1]]++;
    }
    
    int answer = 1;
    for (auto& i : m) {
        answer *= (i.second + 1);
    }
    
    return answer-1;
}
