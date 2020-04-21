#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

char land[50][50];
int answer = -1;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
void findDis(int y, int x, int sero, int garo){
    int check[50][50];
    memset(check,0,sizeof(check));
    
    queue<pair<int, int>> q;
    q.push({y,x});
    check[y][x] = 1;
    
    int maxNumber = 0;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= sero || nx >= garo) continue;
            if(land[ny][nx] == 'W' || check[ny][nx] != 0) continue;
            q.push({ny,nx});
            check[ny][nx] = check[cy][cx] + 1;
            if(check[ny][nx] > maxNumber) maxNumber = check[ny][nx];
        }
    }
    if(answer < maxNumber-1) answer = maxNumber-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> land[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(land[i][j] == 'W') continue;
            findDis(i,j,n,m);
        }
    }
    cout << answer << '\n';
    return 0;
}
