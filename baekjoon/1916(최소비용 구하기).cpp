#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
#define INF 987654321
using namespace std;

struct ci{
    int go;
    int value;
};
struct cmp{
    bool operator()(ci t1, ci t2){
        return t1.value > t2.value;
    }
};
vector<pair<int, int>> city[MAX];
bool check_vist[MAX];
int cost[MAX];
int n,m,start, arrive;
void bfs(int st){
    // st에 대한 초기 설정
    priority_queue<ci,vector<ci>,cmp> pq;
    check_vist[st] = true;
    for(int i=1;i<=n;i++) cost[i] = INF;
    cost[st] = 0;
    pq.push({st,0});
    
    while(!pq.empty()){
        int cur_lo = pq.top().go;
        int cur_cost = pq.top().value;
        pq.pop();
        for(int i=0;i<city[cur_lo].size();i++){
            int next_lo = city[cur_lo][i].first;
            int next_cost = city[cur_lo][i].second;
            if(!check_vist[next_lo]){
                if(cost[next_lo] > cur_cost + next_cost){
                    cost[next_lo] = cur_cost + next_cost;
                    pq.push({next_lo, cur_cost + next_cost});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        city[a].push_back({b,c}); // 도착지점과 버스 비용
    }
    cin >> start >> arrive;
    bfs(start);
    cout << cost[arrive] << '\n';
    return 0;
}
