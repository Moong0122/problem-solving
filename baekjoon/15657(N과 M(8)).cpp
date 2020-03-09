#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int arr[8];
vector<int> select_v;
void dfs(int start,int depth){
    if(depth == m){
        for(int i : select_v) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i=start;i<n;i++){
        select_v.push_back(arr[i]);
        dfs(i,depth+1);
        select_v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    dfs(0,0);
    return 0;
}
