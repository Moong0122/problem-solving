#include<iostream>
#include<vector>
using namespace std;
const int MAX = 13;

struct mal {
    int y,x,d;
    bool isBottom;
} m[11];

int chess[MAX][MAX];
vector<int> check[MAX][MAX];
int chessSize, malCnt;
int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};
int turn(int n){
    if(n % 2 == 0) return n-1;
    return n+1;
}
int move(int n){
    int ny = m[n].y + dy[m[n].d];
    int nx = m[n].x + dx[m[n].d];
    
    // 경계를 넘거나 파란색 칸이라면
    if(ny <= 0 || ny > chessSize || nx <= 0 || nx > chessSize || chess[ny][nx] == 2){
        m[n].d = turn(m[n].d);
        // 방향 전환 후 다음 위치를 확인해주자
        ny = m[n].y + dy[m[n].d];
        nx = m[n].x + dx[m[n].d];
        
        if(ny <= 0 || ny > chessSize || nx <= 0 || nx > chessSize || chess[ny][nx] == 2)
            return 0;
    }
    vector<int> &cur = check[m[n].y][m[n].x];
    vector<int> &next = check[ny][nx];
    // 다음 칸에 흰색 칸이라면
    if(chess[ny][nx] == 0){
        // 만약 이동할 칸에 말들이 있다면 지금 이 말은 제일 밑에 있지 않으므로 false로 바꿔준다
        if(!next.empty()) m[cur.front()].isBottom = false;
        next.insert(next.end(), cur.begin(), cur.end());
    }
    // 빨간색 칸이라면
    else if(chess[ny][nx] == 1){
        next.insert(next.end(), cur.rbegin(),cur.rend());
        m[next.back()].isBottom = false;
        m[next.front()].isBottom = true;
    }
    m[next.front()].y = m[next.back()].y = ny;
    m[next.front()].x = m[next.back()].x = nx;
    cur.clear();
    return next.size();
}
int simulation(){
    for(int turn = 1; turn <= 1000 ; turn++){
        for(int i = 1 ; i <= malCnt ; i++){
            if(m[i].isBottom){
                // i 몇 번째 mal을 이동하겠다 -> move(i)
                // move를 통해 내가 이동하고 나서 몇 칸이 쌓여있는지 알 수 있다
                int tmp = move(i);
                if(tmp >= 4)
                    return turn;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> chessSize >> malCnt;
    for(int i=1;i<=chessSize;i++)
        for(int j=1;j<=chessSize;j++)
            cin >> chess[i][j];
    // 1번부터 malCnt까지의 말들 초기 설정
    for(int i=1;i<=malCnt;i++){
        cin >> m[i].y >> m[i].x >> m[i].d;
        m[i].isBottom = true;
        check[m[i].y][m[i].x].push_back(i);
    }
    cout << simulation() << '\n';
    return 0;
}

