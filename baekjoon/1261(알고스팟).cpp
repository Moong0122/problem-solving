#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 101;

int n,m;
int map[MAX][MAX];
int check[MAX][MAX];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
priority_queue<pair<int, pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> m >> n;
    memset(check, -1, sizeof(check));
    
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<m;j++){
            map[i][j] = str[j] - 48;
        }
    }
    pq.push({0,{0,0}});
    
    while(!pq.empty()){
        int cnt = -pq.top().first; // 숫자가 낮은 것이 높은 우선순위를 갖도록 해준다
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(check[y][x] != -1) continue;
        check[y][x] = cnt;
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                if(check[ny][nx] == -1){
                    if(map[ny][nx] == 1){
                        pq.push({-(cnt+1),{ny,nx}});
                    }else{
                        pq.push({-cnt,{ny,nx}});
                    }
                }
            }
        }
    }
    cout << check[n-1][m-1] << '\n';
    return 0;
}
