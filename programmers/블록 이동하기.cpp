#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int n;
bool visit[100][100][4]; // y,x,dir

// 우 하 좌 상 이동
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

// 회전하면서 지나칠 곳
int ndy[] = {-1,1,1,-1};
int ndx[] = {1,1,-1,-1};

struct Robot{
    int y, x, dir, time;
    Robot(int a, int b, int d, int t){
        y = a;
        x = b;
        dir = d;
        time = t;
    }
};

bool rangeCheck(int y, int x, int yy, int xx){
    if(x < 0 || x >= n || y < 0 || y>=n) return false;
    if(xx < 0 || xx >= n || yy < 0 || yy >=n) return false;
    return true;
}

int solution(vector<vector<int>> board){
    queue<Robot> q;
    q.push(Robot(0,0,0,0)); // ({0,0,0,0})도 가능함
    visit[0][0][0] = true;
    
    n = (int)board.size();
    int targetY = n-1;
    int targetX = n-1;
    int cnt = 0;
    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;
        int time = q.front().time;
        q.pop();
        
        // 로봇의 나머지 부분
        int yy = y + dy[dir];
        int xx = x + dx[dir];
        
        if(y == targetY && x == targetX) return time;
        if(yy == targetY && xx == targetX) return time;
        
        int ny,nx,nyy,nxx;
        
        // 상하좌우 이동
        for(int i=0;i<4;i++){
            ny = y + dy[i];
            nx = x + dx[i];
            nyy = yy + dy[i];
            nxx = xx + dx[i];
            
            if(!rangeCheck(ny, nx, nyy, nxx)) continue;
            if(visit[ny][nx][dir]) continue;
            if(board[ny][nx]==1 || board[nyy][nxx] == 1) continue;
            
            visit[ny][nx][dir] = true;
            q.push(Robot(ny,nx,dir,time+1));
        }
        
        // y,x를 축으로 90도 회전
        for(int i=0;i<4;i+=2){
            int ndir = (dir+i) % 4;
            nyy = y + dy[ndir];
            nxx = x + dx[ndir];
            
            int ry, rx;
            if(i == 1){
                // 시계 방향 회전
                ry = y + ndy[ndir];
                rx = x + ndx[ndir];
            }
            else{
                // 반시계 방향 회전
                ry = y + ndy[dir];
                rx = x + ndx[dir];
            }
            if(!rangeCheck(ry, rx, nxx, nyy)) continue;
            if(visit[y][x][ndir]) continue;
            if(board[nyy][nxx] == 1) continue;
            if(board[ry][rx]) continue;
            
            visit[x][y][dir] = true;
            q.push(Robot(y,x,ndir,time+1));
        }
        // yy,xx를 축으로 90도 회전
        dir = (dir+2)%4;
        for(int i=1;i<4;i+=2){
            int ndir = (dir+i)%4;
            ny = yy + dy[ndir];
            nx = xx + dx[ndir];
            
            int ry, rx;
            if(i == 1){
                ry = yy + ndy[ndir];
                rx = xx + ndx[ndir];
            }
            else{
                ry = yy + ndy[dir];
                rx = xx + ndx[dir];
            }
            if(!rangeCheck(ny, nx, ry, rx)) continue;
            if(board[ny][nx] == 1) continue;
            if(board[ry][rx] == 1) continue;
            
            ndir = (ndir + 2) % 4;
            if(visit[ny][nx][ndir]) continue;
            visit[ny][nx][ndir] = true;
            q.push(Robot(ny, nx, ndir, time+1));
        }
    }
    return 0;
}
