#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 801;
const int INF = 987654321;

int n,m;
vector<pair<int, int>> graph[MAX];
vector<int> search(int start, int size){
    vector<int> dist(size, INF);
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,start});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i=0;i<graph[cur].size();i++){
            int neighbor = graph[cur][i].first;
            // cur까지 가는데 필요한 cost + cur에서 neighbor로 가는데 필요한 cost
            int neighbor_value= cost + graph[cur][i].second;
            
            if(dist[neighbor] > neighbor_value){
                dist[neighbor] = neighbor_value;
                pq.push({neighbor_value,neighbor});
            }
        }
    }
    return dist;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    int tar1, tar2;
    cin >> tar1 >> tar2;
    
    vector<int> reuslt = search(1,n+1);
    vector<int> ans1 = search(tar1, n+1);
    vector<int> ans2 = search(tar2, n+1);
    
    // 1 -> tar1 -> tar2 -> n
    // 2 -> tar2 -> tar1 -> n
    int answer = min(reuslt[tar1]+ans1[tar2]+ans2[n],reuslt[tar2]+ans1[n]+ans2[tar1]);
    if(answer >= INF || answer < 0) cout << -1 << '\n';
    else cout << answer << '\n';
    return 0;
}
