#include<iostream>
#include<vector>
using namespace std;
const int MAX = 20;

int n, target, cnt;
int arr[MAX];
vector<int> v;
void dfs(int start, int depth){
    if(depth <= n){
        if(v.size() != 0){
            int sum = 0;
            for(int i : v) sum += i;
            if(sum == target) cnt++;
        }
        if(depth == n) return;
    }
    
    for(int i=start;i<n;i++){
        v.push_back(arr[i]);
        dfs(i+1,depth+1);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> target;
    for(int i=0;i<n;i++) cin >> arr[i];
    dfs(0,0);
    cout << cnt << '\n';
    return 0;
}
