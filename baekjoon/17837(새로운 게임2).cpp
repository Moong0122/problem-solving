#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 13;

struct mal {
    int y,x,d;
};
mal m[11];

int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};
vector<int> check[MAX][MAX];
int chess[MAX][MAX];
int chessSize, malCnt;
int turn(int num){
    if(num % 2 == 0) return num-1;
    return num+1;
}
int move(int num){
    int ny = m[num].y + dy[m[num].d];
    int nx = m[num].x + dx[m[num].d];
    
    if(ny < 1 || ny > chessSize || nx < 1 || nx > chessSize || chess[ny][nx] == 2){
        m[num].d = turn(m[num].d);
        ny = m[num].y + dy[m[num].d];
        nx = m[num].x + dx[m[num].d];
        if(ny < 1 || ny > chessSize || nx < 1 || nx > chessSize || chess[ny][nx] == 2)
            return 0;
    }
    vector<int> &cur = check[m[num].y][m[num].x];
    vector<int> &next = check[ny][nx];
    auto s = find(cur.begin(),cur.end(),num);
    
    if(chess[ny][nx] == 1)
        reverse(s,cur.end());
    
    // 같이 오는 말들의 좌표 바꿔주고 next에 넣어주기
    for(auto it = s; it != cur.end(); it++){
        m[*it].y = ny;
        m[*it].x = nx;
        next.push_back(*it);
    }
    cur.erase(s,cur.end());
    return (int)next.size();
}
int solution(){
    for(int turn=1;turn <= 1000 ; turn++){
        for(int i=1;i<=malCnt;i++){
            int temp = move(i);
            if(temp >= 4) return turn;
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
    for(int i=1;i<=malCnt;i++){
        cin >> m[i].y >> m[i].x >> m[i].d;
        check[m[i].y][m[i].x].push_back(i);
    }
    cout << solution() << '\n';
    return 0;
}
