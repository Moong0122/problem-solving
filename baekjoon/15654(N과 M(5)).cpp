#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v;
vector<int> choose_v;
int check[8]; // 중복 여부를 체크해주는 배열
void dfs(int depth){
    if(depth == m){
        for(int i : choose_v) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i=0;i<v.size();i++){
        if(!check[i]){
            check[i] = true;
            choose_v.push_back(v[i]);
            dfs(depth+1);
            choose_v.pop_back();
            check[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}
