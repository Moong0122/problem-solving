#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

vector<int> graph[MAX];
int check_visit[MAX];
int k,v,e;
void bfs(int start){
    queue<int> q;
    int color = RED;
    check_visit[start] = color;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(check_visit[now] == RED) color = BLUE;
        else color = RED;
        
        int len = graph[now].size();
        for(int i=0;i<len;i++){
            int next = graph[now][i];
            if(!check_visit[next]){
                check_visit[next] = color;
                q.push(next);
            }
        }
    }
}
bool isCheck(){
    for(int i=1;i<=v;i++){
        int len = graph[i].size();
        for(int j=0;j<len;j++){
            int next = graph[i][j];
            if(check_visit[i] == check_visit[next]) return 0;
        }
    }
    return 1;
}
int main(){
    cin >> k;
    
    while(k--){
        cin >> v >> e;
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=v;i++){
            if(!check_visit[i]) bfs(i);
        }
        if(isCheck()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        for(int i=0;i<=v;i++) graph[i].clear();
        memset(check_visit, 0, sizeof(check_visit));
    }
    return 0;
}

