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
