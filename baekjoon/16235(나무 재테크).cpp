#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAX = 11;

vector<int> land[MAX][MAX];
int energy[MAX][MAX];
int inputEnergy[MAX][MAX];
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};
int n,m,k;
void springAndSummer();
void fall();
void winter();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> inputEnergy[i][j];
            energy[i][j] = 5;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,age;
        cin >> a >> b >> age;
        land[a][b].push_back(age);
    }
    while(k>0){
        springAndSummer();
        fall();
        winter();
        k--;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans += land[i][j].size();
        }
    }
    cout << ans << endl;
    return 0;
}
void springAndSummer(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int len = land[i][j].size();
            if(len !=0 ){
                int updated_index = len;
                sort(land[i][j].begin(),land[i][j].end());
                // spring
                for(int tree = 0;tree < len ; tree++){
                    if(land[i][j][tree] <= energy[i][j]){
                        energy[i][j] -= land[i][j][tree];
                        land[i][j][tree]++;
                    }else{
                        updated_index = tree;
                        break;
                    }
                }
                // summer
                if (updated_index == len) continue;
                for(int tree = len-1;tree>=updated_index;tree--){
                    energy[i][j] += land[i][j][tree] / 2;
                    land[i][j].pop_back();
                }
                //
            }
        }
    }
}
void fall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int len = land[i][j].size();
            if(len != 0){
                //
                for(int tree = 0 ; tree < len ; tree++){
                    if(land[i][j][tree] % 5 == 0){
                        for(int tmp = 0; tmp < 8 ; tmp++){
                            int yy = i + dy[tmp];
                            int xx = j + dx[tmp];
                            if(yy >= 1 && yy <= n && xx >= 1 && yy <= n){
                                land[yy][xx].push_back(1);
                            }
                        }
                    }
                }
                //
            }
        }
    }
}
void winter(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            energy[i][j] += inputEnergy[i][j];
        }
    }
}
