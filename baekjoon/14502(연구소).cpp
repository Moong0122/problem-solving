#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

vector<pair<int,int> > v;
vector<pair<int,int> > wall;
int lab[9][9];
int check_visit[9][9];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;
int big = -1;
void backtracking(int pos,int start);
void BFS();
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    backtracking(0,0);
    cout << big << endl;
    return 0;
}
void backtracking(int pos,int start){
    if(pos == 3){
        int cnt = 0;
        for(int i=0;i<3;i++){
            lab[wall[i].first][wall[i].second] = 1;
        }
        BFS();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(lab[i][j] == 0 && check_visit[i][j] == 0)
                    cnt++;
            }
        }
        if(cnt > big)
            big = cnt;
        for(int i=0;i<3;i++){
            lab[wall[i].first][wall[i].second] = 0;
        }
        memset(check_visit,0,sizeof(check_visit));
        return;
    }

    int len = v.size();
    for(int i=start;i<len;i++){
        wall.push_back(v[i]);
        backtracking(pos+1,i+1);
        wall.pop_back();
    }
}
void BFS(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(lab[i][j] == 2){
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                check_visit[i][j] = 1;
                while(!q.empty()){
                    pair<int,int> temp = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int x = temp.first + dx[k];
                        int y = temp.second + dy[k];
                        if(x >= 0 && x <n && y >= 0 && y < m){
                            if(check_visit[x][y] == 0 && lab[x][y] == 0){
                                q.push(make_pair(x,y));
                                check_visit[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}