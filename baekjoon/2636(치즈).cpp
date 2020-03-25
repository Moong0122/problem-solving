#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, total, t, before;
int pan[101][101];
int air[101][101];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
void checkAir(){
    queue<pair<int,int>> q;
    q.push({0,0});
    air[0][0] = -1;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                if(pan[ny][nx] == 1 && air[ny][nx] != 2) air[ny][nx] = 2;
                if(air[ny][nx] == 0 && pan[ny][nx] == 0){
                    air[ny][nx] = -1;
                    q.push({ny,nx});
                }
            }
        }
    }
}
void removeCheese(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(air[i][j] == 2){
                pan[i][j] = 0;
                total--;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> pan[i][j];
            if(pan[i][j] == 1) total++;
        }
    }
    while(total != 0){ // 전체 개수가 0이 아니라면
        checkAir();
        before = total;
        removeCheese();
        t++;
        // 초기화 해주기
        memset(air, 0, sizeof(air));
    }
    cout << t << '\n' << before << '\n';
    return 0;
}

