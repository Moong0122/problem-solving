#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> choose_v;
int n,m;
void dfs(int depth){
    if(depth == m){
        for(int i : choose_v) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        choose_v.push_back(v[i]);
        dfs(depth+1);
        choose_v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}
