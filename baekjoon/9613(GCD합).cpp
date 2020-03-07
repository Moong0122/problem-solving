#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long answer = 0;
vector<int> v;
vector<int> select_v;
int gcd(int num1, int num2){
    int mini = min(num1, num2);
    int maxi = max(num1, num2);
    while((maxi % mini) != 0){
        int temp = maxi % mini;
        maxi = mini;
        mini = temp;
    }
    return mini;
}
void dfs(int start, int index){
    if(index == 2){
        answer += gcd(select_v[0], select_v[1]);
        return;
    }
    for(int i = start ; i<v.size() ; i++){
        select_v.push_back(v[i]);
        dfs(i+1,index+1);
        select_v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            int m;
            cin >> m;
            v.push_back(m);
        }
        // 백트래킹 해주기
        answer = 0;
        dfs(0,0);
        // 결과값 출력
        cout << answer << '\n';
        v.clear();
        select_v.clear();
    }
    return 0;
}
