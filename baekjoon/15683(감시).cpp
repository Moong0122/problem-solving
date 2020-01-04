#include<iostream>
#include<vector>
using namespace std;
const int MAX = 8;

vector<pair< pair<int, int>, int>> v;
void shineBlock(int y, int x, int where);
void changeDir(int cctvNum, int number, int y, int x);
void DFS(int level);
int board[MAX][MAX], n, m, len;
int minimum = MAX * MAX;
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5){
                v.push_back({{i,j},board[i][j]});
            }
        }
    }
    len = v.size();
    DFS(0);
    cout << minimum << endl;
    return 0;
}
void DFS(int level){
    if(level == len){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0)
                    cnt++;
            }
        }
        minimum = min(cnt, minimum);
        return;
    }
    // 현재 상태를 저장해주는 배열 선언
    int currentState[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            currentState[i][j] = board[i][j];
        }
    }
    // 각 카메라의 회전 전환할 수 있는 조합들이 각각 4개씩 있다.
    for(int i=0;i<4;i++){
        // 현재 카메라 종류(1~5) 몇번째 조합을 줘야하는지(0~3) 현재 위치 y x
        changeDir(v[level].second,i,v[level].first.first,v[level].first.second);
        DFS(level+1);
        // DFS에서 돌아온 후 현재 상태로 돌려주는 역할
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = currentState[i][j];
            }
        }
    }
}
void changeDir(int cctvNum, int number, int y, int x){
    if(cctvNum == 1){
        shineBlock(y, x, number);
    }else if(cctvNum == 2){
        shineBlock(y, x, number);
        shineBlock(y, x, (number+2)%4);
    }else if(cctvNum == 3){
        shineBlock(y, x, number);
        shineBlock(y, x, (number+1)%4);
    }else if(cctvNum == 4){
        shineBlock(y, x, number);
        shineBlock(y, x, (number+1)%4);
        shineBlock(y, x, (number+2)%4);
    }else if(cctvNum == 5){
        shineBlock(y, x, 0);
        shineBlock(y, x, 1);
        shineBlock(y, x, 2);
        shineBlock(y, x, 3);
    }
}
void shineBlock(int y, int x, int where){
    int dy = mov[where][0];
    int dx = mov[where][1];
    
    while(y+dy >= 0 && x+dx >= 0 && y+dy < n && x+dx < m){
        y += dy;
        x += dx;
        if(board[y][x] == 6)
            break;
        if(board[y][x] == 0)
            board[y][x] = -1;
    }
}
