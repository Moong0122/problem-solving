#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cmath>
using namespace std;

bool solution(string s) {
    unordered_map<char, int> m;
    stack<char> st;
    
    m['('] = -1, m[')'] = 1;
    m['{'] = -2, m['}'] = 2;
    m['['] = -3, m[']'] = 3;
    
    for (auto& i : s) {
        if (!st.empty()) {
            if ((abs(m[st.top()]) == abs(m[i])) && (m[st.top()] < 0 && m[i] > 0)) {
                st.pop();
                continue;
            }
        }
        st.push(i);
    }
    
    return st.empty();
}

// 피드백
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

bool solution(string s) {
    unordered_map<char, int> m;
    stack<char> st;
    
    m['('] = -1, m[')'] = 1;
    m['{'] = -2, m['}'] = 2;
    m['['] = -3, m[']'] = 3;
    
    for (auto& i : s) {
        if (!st.empty()) {
            if (-m[st.top()] == m[i] && (m[st.top()] < 0 && m[i] > 0)) {
                st.pop();
                continue;
            }
        }
        st.push(i);
    }
    
    return st.empty();
}
