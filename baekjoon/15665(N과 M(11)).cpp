#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

set<vector<int>> s;
vector<int> choose_v;
int arr[7];
int n,m;
void dfs(int depth){
    if(depth == m){
        s.insert(choose_v);
        return;
    }
    for(int i=0;i<n;i++){
        choose_v.push_back(arr[i]);
        dfs(depth+1);
        choose_v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    dfs(0);
    for(auto i : s){
        for(auto j : i) cout << j << " ";
        cout << '\n';
    }
    return 0;
}
