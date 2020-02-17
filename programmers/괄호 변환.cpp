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
