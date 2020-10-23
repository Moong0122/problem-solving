// 처음 풀었을 때
#include <string>
#include <vector>
#include <map>
using namespace std;

int remainDays(int current, int speed) {
    return current % speed == 0 ? current / speed : current / speed + 1;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map <int, int> m;
    
    int partial, target = remainDays(100 - progresses[0], speeds[0]);
    m[target]++;
    
    for (int i = 1 ; i < progresses.size() ; i++) {
        partial = remainDays(100 - progresses[i], speeds[i]);
        
        if (partial > target) target = partial;
        
        m[target]++;
    }
    
    for (auto& i : m) {
        answer.push_back(i.second);
    }
    return answer;
}

// 피드백
#include <string>
#include <vector>
#include <map>
using namespace std;

int remainDays(int current, int speed) {
    return (100 - current) % speed == 0 ? (100 - current) / speed : (100 - current) / speed + 1;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map <int, int> m;

    int partial, target = remainDays(progresses[0], speeds[0]);
    m[target]++;

    for (int i = 1 ; i < progresses.size() ; i++) {
        partial = remainDays(progresses[i], speeds[i]);

        if (partial > target) target = partial;

        m[target]++;
    }

    for (auto& i : m) {
        answer.push_back(i.second);
    }
    return answer;
}
