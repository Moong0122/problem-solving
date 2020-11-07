#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();
    
    for(int i = 1 ; i < height ; i++){
        int cur_height = triangle[i].size();
        for(int j = 0 ; j < cur_height ; j++){
            if(j == 0){
                triangle[i][j] += triangle[i-1][j];
            }else if(j == cur_height-1){
                triangle[i][j] += triangle[i-1][j-1];
            }else{
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    
    int answer = triangle[height-1][0];
    for(int i = 1 ; i < height ; i++){
        answer = max(answer, triangle[height-1][i]);
    }
    return answer;
}


// 다시 풀어보기
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    
    return triangle[0][0];
}
