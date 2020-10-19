// 처음 풀었을 때
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0 ; i < commands.size() ; i++) {
        vector<int> temp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }
    
    return answer;
}

// 피드백 받고
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto& v : commands) {
        vector<int> sub(array.begin() + v[0] - 1, array.begin() + v[1]);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[v[2] - 1]);
    }
    
    return answer;
}
