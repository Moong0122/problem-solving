#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> v;
int main(){
    cin >> n >> m; // n개의 수열, 총 합이 m이 되어야 한다
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i]; // 0~n-1까지
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += v[j];
            if(sum == m){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
