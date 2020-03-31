#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

map<int,int> m;
vector<pair<int, pair<int, int>>> result;
bool cmp(pair<int, pair<int, int>> t1, pair<int, pair<int, int>> t2){
    if((long long)t1.second.first * t2.second.second == (long long)t2.second.first * t1.second.second)
        return t1.first < t2.first;
    return (long long)t1.second.first * t2.second.second > (long long)t2.second.first * t1.second.second;
}
vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    
    for(int i=1;i<=N;i++) m[i] = 0;
    
    int total = (int)stages.size();
    for(int i=0;i<total;i++){
        m[stages[i]]++;
    }
    for(int i=1;i<=N;i++){
        if(total == 0) result.push_back({i,{0,0}});
        else{
            result.push_back({i,{m[i],total}});
            total -= m[i];
        }
    }
    sort(result.begin(), result.end(), cmp);
    for(auto it : result) answer.push_back(it.first);
    
    return answer;
}
