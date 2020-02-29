#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 51;
const int MAX_ANSWER = 99999999;

vector<pair<int, int>> virus;
vector<pair<int, int>> chooseVirus;
queue<pair<int, int>> q;

int result = MAX_ANSWER;
int lab[MAX][MAX], check[MAX][MAX];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
int labSize, virusCnt;
void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < labSize && nx >= 0 && nx < labSize){
                if(lab[ny][nx] != 1 && check[ny][nx] == -1){
                    check[ny][nx] = check[y][x] + 1;
                    q.push({ny,nx});
                }
            }
        }
    }
    bool isFinish = true;
    int mmax = 0;
    for(int i=0;i<labSize;i++){
        for(int j=0;j<labSize;j++){
            if(lab[i][j] == 0){
                if(check[i][j] == -1 ){
                    isFinish = false;
                    break;
                }else{
                    mmax = max(mmax,check[i][j]);
                }
            }
        }
    }
    if(isFinish) result = min(result, mmax);
}
void DFS(int start, int limit){
    if(limit == virusCnt){
        for(int i=0;i<virusCnt;i++) q.push(chooseVirus[i]);
        // check 배열 초기화 1. 전체 -1로 덮기
        for(int i=0;i<labSize;i++)
            for(int j=0;j<labSize;j++)
                check[i][j] = -1;
        // 2. 선택한 바이러스에 대해 시작을 0으로 설정해주기
        for(int i=0;i<virusCnt;i++){
            check[chooseVirus[i].first][chooseVirus[i].second] = 0;
        }
        BFS();
        return;
    }
    for(int i=start;i<virus.size();i++){
        chooseVirus.push_back(virus[i]);
        DFS(i+1, limit+1);
        chooseVirus.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> labSize >> virusCnt;
    for(int i=0;i<labSize;i++){
        for(int j=0;j<labSize;j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2) virus.push_back({i,j});
        }
    }
    DFS(0, 0);
    if(result == MAX_ANSWER) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}
