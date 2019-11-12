#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int x, int y);
int house[17][17];
int n, result = 0;
int main(){
    int a;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> house[i][j];
        }
    }
    bfs(1,2);
    cout << result << endl;
}
void bfs(int x, int y){
    queue<pair<int,int> >q;
    queue<int> status;

    status.push(1);
    q.push(make_pair(x,y));

    while(!q.empty()){
        pair<int,int> pos = q.front();
        int state = status.front();
        q.pop();
        status.pop();

        if(pos.first == n && pos.second == n)
            result++;

        if(state == 1){
            if(house[pos.first][pos.second+1] == 0 && pos.second + 1 <= n){
                q.push(make_pair(pos.first,pos.second+1));
                status.push(1);
            }
            if(house[pos.first][pos.second+1] == 0 && house[pos.first+1][pos.second] == 0 && house[pos.first+1][pos.second+1] == 0 && pos.second + 1 <= n && pos.first + 1 <= n){
                q.push(make_pair(pos.first+1,pos.second+1));
                status.push(2);
            }
        }
        if(state == 2){
            if(house[pos.first][pos.second+1] == 0 && pos.second + 1 <= n){
                q.push(make_pair(pos.first,pos.second+1));
                status.push(1);
            }
            if(house[pos.first+1][pos.second] == 0 && pos.first + 1 <= n){
                q.push(make_pair(pos.first+1,pos.second));
                status.push(3);
            }
            if(house[pos.first][pos.second+1] == 0 && house[pos.first+1][pos.second] == 0 && house[pos.first+1][pos.second+1] == 0 && pos.second + 1 <= n && pos.first + 1 <= n){
                q.push(make_pair(pos.first+1,pos.second+1));
                status.push(2);
            }
        }
        if(state == 3){
            if(house[pos.first+1][pos.second] == 0 && pos.first + 1 <= n){
                q.push(make_pair(pos.first+1,pos.second));
                status.push(3);
            }
            if(house[pos.first][pos.second+1] == 0 && house[pos.first+1][pos.second] == 0 && house[pos.first+1][pos.second+1] == 0 && pos.second + 1 <= n && pos.first + 1 <= n){
                q.push(make_pair(pos.first+1,pos.second+1));
                status.push(2);
            }
        }
    }
}