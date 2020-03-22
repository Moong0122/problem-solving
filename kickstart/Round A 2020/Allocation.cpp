#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cost;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i=1;i<=testCase;i++){
        int n, b;
        cin >> n >> b;
        cost.resize(n);
        
        for(int i=0;i<n;i++) cin >> cost[i];
        sort(cost.begin(), cost.end());
        
        int answer = 0;
        for(int it : cost){
            if(it > b) break;
            else{
                b -= it;
                answer++;
            }
        }
        cout << "Case #" << i << ": " << answer << '\n';
        cost.clear();
    }
    return 0;
}
