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


// 풀이 보고 공부하기
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 로봇의 위치와 자세를 저장하기 위한 자료형
// 가로 방향인 경우 (r, c)는 왼쪽, 세로 방향인 경우 (r, c)는 위쪽
class robot {
    public:
        int r = 0; // row
        int c = 0; // column
        int d = 0; // direction (0: 가로, 1: 세로)
    
    robot(int _r, int _c, int _d) : r(_r), c(_c), d(_d) {}
};

int solution(vector<vector<int>> board) {
    int N = (int)board.size();

    vector<vector<vector<int>>> check(N, vector<vector<int>>(N, vector<int>(2, -1)));
    
    // 오른쪽, 아래, 왼쪽, 위
    int dc[4] = {1, 0, -1, 0};
    int dr[4] = {0, 1, 0, -1};
    
    queue<robot> q;
    q.push(robot(0, 0, 0)); // (0, 0), 가로 방향
    check[0][0][0] = 0;
    
    while (!q.empty()) {
        int cur_r1 = q.front().r;
        int cur_c1 = q.front().c;
        int cur_d1 = q.front().d;
        
        // 방향을 토대로 로봇의 나머지 좌표 확인
        int cur_r2 = cur_r1 + dr[cur_d1];
        int cur_c2 = cur_c1 + dc[cur_d1];
        
        int cost = check[cur_r1][cur_c1][cur_d1];
        q.pop();
        
        // 만약 목표 지점에 도착했다면 종료하기
        if (cur_r1 == N - 1 && cur_c1 == N - 2 && cur_d1 == 0) break;
        if (cur_r1 == N - 2 && cur_c1 == N - 1 && cur_d1 == 1) break;
        
        // 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            // 이동했을 때 로봇의 위치를 확인
            int next_r1 = cur_r1 + dr[i];
            int next_c1 = cur_c1 + dc[i];
            
            int next_r2 = cur_r2 + dr[i];
            int next_c2 = cur_c2 + dc[i];
            
            // 로봇이 칸의 범위를 벗어나면 continue 해준다.
            if (next_r1 < 0 || next_r1 >= N || next_c1 < 0 || next_c1 >= N) continue;
            if (next_r2 < 0 || next_r2 >= N || next_c2 < 0 || next_c2 >= N) continue;
            // 로봇이 있는 위치에 벽이 있다면 continue 해준다.
            if (board[next_r1][next_c1] == 1 || board[next_r2][next_c2] == 1) continue;
            // 이미 방문한 적이 있다면 continue 해준다.
            if (check[next_r1][next_c1][cur_d1] != -1) continue;
            
            // 위 조건을 다 통과했다면 큐에 넣어주고 위치 업데이트 해준다.
            check[next_r1][next_c1][cur_d1] = cost + 1;
            q.push(robot(next_r1, next_c1, cur_d1));
        }
        
        // 회전
        for (int t = 0; t < 2; t++) {
            // 로봇의 두부분 이동이 아닌 한 부분을 고정하고, 그 부분을 기준으로 상하좌우 이동해주고 올바른 회전인지 확인해준다
            for (int i = 0; i < 4; i++) {
                int next_r1 = cur_r1; // 고정
                int next_c1 = cur_c1; // 고정
                int next_r2 = cur_r1 + dr[i]; // 회전
                int next_c2 = cur_c1 + dc[i]; // 회전
                
                // 만약 칸의 범위를 벗어나면 continue해준다.
                if (next_r2 < 0 || next_r2 >= N || next_c2 < 0 || next_c2 >= N) continue;
                
                int dist_r = abs(cur_r2 - next_r2);
                int dist_c = abs(cur_c2 - next_c2);
                
                // 시계, 반시계 방향으로 90도 회전한 경우가 아니거나
                if (dist_r != 1 || dist_c != 1) continue;
                // 회전하여 이동할 지점이 비어있지 않은 경우
                if (board[next_r2][next_c2] == 1) continue;
                
                // 회전 시 대각 위치가 비어있지 않은 경우 -> 이 부분이 어렵다.
                // ^의 기능 -> XOR 연산 (2주차 나머지 한 점 구할 때 사용된 방법)
                int diag_r = cur_r1 ^ cur_r2 ^ next_r2;
                int diag_c = cur_c1 ^ cur_c2 ^ next_c2;
                
                // 회전 시 대각 위치가 비어있지 않은 경우 continue해준다.
                if (board[diag_r][diag_c] == 1) continue;
                
                // 회전 후, 좌표 정렬 및 direction 조정 후 큐에 등록 (기준점 체크해주는 코드)
                if (next_r1 > next_r2) swap(next_r1, next_r2);
                if (next_c1 > next_c2) swap(next_c1, next_c2);
                int next_d1 = (cur_d1 == 0) ? 1 : 0;
                
                // 기존에 방문한 적이 없다면 큐에 넣어준다.
                if (check[next_r1][next_c1][next_d1] == -1) {
                    check[next_r1][next_c1][next_d1] = cost + 1;
                    q.push(robot(next_r1, next_c1, next_d1));
                }
            }
            
            swap(cur_r1, cur_r2);
            swap(cur_c1, cur_c2);
        }
    }
    
    int ans = min(check[N - 2][N - 1][1], check[N - 1][N - 2][0]);
    if (ans == -1)
        ans = max(check[N - 2][N - 1][1], check[N - 1][N - 2][0]);
    return ans;
}

