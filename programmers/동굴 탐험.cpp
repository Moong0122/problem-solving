// DFS
#include <string>
#include <vector>
using namespace std;
const int MAX = 200000;

bool check_visit[MAX];
int before[MAX];
int hang[MAX];
vector<int> edge[MAX];

void visit(int num){
    // 이미 방문했다면 return;
    if(check_visit[num]) return;
    
    // num 이전에 방문해야 할 방을 방문하지 않았다면 hang에 저장해두고 return한다
    // -> 이 부분이 조금 어려웠다
    // -> hang[num 이전에 방문해야 하는 방] = num;
    if(!check_visit[before[num]]){
        hang[before[num]] = num;
        return;
    }
    
    check_visit[num] = true;
    // -> 이 부분이 조금 어려웠다
    // num 다음에 방문해야 하는 방들을 방문해준다.
    visit(hang[num]);
    
    // num과 연결된 방을 방문해준다.
    for(int n : edge[num]) visit(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    // 양방향으로 통행이 가능하므로
    for(auto &it : path){
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }
    
    // it[0] -> it[1]
    for(auto &it : order) before[it[1]] = it[0]; // it[1]이전에 방문해야 할 노드는 it[0]이다
    
    // 0번 방 이전에 방문해야 하는 방이 있다면 return false해준다 (테스트 케이스에서 예외로 주어지니 추가해줄 것)
    if(before[0]) return false;
    
    // 0번 방부터 방문을 시작하므로 0번 방에 연결된 방들을 쭉 확인해준다.
    check_visit[0] = true;
    for(int n : edge[0]) visit(n);
    
    // 규칙에 맞게 모든 방을 탐험했는지 확인
    for(int i = 0 ; i < n ; i++) if(!check_visit[i]) return false;
    
    return true;
}

// BFS
/*
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 using namespace std;
 const int MAX = 200000; // 2e5

 vector<int> edge[MAX];
 set<int> s;
 int key[MAX], needKey[MAX];
 bool check_visit[MAX];

 void BFS(int node){
     queue<int> q;
     q.push(node);
     check_visit[node] = true;
     
     if(needKey[0] != 0) return; // 0보다 먼저 가야할 방이 있다면 false
     
     while(!q.empty()){
         int tmp = q.front();
         q.pop();
         needKey[key[tmp]] = 0;
         
         if(s.find(key[tmp]) != s.end()){ // s에 key[tmp] (tmp 다음에 이동해야할 방)이 있다면
             s.erase(key[tmp]); // set에서 지워주고
             q.push(key[tmp]); //  queue에 넣어줘서 다음에 이동할 수 있도록 해준다.
             check_visit[key[tmp]] = 1;
         }
         for(int it : edge[tmp]){ // tmp 방과 연결된 방들을 확인해준다.
             if(check_visit[it]) continue; // 이미 방문했다면 그냥 pass
             if(needKey[it] != 0){ // it번 방보다 먼저 나와야 하는 방이 존재한다면
                 s.insert(it); // set에 삽입해주기
                 continue;
                 // 방문은 하지 않는다 -> it번 방보다 먼저 나와야 하는 방이 있으니까 set에 넣어주고
                 // set에서 queue로 이동하기를 기다린다.
             }
             check_visit[it] = true;
             q.push(it);
         }
     }
 }

 bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
     for(auto &it : path){
         edge[it[0]].push_back(it[1]);
         edge[it[1]].push_back(it[0]);
     }
     // order[][0] -> order[][1];
     for(auto & it : order){
         key[it[0]] = it[1]; // key[먼저] = 나중
         needKey[it[1]] = it[0]; // needKey[나중] = 먼저
     }
     BFS(0);
     for(int i = 0 ; i < n ; i++) if(!check_visit[i]) return false;
     return true;
 }
 */
