#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
// int를 string으로 바꾸는 to_string()활용해보기
int solution(string s){
    int len = (int)s.size();
    int answer = len;
    int maxZip = len/2;
    
    for(int i=1;i<=maxZip;i++){ // 압축할 문자열 수 1개부터 len/2개 까지
        //
        int seq = 1;
        int totalLen = len;
        string before = "";
        for(int j=0;j<len;j+=i){
            string tmp;
            if(j+i > len) tmp = s.substr(j,len-j);
            else tmp = s.substr(j,i);
            
            if(j!=0){
                if(tmp == before){
                    totalLen -= i;
                    seq++;
                }else{
                    if(seq != 1){ // 전에 연속된 기록들을 처리해주기
                        totalLen += to_string(seq).size();
                        seq = 1;
                    }
                }
            }
            before = tmp;
        }
        if(seq != 1) totalLen += to_string(seq).size();
        
        if(totalLen < answer) answer = totalLen;
        //
    }
    return answer;
}
