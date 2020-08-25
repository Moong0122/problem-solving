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
