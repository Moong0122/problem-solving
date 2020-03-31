#include<iostream>
#include<vector>
#include <string>
#include<map>
using namespace std;

string hangul[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};

vector<pair<string, int>> seq; // < 유저 아이디, enter = 0, leave = 1 >
map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(string it : record){
        int firstPos = (int)it.find(32);
        int secondPos = (int)it.find(32,firstPos+1);
        string str1 = it.substr(0,firstPos);
        string str2 = it.substr(firstPos+1,secondPos-firstPos-1);
        string str3 = it.substr(secondPos+1);
        
        if(str1 == "Enter"){
            seq.push_back({str2,0});
            m[str2] = str3;
        }else if(str1 == "Leave"){
            seq.push_back({str2,1});
        }else if(str1 == "Change"){
            m[str2] = str3;
        }
    }
    for(int i=0;i<seq.size();i++){
        string sum = "";
        sum += m[seq[i].first];
        sum += hangul[seq[i].second];
        answer.push_back(sum);
    }
    return answer;
}
