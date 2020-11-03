#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
bool check[200];

void connect(int ith, vector<vector<int>> com, int cnt){
    queue<int> q;
    q.push(ith);
    check[ith] = true;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        for(int i=0;i<cnt;i++){
            if(com[temp][i] == 1 && !check[i]){
                q.push(i);
                check[i] = true;
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers){
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!check[i]){
            connect(i,computers,n);
            answer++;
        }
    }
    return answer;
}

// 다시 풀어보기 + 피드백 적용

// 1. DFS (재귀 사용)
#include <string>
#include <vector>
using namespace std;

void checkConnect(int index, vector<bool>& visit, vector<vector<int>>& computers) {
    visit[index] = true;
    
    for (int i = 0; i < visit.size(); i++) {
        if (computers[index][i] && !visit[i]) {
            checkConnect(i, visit, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n,false);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if(!visit[i]) {
            answer++;
            checkConnect(i, visit, computers);
        }
    }
    
    return answer;
}

// 2. DFS (stack 사용)
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n, false);
    stack<int> s;
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            visit[i] = true;
            s.push(i);
            
            while (!s.empty()) {
                int sub = s.top();
                s.pop();
                
                for (int j = 0; j < n; j++) {
                    if (computers[sub][j] && !visit[j]) {
                        visit[j] = true;
                        s.push(j);
                    }
                }

            }

        }
    }

    return answer;
}

// 3. BFS (queue 사용)
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;

        queue<int> q;
        q.push(i);
        answer++;
        
        while (!q.empty()) {
            int sub = q.front();
            q.pop();

            if (visit[sub]) continue;
            
            visit[sub] = true;
            
            for (int j = 0; j < n; j++) {
                if (computers[sub][j] && !visit[j]) {
                    q.push(j);
                }
            }
            
        }
            
    }
    
    return answer;
}

