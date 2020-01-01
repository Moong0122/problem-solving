#include<iostream>
#include<queue>
using namespace std;

const int MAX = 20;
int n, board[MAX][MAX], biggest = -1;
void DFS(int num);
void nextMove(int num);
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    DFS(0);
    cout << biggest << endl;
    return 0;
}
void DFS(int num){
    if(num == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                biggest = max(biggest, board[i][j]);
            }
        }
        return;
    }
    // 현재 지금 보드상태 저장
    int saveBoard[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            saveBoard[i][j] = board[i][j];
        }
    }
    for(int i=0;i<4;i++){
        nextMove(i);
        DFS(num+1);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                board[j][k] = saveBoard[j][k];
            }
        }
    }
}
void nextMove(int num){
    queue<int> q;
    switch (num) {
        case 0:
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                    }
                }
                int idx = 0;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    if(board[i][idx] == 0)
                        board[i][idx] = tmp;
                    else if(board[i][idx] == tmp){
                        board[i][idx] *= 2;
                        idx++;
                    }else{
                        idx++;
                        board[i][idx] = tmp;
                    }
                }
            }
        break;
        case 1:
            for(int i=0;i<n;i++){
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                    }
                }
                int idx = n-1;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    if(board[i][idx] == 0)
                        board[i][idx] = tmp;
                    else if(board[i][idx] == tmp){
                        board[i][idx] *= 2;
                        idx--;
                    }else{
                        idx--;
                        board[i][idx] = tmp;
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[j][i]){
                    q.push(board[j][i]);
                    board[j][i] = 0;
                    }
                }
                int idx = 0;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    if(board[idx][i] == 0)
                        board[idx][i] = tmp;
                    else if(board[idx][i] == tmp){
                        board[idx][i] *= 2;
                        idx++;
                    }else{
                        idx++;
                        board[idx][i] = tmp;
                    }
                }
            }
            break;
        case 3:
            for(int i=0;i<n;i++){
                for(int j=n-1;j>=0;j--){
                    if(board[j][i]){
                    q.push(board[j][i]);
                    board[j][i] = 0;
                    }
                }
                int idx = n-1;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    if(board[idx][i] == 0)
                        board[idx][i] = tmp;
                    else if(board[idx][i] == tmp){
                        board[idx][i] *= 2;
                        idx--;
                    }else{
                        idx--;
                        board[idx][i] = tmp;
                    }
                }
            }
            break;
    }
}
