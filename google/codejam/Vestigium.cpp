// map -> solving
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#define MAX 100
using namespace std;

int board[MAX][MAX];

int calK(int len){
    int answer = 0;
    for(int i=0;i<len;i++) answer += board[i][i];
    return answer;
}
int calR(int len){
    int answer = 0;
    for(int i=0;i<len;i++){
        int cnt = 0;
        map<int, bool> m;
        for(int j=0;j<len;j++){
            m[board[i][j]] = true;
        }
        for(auto it = m.begin() ; it != m.end() ; it++) cnt++;
        if(cnt != len) answer++;
    }
    return answer;
}
int calC(int len){
    int answer = 0;
    for(int i=0;i<len;i++){
        int cnt = 0;
        map<int, bool> m;
        for(int j=0;j<len;j++){
            m[board[j][i]] = true;
        }
        for(auto it = m.begin() ; it != m.end() ; it++) cnt++;
        if(cnt != len) answer++;
    }
    return answer;
}
void input(int len){
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            cin >> board[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i=1;i<=testCase;i++){
        int boardSize;
        cin >> boardSize;
        input(boardSize);
        int dia = calK(boardSize);
        int r = calR(boardSize);
        int c = calC(boardSize);
        cout << "Case #" << i << ": " << dia << " " << r << " " << c << '\n';
        memset(board, 0, sizeof(board));
    }
    return 0;
}
