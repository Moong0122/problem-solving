#include<iostream>
using namespace std;

int paper[501][501];
bool check[501][501];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int biggest = -1, sum,ssum,n,m;
void DFS(int y, int x, int level);
void another(int y, int x);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> paper[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j] = true;
            sum += paper[i][j];
            DFS(i, j, 0);
            sum -= paper[i][j];
            check[i][j] = false;
            another(i, j);
        }
    }
    cout << biggest << '\n';
    return 0;
}
void DFS(int y, int x, int level){
    if(level == 3){
        if(sum > biggest)
            biggest = sum;
        return;
    }
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(yy>=0 && xx >=0 && xx<m && yy < n){
            if(!check[yy][xx]){
                check[yy][xx] = true;
                sum += paper[yy][xx];
                DFS(yy,xx,level+1);
                sum -= paper[yy][xx];
                check[yy][xx] = false;
            }
        }
    }
    return;
}
void another(int y, int x){
    ssum = 0;
    if(y-1>=0 && x-1 >=0 && x+1 < m){
        ssum = paper[y-1][x] + paper[y][x-1] + paper[y][x+1] + paper[y][x];
        if(ssum > biggest)
            biggest = ssum;
    }if(y-1>=0 && x+1 < m && y+1 < n){
        ssum = paper[y-1][x] + paper[y+1][x] + paper[y][x+1] + paper[y][x];
        if(ssum > biggest)
            biggest = ssum;
    }if(x-1>=0 && x+1 < m && y+1 < n){
        ssum = paper[y][x-1] + paper[y][x+1] + paper[y+1][x] + paper[y][x];
        if(ssum > biggest)
            biggest = ssum;
    }if(x-1>=0 && y-1 >= 0 && y+1 < n){
        ssum = paper[y][x-1] + paper[y-1][x] + paper[y+1][x] + paper[y][x];
        if(ssum > biggest)
            biggest = ssum;
    }
}
