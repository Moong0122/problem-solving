// 처음 풀었을 때
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> ss;
    
    for(auto& i : s){
        if(ss.empty()){
            ss.push(i);
        }
        else if(ss.top() == i){
            ss.pop();
        }
        else ss.push(i);
    }
    int answer = 0;
    answer = ss.empty() ? 1 : 0;
    return 0;
}

// 피드백 후 (for문의 내용만 수정하면 될 듯)
for(auto& i : s){
    if(!ss.empty() && ss.top() == i){
        ss.pop();
    }
    else{
        ss.push(i);
    }
}
