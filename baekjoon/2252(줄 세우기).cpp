// 위상 정렬
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAX 32001
using namespace std;

int main(){
    int n, m, degree[MAX], from, to;
    cin >> n >> m;
    vector<int> v[MAX]; // 처음에는 vector<vector<int>> v라고 풀었는데 그 부분이 틀린 것 같다!
    
    for(int i = 0 ; i < m; i++){
        cin >> from >> to;
        v[from].push_back(to);
        degree[to]++;
    }
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
        if(degree[i] == 0) q.push(i);
    
    while(!q.empty()){ // 꼭 기존의 풀이 방법처럼 for(int i = 1 ; i <= n ; i++)로 풀지 않아도 된다!
        int tmp = q.front();
        q.pop();
        
        cout << tmp << " ";
        for(int i = 0 ; i < (int)v[tmp].size() ; i++){
            degree[v[tmp][i]]--;
            if(degree[v[tmp][i]] == 0) q.push(v[tmp][i]);
        }
    }
    return 0;
}
