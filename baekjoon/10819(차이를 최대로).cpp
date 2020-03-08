#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int MAX = 8;

vector<int> v;
bool check[MAX];
int arr[MAX];
int n, result = -1;
void dfs(int depth){
    if(depth == n){
        int sum = 0;
        for(int i=1;i<n;i++) sum += abs(v[i-1]-v[i]);
        if(sum > result) result = sum;
        return;
    }
    for(int i=0;i<n;i++){
        if(!check[i]){
            v.push_back(arr[i]);
            check[i] = true;
            dfs(depth+1);
            check[i] = false;
            v.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    dfs(0);
    cout << result << '\n';
    return 0;
}
