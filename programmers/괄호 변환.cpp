// 이 전에 풀이보면서 오답한 거
#include<string>
#include<vector>
using namespace std;

string solution(string p){
    string answer = "";
    int left = 0, right = 0;
    bool check = false;
    if(p.size() == 0) return "";
    for(int i=0;i<p.size();i++){
        if(p[i] == '(') left++;
        if(p[i] == ')') right++;
        // check = true -> 올바르지 않은 문장
        if(right > left) check = true;
        
        if(left == right){
            if(check){
                answer += '(';
                // v
                answer+= solution(p.substr(i+1,p.size()-i-1));
                answer += ')';
                // u
                for(int j=1;j<i;j++){
                    if(p[j] == '(') answer += ')';
                    if(p[j] == ')') answer += '(';
                }
                return answer;
            }
            else{
                answer += p.substr(0,i+1);
                answer += solution(p.substr(i+1, p.size()-i-1));
                return answer;
            }
        }
    }
    return answer;
}


// 새롭게 스스로 풀어보기
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isCorrect(string sub){ // 괄호의 짝이 맞는지 확인해주는 함수
    stack <char> s;
    
    for (char c : sub) {
        if (!s.empty() && s.top() == '(' && c == ')') {
                s.pop();
        }
        else {
            s.push(c);
        }
    }
    return s.empty();
}
string change(string sub){
    string answer = "", u = "", v ="";
    int lBracket = 0, rBracket = 0;
        
    if (!sub.empty()) {
        int i = 0;
        // 1. p를 u(균형잡힌 괄호 문자열),v(나머지 문자열)로 분리해야 한다.
        for (i = 0 ; i < sub.size() ; i++) {
            if (lBracket != 0 && (lBracket == rBracket)) {
                break;
            }
            if (sub[i] == '(') {
                lBracket++;
            } else {
                rBracket++;
            }
        }
        u = sub.substr(0, i);
        v = sub.substr(i);
        
        // 만약 u가 올바른 괄호 문자열이라면 v는 1.번부터 다시 수행해준다
        if (isCorrect(u)) {
            answer = u + change(v);
        }
        // 올바른 괄호 문자열이 아니라면 아래 과정을 수행합니다.
        else {
            answer += '(';
            answer += change(v);
            answer += ')';
            
            for (int j = 1 ; j < u.size()-1 ; j++) {
                if (u[j] == '(') {
                    answer += ')';
                } else {
                    answer += '(';
                }
            }
        }
    }
    return answer;
}
string solution(string p) {
    string answer = "";
    
    answer = change(p);
   
    return answer;
}

// 피드백 받은 후
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string p)
{
    string answer = "";

    for (int i = 0, cnt = 0; i < p.length(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;

        if (cnt == 0) {
            string u = p.substr(0, i + 1);
            string v = p.substr(i + 1);

            if (p[0] == '(') {
                // 올바른 괄호 문자열 처리
                answer = u + solution(v);
            } else {
                // 균형잡힌 괄호 문자열 처리
                answer = "(" + solution(v) + ")";

                for (int j = 1; j < u.length() - 1; j++) {
                    answer += (u[j] == '(') ? ")" : "(";
                }
            }

            break;
        }
    }

    return answer;
}
