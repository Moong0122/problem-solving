#include<iostream>
using namespace std;
const int MAX = 10;

int city[MAX][MAX];
bool check[MAX];
int n, cost, answer = 99999999;
void dfs(int depth, int current, int finish){
    if(depth == n){
        if(current == finish) answer = min(answer, cost);
        return;
    }
    for(int i=0;i<n;i++){
        if(city[current][i] != 0 && !check[i]){ // 그 마을로 갈 수 있는 길이 존재하고, 방문 X 일때
            cost += city[current][i];
            check[i] = true;
            dfs(depth+1, i, finish);
            check[i] = false;
            cost -= city[current][i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin >> city[i][j];
    
    for(int i=0;i<n;i++){
        dfs(0,i,i);
        // 초기화 작업
        cost = 0;
        for(int j=0;j<n;j++) check[j] = false;
    }
    cout << answer << '\n';
    return 0;
}
