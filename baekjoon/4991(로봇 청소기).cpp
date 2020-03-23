#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
//
#define P pair<int,int>
#define PI pair<P,int>
#define mp(a,b) make_pair(a,b)
#define mp3(a,b,c)  mp(mp(a,b), c)
//
using namespace std;

vector<PI> contents;
int w,h,star, last_x, last_y, check[21][21], idx_tracer[21], cnt_sum = TMP_MAX;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
char map[21][21];
bool visit[21][21], flag;
int dis[21][21];

void bfs(int idx, int y, int x){
    queue<PI> Q;
    Q.push(mp3(y,x,0));
    visit[y][x] = true;
    
    while(!Q.empty()){
        int cy = Q.front().first.first;
        int cx = Q.front().first.second;
        int cnt = Q.front().second;
        Q.pop();
        
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w || visit[ny][nx] || map[ny][nx] == 'x') continue;
            
            // 자기보다 큰 별 발견. idx행 check[nx][ny] 열에 cnt를 할당한다
            if(check[ny][nx] > idx){
                int from = idx, to = check[ny][nx];
                dis[from][to] = dis[to][from] = cnt + 1;
            }
            visit[ny][nx] = true;
            Q.push(mp3(ny, nx, cnt+1));
        }
    }
}
void dfs(int last_idx, int sum, int cnt){
    if(cnt == star){
        cnt_sum = cnt_sum > sum ? sum : cnt_sum;
        flag = true;
        return;
    }
    for(int i=1;i<=star;i++){
        if(!idx_tracer[i]){
            if(dis[last_idx][i] == 0) continue;
            idx_tracer[i] = true;
            int next_sum = sum + dis[last_idx][i];
            if(next_sum < cnt_sum) dfs(i,sum+dis[last_idx][i], cnt+1);
            idx_tracer[i] = false;
        }
    }
}
bool cmp(PI a, PI b){
    return a.first.first < b.first.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        cin >> w >> h;
        
        if(!(w|h)) break;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    last_y = i, last_x = j;
                    check[i][j] = 0;
                    contents.push_back(mp3(0,i,j));
                }else if(map[i][j] == '*'){
                    check[i][j] = ++star;
                    contents.push_back(mp3(star,i,j));
                }
            }
        }
        // 0번째에 로봇 놓고 나머지 정렬
        sort(contents.begin(), contents.end(),cmp);
        
        // 로봇이 bfs 돌아서 자기보다 작은 숫자만 빼고 전부 거리 측정
        for(int i=0;i<contents.size();i++){
            bfs(i,contents[i].first.second, contents[i].second);
            memset(visit,0,sizeof(visit));
        }
        // 로봇부터(0번부터) dfs 실시하면서 가장 짧은 거리 구하기
        dfs(0,0,0);
        
        if(!flag) cnt_sum = -1;
        cout << cnt_sum << '\n';
        
        cnt_sum = TMP_MAX, star = last_x = last_y = 0;
        contents.clear();
        memset(check, 0, sizeof(check));
        memset(dis, 0, sizeof(dis));
        flag = false;
    }
    return 0;
}

// 나중에 다시 풀어보기
