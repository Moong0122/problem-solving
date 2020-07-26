#include <string>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> final_check;
set<int> tmp;

void dfs(int depth, int limit, vector<vector<int>> &arr){
    if(depth == limit){
        for(auto &it : final_check) if(it == tmp) return;
        final_check.push_back(tmp);
        return;
    }
    for(auto &it : arr[depth]){
        if(tmp.find(it) != tmp.end()) continue; // set안에 있다는 뜻이므로 그냥 넘어간다
        tmp.insert(it);
        dfs(depth+1, limit, arr);
        tmp.erase(it);
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int user_len = (int)user_id.size();
    int ban_len = (int)banned_id.size();
    
    vector<vector<int>> check;
    check.resize(ban_len);
    // user_id와 banned_id를 비교해준다
    for(int i = 0 ; i < ban_len ; i++){
        for(int j = 0 ; j < user_len ; j++){
            if(banned_id[i].size() != user_id[j].size()) continue;
            //
            bool same = true;
            for(int k = 0 ; k < banned_id[i].size() ; k++){
                if(banned_id[i][k] == '*') continue;
                if(banned_id[i][k] != user_id[j][k]) same = false;
            }
            //
            if(same) check[i].push_back(j);
        }
    }
    dfs(0, ban_len, check);
    return (int)final_check.size();
}
