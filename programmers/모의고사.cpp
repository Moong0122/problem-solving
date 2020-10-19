// 처음 풀었을 때
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> supoja(3,0);
    int size = answers.size();
    int two[] = {1, 3, 4, 5};
    int three[] = {3, 1, 2, 4, 5};
    
    for (int i = 0 ; i < size ; i++) {
        // 1번
        if (answers[i] == (i % 5) + 1) {
            supoja[0]++;
        }
        // 2번
        if ((i % 2 == 0 && answers[i] == 2) || (i % 2 == 1 && answers[i] == two[(i % 8) / 2])) {
            supoja[1]++;
        }
        // 3번
        if (answers[i] == three[(i % 10) / 2]) {
            supoja[2]++;
        }
    }
    
    int max_number = max(max(supoja[0], supoja[1]), supoja[2]);
    for (int i = 0 ; i < 3 ; i++) {
        if (supoja[i] == max_number) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

// 피드백을 받고
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patterns {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    vector<int> supoja(patterns.size(),0);
    
    for (int i = 0 ; i < answers.size() ; i++) {
        for (int j = 0 ; j < patterns.size() ; j++) {
            if (answers[i] == patterns[j][i % patterns[j].size()]) {
                supoja[j]++;
            }
        }
    }
    
    int max_number = *max_element(supoja.begin(), supoja.end());
    for (int i = 0 ; i < patterns.size() ; i++) {
        if (supoja[i] == max_number) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
