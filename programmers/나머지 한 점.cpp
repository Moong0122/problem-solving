#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    unordered_set<int> left, right;
    vector<int> ans;

    for (auto& i : v) {
        if (left.count(i[0])) {
            left.erase(i[0]);
        } else {
            left.insert(i[0]);
        }
        
        if (right.count(i[1])) {
            right.erase(i[1]);
        } else {
            right.insert(i[1]);
        }
    }

    for (auto& i : left) ans.push_back(i);
    for (auto& i : right) ans.push_back(i);
    
    return ans;
}

// 피드백
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    unordered_map<int, int> left, right;
    
    for (auto i : v) {
        left[i[0]]++;
        right[i[1]]++;
    }
    
    for (auto& i : left) {
        if (i.second == 1) ans.push_back(i.first);
    }
    
    for (auto& i : right) {
        if (i.second == 1) ans.push_back(i.first);
    }

    return ans;
}
