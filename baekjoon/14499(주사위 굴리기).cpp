#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    int one,two,thr,four,five,six;
}diceFace;
diceFace newdice;

void rotateDice(int num);
int moveDice[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int board[21][21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,y,x,k;
    cin >> n >> m >> y >> x >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    int a;
    for(int i=0;i<k;i++){
        cin >> a;
        int nextY = y + moveDice[a-1][0];
        int nextX = x + moveDice[a-1][1];
        if(nextY >= 0 && nextX >= 0 && nextY < n && nextX < m){
            y = nextY;
            x = nextX;
            rotateDice(a);
            if(board[y][x] == 0)
                board[y][x] = newdice.six;
            else{
                newdice.six = board[y][x];
                board[y][x] = 0;
            }
            cout << newdice.one << '\n';
        }
    }
    return 0;
}
void rotateDice(int num){
    int tmp = newdice.one;
    if(num == 1){
        newdice.one = newdice.four;
        newdice.four = newdice.six;
        newdice.six = newdice.thr;
        newdice.thr = tmp;
    }else if(num == 2){
        newdice.one = newdice.thr;
        newdice.thr = newdice.six;
        newdice.six = newdice.four;
        newdice.four = tmp;
    }else if(num == 3){
        newdice.one = newdice.five;
        newdice.five = newdice.six;
        newdice.six = newdice.two;
        newdice.two = tmp;
    }else if(num == 4){
        newdice.one = newdice.two;
        newdice.two = newdice.six;
        newdice.six = newdice.five;
        newdice.five = tmp;
    }
}
