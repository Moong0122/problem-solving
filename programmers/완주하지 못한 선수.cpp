#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> m;
    
    for(auto& i : participant) m[i]++;
    for(auto& i : completion) m[i]--;
    for(auto& i : m){
        if(i.second > 0){
            answer = i.first;
            break;
        }
    }
    return answer;
}

// 다시 처음 풀었을 때 (피드백 적용)
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    string answer = "";
    
    for (auto& i : participant) {
        m[i]++;
    }
    
    for (auto& i : completion) {
        m[i]--;
    }
    
    for (auto& i : m) {
        if (i.second != 0) {
            answer = i.first;
            break;
        }
    }
    
    return answer;
}
