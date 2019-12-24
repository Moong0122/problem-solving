#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] = {{-1,0},{0,1},{1,0},{0,-1}}; // 0,1,2,3

int n,m;
int board[51][51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    int r,c,d;
    cin >> r >> c >> d;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    int result = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{r,c},d});
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        if(board[y][x] == 0){
            board[y][x] = 2;
            result++;
        }
        q.pop();
        
        bool flag = false;
        for(int i=0;i<4;i++){
            int nextDir = (dir + (3-i)) % 4;
            int nexty = y + moveDir[nextDir].y;
            int nextx = x + moveDir[nextDir].x;
            
            if(0<=nexty && nexty < n && 0<=nextx && nextx < m){
                if(!board[nexty][nextx]){
                    q.push({{nexty,nextx},nextDir});
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            int beforey = y - moveDir[dir].y;
            int beforex = x - moveDir[dir].x;
            if((0 <= beforey && beforey < n && 0 <= beforex && beforex < m) && board[beforey][beforex] != 1)
                q.push({{beforey,beforex},dir});
            else
                break;
        }
    }
    cout << result << endl;
    return 0;
}
