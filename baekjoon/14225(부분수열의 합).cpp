#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n;
int arr[20];
bool finish[2000004];
bool check[20];

void dfs(int start, int sum){
    finish[sum] = true;
    
    for(int i=start;i<n;i++){
        if(!check[i]){
            check[i] = true;
            dfs(i+1, sum+arr[i]);
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++){
        check[i] = true;
        dfs(i+1, arr[i]);
        check[i] = false;
    }
    for(int i=1;i<=2000004;i++){
        if(!finish[i]){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
