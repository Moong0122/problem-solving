#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
#define MAX 1001
using namespace std;

struct p{
    int num;
    int value;
};
struct cmp {
    bool operator()(p t1, p t2){
        return t1.value > t2.value;
    }
};
vector<pair<int,int>> v[MAX];
int cost[MAX];
int total[MAX];
int n,m,x;
void search(int start){
    priority_queue<p,vector<p>, cmp> pq;
    for(int i=1;i<=n;i++) cost[i] = INF;
    cost[start] = 0;
    
    pq.push({start,0});
    
    while(!pq.empty()){
        int cur = pq.top().num;
        int cur_value = pq.top().value;
        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int next_value = v[cur][i].second;
            if(cost[next] > cur_value + next_value){
                cost[next] = cur_value + next_value;
                pq.push({next,cur_value + next_value});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    search(x); // X에서 각자의 집으로 가는 거리
    for(int i=1;i<=n;i++){
        total[i] += cost[i];
    }
    for(int i=1;i<=n;i++){ // n명의 학생들 X까지의 거리 체크해준다
        search(i);
        total[i] += cost[x];
    }
    int answer=total[1];
    for(int i=1;i<=n;i++){
        answer = max(answer, total[i]);
    }
    cout << answer << '\n';
    return 0;
}
