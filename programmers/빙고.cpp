#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
    unordered_map<int, pair<int,int>> m;
    
    for (int i = 0 ; i < board.size() ; i++) {
        for (int j = 0 ; j < board.size() ; j++) {
            m[board[i][j]] = {i, j};
        }
    }
    
    for (auto& i : nums) {
        board[m[i].first][m[i].second] = 0;
    }
    
    int answer = 0, left = 0, right = 0, index = board.size();
    int row, col;
    
    for (int i = 0 ; i < board.size() ; i++) {
        --index;
        row = 0;
        col = 0;
        
        if (board[i][i] == 0) left++;
        if (board[board.size() - 1 - index][index] == 0) right++;
        
        for (int j = 0 ; j < board.size() ; j++) {
            if (board[i][j] == 0) row++;
            if (board[j][i] == 0) col++;
        }
        
        if (row == board.size()) answer++;
        if (col == board.size()) answer++;
    }
    
    if (left == board.size()) answer++;
    if (right == board.size()) answer++;
    
    return answer;
}

// 피드백
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
    unordered_map<int, pair<int,int>> m;

    for (int i = 0 ; i < board.size() ; i++) {
        for (int j = 0 ; j < board.size() ; j++) {
            m[board[i][j]] = {i, j};
        }
    }

    for (auto& i : nums) {
        board[m[i].first][m[i].second] = 0;
    }

    int answer = 0, diag_left = 0, diag_right = 0;
    int row, col;

    for (int i = 0 ; i < board.size() ; i++) {
        row = 0;
        col = 0;

        if (board[i][i] == 0) diag_left++;
        if (board[i][board.size() - 1 - i] == 0) diag_right++;

        for (int j = 0 ; j < board.size() ; j++) {
            if (board[i][j] == 0) row++;
            if (board[j][i] == 0) col++;
        }
        if (row == board.size()) answer++;
        if (col == board.size()) answer++;
    }

    if (diag_left == board.size()) answer++;
    if (diag_right == board.size()) answer++;

    return answer;
}
