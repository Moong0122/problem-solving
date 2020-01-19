#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 51;
vector<int> airMachine;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
void spread();
void circulateUp();
void circulateDown();
int place[MAX][MAX], check[MAX][MAX];
int r,c,t;
int main(){
    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> place[i][j];
            if(place[i][j] == -1){
                airMachine.push_back(i);
                place[i][j] = 0;
            }
        }
    }
    while(t > 0){
        spread();
        circulateUp();
        circulateDown();
        t--;
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(place[i][j] > 0)
                ans += place[i][j];
        }
    }
    cout << ans << endl;
}
void circulateUp(){
    int Y = airMachine[0];
    for(int i=Y;i>0;i--){
        place[i][0] = place[i-1][0];
    }
    place[Y][0] = 0;
    for(int i=0;i<c-1;i++){
        place[0][i] = place[0][i+1];
    }
    for(int i=0;i<Y;i++){
        place[i][c-1] = place[i+1][c-1];
    }
    for(int i=c-1;i>0;i--){
        place[Y][i] = place[Y][i-1];
    }
}
void circulateDown(){
    int Y = airMachine[1];
    for(int i=Y;i<r-1;i++){
        place[i][0] = place[i+1][0];
    }
    place[Y][0] = 0;
    for(int i=0;i<c-1;i++){
        place[r-1][i] = place[r-1][i+1];
    }
    for(int i=r-1;i>Y;i--){
        place[i][c-1] = place[i-1][c-1];
    }
    for(int i=c-1;i>0;i--){
        place[Y][i] = place[Y][i-1];
    }
}
void spread(){
    queue<pair<int, int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(place[i][j] > 0)
                q.push({i,j});
        }
    }
    check[airMachine[0]][0] = -1;
    check[airMachine[1]][0] = -1;
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        
        int value = place[tmp.first][tmp.second] / 5;
        for(int i=0;i<4;i++){
            int yy = tmp.first + dy[i];
            int xx = tmp.second + dx[i];
            if(yy >= 0 && yy < r && xx >= 0 && xx < c && check[yy][xx] != -1){
                check[yy][xx] += value;
                place[tmp.first][tmp.second] -= value;
            }
        }
    }
    check[airMachine[0]][0] = 0;
    check[airMachine[1]][0] = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            place[i][j] += check[i][j];
            check[i][j] = 0;
        }
    }
}
