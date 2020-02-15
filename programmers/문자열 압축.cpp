#include<iostream>
#include<string>
#include<vector>
using namespace std;

int changeNum(int n){
    if(n < 10) return 1;
    if(n < 100) return 2;
    return 3;
}

int solution(string s){
    string cmp = "";
    int answer = s.size(), len = s.size(), tmp, cnt;
    
    for(int part = 1; part <= len/2; part++){
        cmp = s.substr(0,part);
        cnt = 1;
        tmp = 0;
        
        for(int i=part ; i < len ; i+=part){
            if(cmp != s.substr(i,part)){
                if(cnt > 1) tmp += changeNum(cnt);
                tmp += part;
                cmp = s.substr(i,part);
                cnt = 1;
            }
            else cnt++;
            if(i+part >= len){
                if(cnt > 1) tmp += changeNum(cnt);
                tmp += (len - i );
            }
        }
        answer = min(answer, tmp);
    }
    return answer;
}
