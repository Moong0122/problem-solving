#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int cur_left_pos = 10;
    int cur_right_pos = 12;
    int len = (int)numbers.size();
    
    for(int i = 0 ; i < len ; i++){
        if(numbers[i] == 0)
            numbers[i] = 11;
        
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            cur_left_pos = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            cur_right_pos = numbers[i];
        }
        else{
            int lefty = (cur_left_pos - 1) / 3;
            int leftx = (cur_left_pos - 1) % 3;
            int righty = (cur_right_pos - 1) / 3;
            int rightx = (cur_right_pos - 1) % 3;
            int cury = (numbers[i] - 1) / 3;
            int curx = (numbers[i] - 1) % 3;
            
            if(abs(lefty - cury) + abs(leftx - curx) < abs(righty - cury) + abs(rightx - curx)){
                answer += "L";
                cur_left_pos = numbers[i];
            }
            else if(abs(lefty - cury) + abs(leftx - curx) > abs(righty - cury) + abs(rightx - curx)){
                answer += "R";
                cur_right_pos = numbers[i];
            }
            else{
                if(hand == "left"){
                    answer += "L";
                    cur_left_pos = numbers[i];
                }
                else{
                    answer += "R";
                    cur_right_pos = numbers[i];
                }
            }
        }
    }
    return answer;
}
