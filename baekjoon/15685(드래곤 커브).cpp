#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int MAX = 101;

vector<pair<int,int>> v;
void makeInitial(int nextY, int nextX, int dir);
void rotateCurve();
int grid[MAX][MAX];
int main(){
    int n;
    cin >> n;
    int x,y,d,g;
    for(int i=0;i<n;i++){
        cin >> x >> y >> d >> g;
        makeInitial(y,x,d);
        for(int j=0;j<g;j++){
            rotateCurve();
        }
        for(int j=0;j<v.size();j++){
            grid[v[j].first][v[j].second] = 1;
        }
        v.clear();
    }
    int ans = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(grid[i][j] == 1 && grid[i][j+1] == 1 && grid[i+1][j] == 1 && grid[i+1][j+1] == 1)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
void makeInitial(int nextY, int nextX, int dir){
    v.push_back({nextY,nextX});
    switch (dir) {
        case 0:
            v.push_back({nextY,nextX+1});
            break;
        case 1:
            v.push_back({nextY-1,nextX});
            break;
        case 2:
            v.push_back({nextY,nextX-1});
            break;
        case 3:
            v.push_back({nextY+1,nextX});
            break;
    }
}
void rotateCurve(){
    int len = v.size() - 1;
    int centerY = v[len].first;
    int centerX = v[len].second;
    for(int i=len-1;i>=0;i--){
        int yy = centerY - v[i].first;
        int xx = centerX - v[i].second;
        v.push_back({centerY + (-1)*xx, centerX + yy});
    }
}
