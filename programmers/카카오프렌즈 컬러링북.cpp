#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int check[m][n];
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int cnt = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            check[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[i][j] == 0 && picture[i][j] > 0){
                int color = picture[i][j];
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                check[i][j] = 1;
                
                while(!q.empty()){
                    pair<int,int> p;
                    p = q.front();
                    q.pop();
                    cnt++;
                    for(int i=0;i<4;i++){
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if(x>=0 && y>=0 && x < m && y <n && check[x][y] == 0 && picture[x][y] == color){
                            q.push(make_pair(x,y));
                            check[x][y]=1;
                        }
                    }
                }
                number_of_area++;
            }
            if(cnt > max_size_of_one_area)
                max_size_of_one_area = cnt;
            cnt = 0;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
