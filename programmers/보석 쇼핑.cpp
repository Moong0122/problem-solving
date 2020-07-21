#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<string, int> m;
int front = 100000, back = -1;
bool isFull = false;

void check_gems(){
    int left = 100000, right = -1;
    
    for(auto it=m.begin() ; it != m.end() ; it++){
        if(it->second > right) right = it->second;
        if(it->second < left) left = it->second;
    }
    if(abs(front-back) >= abs(left-right)){
        front = left;
        back = right;
    }
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int len = (int)gems.size();
    int total_gems_kinds = 0;
    
    for(int i = 0 ; i < len ; i++) m[gems[i]] = -1;
    
    // 보석 종류의 개수를 파악해야 한다.
    for(auto it = m.begin() ; it != m.end() ; it++) total_gems_kinds++;
    
    // 뒤에서부터 for문을 돌면서 최소 구간 발견
    for(int i = len-1 ; i >= 0 ; i--){
        if(m[gems[i]] == -1) // 새로 추가된 보석의 종류라면
        {
            m[gems[i]] = i;
            total_gems_kinds--;
            if(total_gems_kinds == 0) isFull = true;
        }
        else // 기존에 발견된 보석의 종류라면
        {
            m[gems[i]] = i;
        }
        
        if(isFull) check_gems();
    }
    answer.push_back(front+1);
    answer.push_back(back+1);
    return answer;
}

/*
 #include <string>
 #include <vector>
 #include <unordered_map>
 #include <set>
 using namespace std;

 set<string> gems_list;
 unordered_map<string, int> m;

 vector<int> solution(vector<string> gems) {
     int left = 0, right = 0, gems_cnt;
     int len = (int)gems.size();
     
     vector<int> answer(2);
     answer[0] = 0;
     answer[1] = len-1;
     
     for(int i = 0 ; i < len ; i++) gems_list.insert(gems[i]);
     gems_cnt = (int)gems_list.size(); // 보석 종류의 개수
     
     m[gems[0]]++;
     while(1){
         if(m.size() == gems_cnt){
             if(answer[1] - answer[0] > right - left){
                 answer[1] = right;
                 answer[0] = left;
             }
             if(left == right) break;
             else{
                 m[gems[left]]--;
                 if(m[gems[left]] == 0) m.erase(gems[left]);
                 left++;
             }
         }
         else if(m.size() > gems_cnt){
             if(left + 1 >= len) break;
             else{
                 m[gems[left]]--;
                 if(m[gems[left]] == 0) m.erase(gems[left]);
                 left++;
             }
         }
         else if(m.size() < gems_cnt){
             if(right + 1 >= len) break;
             else{
                 m[gems[++right]]++;
             }
         }
     }
     answer[0]++;
     answer[1]++;
     return answer;
 }
 */
