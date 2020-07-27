#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1.size() < v2.size();
}
vector<int> solution(string s) {
    vector<vector<int>> v;
    vector<int> answer;
    vector<int> tmp;
    
    int len = (int)s.size();
    string sub_part = "";
    //
    for(int i = 1 ; i < len - 1 ; i++){
        if(s[i] == ','){
            if(sub_part != ""){
                tmp.push_back(stoi(sub_part));
                sub_part = "";
            }
        }
        else if(s[i] == '}'){
            tmp.push_back(stoi(sub_part));
            sub_part = "";
            v.push_back(tmp);
            tmp.clear();
        }
        else if(s[i] != '{') sub_part += s[i];
    }
    // 정렬 완료
    sort(v.begin(), v.end(), cmp);
    
    answer.push_back(v[0][0]);
    // vector<vector>> v순회하기
    int arr_len = (int)v.size();
    for(int i = 1 ; i < arr_len ; i++){
        map<int, int> m;
        for(auto &it : answer) m[it]++;
        for(auto & it : v[i]){
            if(m[it]-1 < 0 || !m.count(it)){
                answer.push_back(it);
                break;
            }
        }
        //
    }
    //
     return answer;
}
