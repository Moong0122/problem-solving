#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 50;

pair<int,int> go;
vector<pair<int, int>> water;
int r,c;
char land[MAX][MAX];
int check[MAX][MAX];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int bfs(){
    queue<pair<int, int>> q;
    
    for(int i=0;i<water.size();i++){
        check[water[i].first][water[i].second] = -1;
        q.push({water[i].first, water[i].second});
    }
    q.push(go);
    check[go.first][go.second] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int yy,xx;
        if(check[y][x] == -1){
            for(int i=0;i<4;i++){
                yy = y + dy[i];
                xx = x + dx[i];
                if(yy >= 0 && yy < r && xx >= 0 && xx < c ){
                    if(land[yy][xx] == '.' && check[yy][xx] == 0){
                        check[yy][xx] = -1;
                        q.push({yy,xx});
                    }
                }
            }
        }
        else if(check[y][x] > 0){
            for(int i=0;i<4;i++){
                yy = y + dy[i];
                xx = x + dx[i];
                if(yy >= 0 && yy < r && xx >= 0 && xx < c){
                    if(land[yy][xx] == '.' && check[yy][xx] == 0){
                        check[yy][xx] = check[y][x] + 1;
                        q.push({yy,xx});
                    }
                    if(land[yy][xx] == 'D') return check[y][x];
                }
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> land[i][j];
            if(land[i][j] == 'S') go = make_pair(i,j);
            if(land[i][j] == '*') water.push_back({i,j});
        }
    }
    int result = bfs();
    if(!result) cout << "KAKTUS" << '\n';
    else cout << result << '\n';
    return 0;
}
