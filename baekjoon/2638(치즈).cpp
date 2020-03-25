#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int monun[100][100];
int air[100][100];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
int n,m,total,t;
int howManyAttach(int y, int x){
    int attach = 0;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && nx >= 0 && ny < n && nx < m){
            if(air[ny][nx] == -1) attach++;
        }
    }
    return attach;
}
void checkAir(){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
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
                if(monun[ny][nx] == 0 && air[ny][nx] == 0){ // 치즈가 없고 방문도 안 했다면
                    air[ny][nx] = -1;
                    q.push({ny,nx});
                }
                if(monun[ny][nx] == 1 && air[ny][nx] == 0){ // 치즈가 있는데 방문 아직 못 했다면
                    air[ny][nx] = 1;
                    v.push_back({ny,nx});
                }
            }
        }
    }
    for(int i=0;i<v.size();i++){
        int cy = v[i].first;
        int cx = v[i].second;
        if(howManyAttach(cy, cx) >= 2) air[cy][cx] = 2;
    }
}
void removeCheese(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(air[i][j] == 2){
                monun[i][j] = 0;
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
            cin >> monun[i][j];
            if(monun[i][j] == 1) total++;
        }
    }
    while(total != 0){
        checkAir();
        removeCheese();
        t++;
        memset(air, 0, sizeof(air));
    }
    cout << t << '\n';
    return 0;
}
