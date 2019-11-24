#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

typedef struct{
    int cnt,
        rx,
        ry,
        bx,
        by;
} pos;

bool goalRed, goalBlue;
int findAnswer = -1;
int n,m;
char board[11][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pos> q;
void BFS();
pair<int,int> calMoving(char c, pos po, int mx, int my);
int main(){
    cin >> n >> m;

    pos T;
    T.cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                T.rx = i;
                T.ry = j;
            }
            if(board[i][j] == 'B'){
                T.bx = i;
                T.by = j;
            }
        }
    }
    q.push(T);
    BFS();

    cout << findAnswer << endl;
    return 0;
}

void BFS(){
    while(!q.empty()){
        pos tmp = q.front();
        q.pop();

        if(tmp.cnt == 10)
            break;

        for(int i=0;i<4;i++){
            goalRed = false;
            goalBlue = false;
            pos nextState;
            nextState.cnt = (tmp.cnt+1);
            pair<int,int> xx = calMoving('R',tmp,dx[i],dy[i]);
            pair<int,int> yy = calMoving('B',tmp,dx[i],dy[i]);
            nextState.rx = xx.first;
            nextState.ry = xx.second;
            nextState.bx = yy.first;
            nextState.by = yy.second;

            if(goalRed && !goalBlue){
                findAnswer = nextState.cnt;
                break;
            }
            else if(!goalRed && !goalBlue)
                q.push(nextState);
        }
        if(findAnswer != -1)
            break;
    }
}
pair<int,int> calMoving(char c, pos po, int mx, int my){
    int sx,sy;
    if(c == 'R'){
        sx = po.rx;
        sy = po.ry;
    }else{
        sx = po.bx;
        sy = po.by;
    }

    pair<int,int> p;
    bool block = false;

    while(board[sx+mx][sy+my] != '#'){
        sx+=mx;
        sy+=my;
        if(c == 'R' && sx == po.bx && sy == po.by)
            block = true;
        if(c == 'B' && sx == po.rx && sy == po.ry)
            block = true;

        if(c == 'R' && board[sx][sy] == 'O')
            goalRed = true;
        if(c == 'B' && board[sx][sy] == 'O')
            goalBlue = true;
    }
    if(block){
        sx -= mx;
        sy -= my;
    }
    p = make_pair(sx,sy);
    return p;
}
