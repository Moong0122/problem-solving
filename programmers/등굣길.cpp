#include <cstring>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int loc[n][m];
    memset(loc, 0, sizeof(loc));
    
    for(auto& i : puddles) loc[i[1]-1][i[0]-1] = -1;
    
    for(int i = 0 ; i < m ; i++){
        if(loc[0][i] == -1) break;
        loc[0][i] = 1;
    }
    
    for(int i = 1 ; i < n ; i++){
        if(loc[i][0] == -1) break;
        loc[i][0] = 1;
    }
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(loc[i][j]) continue;
            
            if(loc[i-1][j] != -1) loc[i][j] += loc[i-1][j];
            if(loc[i][j-1] != -1) loc[i][j] += loc[i][j-1];
            
            loc[i][j] %= 1000000007;
        }
    }
    return loc[n-1][m-1];
}
