#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INF = 25 * 25 * 500;
int dist[26][26][4]; // y,x,dir;
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};

typedef struct{
    int y, x, cost, direction;
}state;

struct cmp {
    bool operator () (state& s1, state& s2){
        return s1.cost > s2.cost;
    }
};

int solution(vector<vector<int>> board) {
    int len = (int)board.size();
    int answer = INF;
    
    for(int i = 0 ; i < 26 ; i++)
        for(int j = 0 ; j < 26 ; j++)
            for(int k = 0 ; k < 4 ; k++) dist[i][j][k] = INF;
    
    priority_queue<state, vector<state>, cmp> pq;
    
    // 시작지점에 dist 0으로 변경 -> pq에 넣어주기
    dist[0][0][0] = 0;
    dist[0][0][1] = 0;
    dist[0][0][2] = 0;
    dist[0][0][3] = 0;
    
    pq.push({0,0,0,0});
    pq.push({0,0,0,1});
    pq.push({0,0,0,2});
    pq.push({0,0,0,3});
    
    while(!pq.empty()){
        state S = pq.top();
        pq.pop();
        
        int y = S.y;
        int x = S.x;
        int cost = S.cost;
        int dir = S.direction;
        
        // 4방향 이동
        for(int i = 0 ; i < 4 ; i++){
            int nexty = y + dy[i];
            int nextx = x + dx[i];
            
            // 다시 이전 칸으로 돌아간다면 continue 해주기
            if(abs(dir - i) == 2) continue;
            
            // 범위 벗어남
            if(nexty < 0 || nextx < 0 || nexty >= len || nextx >= len) continue;
            // 벽이 있음
            if(board[nexty][nextx] == 1) continue;
            
            int money = 100;
            if(dir != i) money += 500;
            
            int nextCost = cost + money;
            
            // 이 부분이 중요! 지금 새로 들어온 nextCost가 기존에 있던 dist보다 작다면 업데이트해준다
            if(dist[nexty][nextx][i] > nextCost){
                dist[nexty][nextx][i] = nextCost;
                pq.push({nexty, nextx, nextCost, i});
            }
        }
    }
    for(int i = 0 ; i < 4 ; i++) answer = min(answer, dist[len-1][len-1][i]);
    return answer;
}

/*
 - 다른 방법 -
 #include <string>
 #include <vector>
 #include <queue>
 using namespace std;

 typedef struct{
     int y, x, cost, dir;
 }pos;
 int dy[] = {0, -1, 0, 1};
 int dx[] = {-1, 0, 1, 0};
 int solution(vector<vector<int>> board) {
     int len = (int)board.size();
     int answer = 25 * 25 * 500;
     
     queue<pos> q;
     q.push({0,0,0,-1});
     board[0][0] = 1; // 1로 설정하여 접근하지 못하도록 해준다.
     
     while(!q.empty()){
         pos P = q.front();
         q.pop();
         
         if(P.y == len-1 && P.x == len-1){
             answer = min(answer, P.cost);
             continue;
         }
         
         for(int i = 0 ; i < 4 ; i++){
             int ny = P.y + dy[i];
             int nx = P.x + dx[i];
             if(abs(P.dir-i) == 2) continue; // 다시 뒤로 돌아가는 경우는 제외해준다.
             if(ny < 0 || nx < 0 || ny >= len || nx >= len) continue;
             if(board[ny][nx] == 1) continue;
             
             int new_cost = 0;
             // new_cost => [ny][nx]까지 오는데 걸리는 비용
             if(P.dir == -1 || P.dir == i) new_cost = P.cost + 100;
             else if(P.dir != i) new_cost = P.cost + 600;
             
             if(board[ny][nx] == 0){
                 board[ny][nx] = new_cost;
                 q.push({ny, nx, new_cost, i});
             }
             // 처음 간 곳이 아닐 경우 비용이 더 작거나 같은 경우에 큐에 넣어준다.
             if(board[ny][nx] >= new_cost){
                 board[ny][nx] = new_cost;
                 q.push({ny, nx, new_cost, i});
             }
         }
     }
     return answer;
 }
 */
