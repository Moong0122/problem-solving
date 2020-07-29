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
