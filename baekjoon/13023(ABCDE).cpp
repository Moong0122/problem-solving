#include<iostream>
#include<vector>
using namespace std;
const int MAX = 2000;

vector<int> v[MAX];
bool check_visit[MAX];
int n,m;
bool answer;
void dfs(int who, int depth){
    if(answer) return;
    if(depth == 4){
        answer = true;
        return;
    }
    for(int i=0;i<v[who].size();i++){
        if(!check_visit[v[who][i]]){
            check_visit[v[who][i]] = true;
            dfs(v[who][i], depth+1);
            check_visit[v[who][i]] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int p1, p2;
        cin >> p1 >> p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }
    for(int i=0;i<n;i++){
        check_visit[i] = true;
        dfs(i,0);
        check_visit[i] = false;
        if(answer) break;
    }
    if(answer) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}
