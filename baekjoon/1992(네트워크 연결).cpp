#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;

struct info {
    int num, value;
};
struct cmp {
    bool operator()(info t1, info t2){
        return t1.value > t2.value;
    }
};
bool visit[1001];
int dist[1001];
vector<pair<int, int>> computer[1001];
int n,m;
void search(int start){
    // 초기 설정 (1번 ~ n번까지의 컴퓨터)
    for(int i=1 ; i<= n; i++) dist[i] = INF;
    dist[start] = 0;
    
    priority_queue<info, vector<info>, cmp> q;
    q.push({start,0});
    
    while(!q.empty()){
        int curNum = q.top().num;
        int curValue = q.top().value;
        q.pop();
        visit[curNum] = true;
        
        for(int i=0;i<computer[curNum].size();i++){
            int nNum = computer[curNum][i].first; // 다음으로 이동할 컴퓨터의 번호
            int nValue = computer[curNum][i].second;
            if(!visit[nNum]){
                if(dist[nNum] > nValue){
                    q.push({nNum, nValue});
                    dist[nNum] = nValue;
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
        computer[a].push_back({b,c});
        computer[b].push_back({a,c});
    }
    search(1);
    int result = 0;
    for(int i=1;i<=n;i++) result += dist[i];
    cout << result << '\n';
    return 0;
}
