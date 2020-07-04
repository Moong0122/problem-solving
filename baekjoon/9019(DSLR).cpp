#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

int addD(int num){
    return num = (2 * num) % 10000;
}
int addS(int num){
    return num == 0 ? 9999 : num-1;
}
int addL(int num){
    return (num % 1000) * 10 + num / 1000;
}
int addR(int num){
    return (num % 10) * 1000 + num / 10;
}
string find_answer(int start, int finish){
    bool check_visit[10000] = {false,};
    queue<pair<string, int>> q; // 명령어 조합, 십진수저장
    check_visit[start] = true;
    q.push({"",start});
    
    while(!q.empty()){
        pair<string, int> tmp = q.front();
        q.pop();
        
        if(tmp.second == finish) return tmp.first;
        
        int cur;
        cur = addD(tmp.second);
        if(!check_visit[cur]){
            check_visit[cur] = true;
            q.push({tmp.first + "D", cur});
        }
        
        cur = addS(tmp.second);
        if(!check_visit[cur]){
            check_visit[cur] = true;
            q.push({tmp.first + "S", cur});
        }
        
        cur = addL(tmp.second);
        if(!check_visit[cur]){
            check_visit[cur] = true;
            q.push({tmp.first + "L", cur});
        }
        
        cur = addR(tmp.second);
        if(!check_visit[cur]){
            check_visit[cur] = true;
            q.push({tmp.first + "R", cur});
        }
    }
    return "";
}
int main(){
    int testCase, start, finish;
    cin >> testCase;
    for(int i = 0 ; i < testCase ; i++){
        cin >> start >> finish;
        cout << find_answer(start, finish) << '\n';
    }
    return 0;
}
