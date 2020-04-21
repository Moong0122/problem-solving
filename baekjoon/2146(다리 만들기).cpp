#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int answer = 10001;
int land[100][100];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
void markLand(int y, int x, int number, int len){
    queue<pair<int, int>> q;
    q.push({y,x});
    land[y][x] = number;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i = 0; i< 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= len || nx >= len) continue;
            if(land[ny][nx] != 1) continue;
            land[ny][nx] = number;
            q.push({ny,nx});
        }
    }
}
int searchAnotherLand(int y, int x, int myNumber, int len){
    int check[100][100] = {0};
    queue<pair<int, int>> q;
    q.push({y,x});
    check[y][x] = 1;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= len || nx >= len) continue;
            if(land[ny][nx] != 0 && land[ny][nx] != myNumber) return check[cy][cx];
            if(land[ny][nx] == myNumber || check[ny][nx] != 0) continue;
            q.push({ny,nx});
            check[ny][nx] = check[cy][cx] + 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> land[i][j];
    
    int landCnt = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(land[i][j] == 1){
                markLand(i,j,landCnt,n);
                landCnt--;
            };
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(land[i][j] < 0){
                int temp = searchAnotherLand(i,j,land[i][j],n);
                if(temp == 0) continue;
                if(answer > temp-1) answer = temp-1;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
