#include<iostream>
using namespace std;

bool isFind;
int board[9][9];
bool check(int index, int number){
    int i = index / 9;
    int j = index % 9;
    for(int k = 0 ; k < 9 ; k++) if(board[i][k] == number) return false;
    for(int k = 0 ; k < 9 ; k++) if(board[k][j] == number) return false;
    
    int ii = i - (i % 3);
    int jj = j - (j % 3);
    for(int a = ii ; a < ii+3 ; a++){
        for(int b = jj ; b < jj+3 ; b++){
            if(board[a][b] == number) return false;
        }
    }
    return true;
}
void searchAnswer(int index){
    if(isFind) return;
    int i = index / 9;
    int j = index % 9;
    if(index == 81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        isFind = true;
        return;
    }
    if(board[i][j] != 0) searchAnswer(index+1);
    else if(board[i][j] == 0){
        for(int num = 1 ; num <= 9 ; num++){
            if(check(index,num)){
                board[i][j] = num;
                searchAnswer(index + 1);
                board[i][j] = 0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
        }
    }
    searchAnswer(0);
    return 0;
}
