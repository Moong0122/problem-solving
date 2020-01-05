#include<iostream>
#include<queue>
using namespace std;
const int MAX = 51;

int n,l,r,ans;
bool isOut;
int dy[4] = {-1,1,0,0}, dx[4] = {0,0,1,-1};
int land[MAX][MAX];
int check_visit[MAX][MAX];
int total_check[MAX][MAX];
void BFS(int y,int x);
void makeclear();
bool isGo(int y, int x);
int main(){
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> land[i][j];
        }
    }
    while(1){
        isOut = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(total_check[i][j] == 0 && isGo(i, j))
                    BFS(i,j);
            }
        }
        if(isOut)
            break;
        ans++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                total_check[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
void BFS(int y,int x){
    int yum_cnt = 0, yum_sum = 0;
    queue<pair<int, int>> q;
    q.push({y,x});
    check_visit[y][x] = 1;
    total_check[y][x] = 1;
    
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        yum_cnt++;
        yum_sum += land[nowY][nowX];
        
        for(int i=0;i<4;i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if(nextY >= 0 && nextX >= 0 && nextY < n && nextX < n){
                if(total_check[nextY][nextX] == 0 && check_visit[nextY][nextX] == 0 && abs(land[nowY][nowX]-land[nextY][nextX]) >= l && abs(land[nowY][nowX]-land[nextY][nextX]) <= r){
                    isOut = false;
                    check_visit[nextY][nextX] = 1;
                    total_check[nextY][nextX] = 1;
                    q.push({nextY,nextX});
                }
            }
        }
    }
    int value = yum_sum / yum_cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check_visit[i][j] == 1)
                land[i][j] = value;
        }
    }
    makeclear();
}
void makeclear(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check_visit[i][j] = 0;
        }
    }
}
bool isGo(int y, int x){
    bool return_value = false;
    for(int i=0;i<4;i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY >= 0 && nextX >= 0 && nextY < n && nextX < n){
            if(total_check[nextY][nextX] == 0 && abs(land[y][x]-land[nextY][nextX]) >= l && abs(land[y][x]-land[nextY][nextX]) <= r){
                return_value = true;
            }
        }
    }
    return return_value;
}
