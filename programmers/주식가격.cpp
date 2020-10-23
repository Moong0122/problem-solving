#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0 ; i < prices.size() ; i++){
        int cnt = 0;
        for(int j = i+1 ; j < prices.size() ; j++){
            cnt++;
            if(prices[i] > prices[j]) break;
        }
        answer[i] = cnt;
    }
    
    return answer;
}

// 다시 처음 풀었을 때
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0 ; i < prices.size() ; i++) {
        int cnt = 0;
        for (int j = i+1 ; j < prices.size() ; j++) {
            cnt++;
            if (prices[j] < prices[i]) {
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

// 피드백
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;
    
    for (int i = 0 ; i < prices.size() ; i++) {
        while (!st.empty() && prices[i] < prices[st.top()]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }
    
    return answer;
}
