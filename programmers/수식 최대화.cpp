#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long answer = 0;
int total_number_cnt; // 4
int total_buho_cnt; // 3
int buho_use_cnt; // 2
//
vector<int> numbers; // 50 6 3 2
vector<int> g_buho; // * - *
vector<int> s_buho; // 0 1, 1 0
//
bool buho_use_check[3];

void calculate(){
    // 2개의 실험용 벡터 생성하기
    vector<long long> t_numbers(total_number_cnt);
    for(int i = 0 ; i < total_number_cnt ; i++) t_numbers[i] = numbers[i];
    
    vector<int> t_buho(total_buho_cnt);
    for(int i = 0 ; i < total_buho_cnt ; i++) t_buho[i] = g_buho[i];
    // 복사 완료
    
    for(int i = 0 ; i < buho_use_cnt ; i++){
        int cur_buho = s_buho[i];
        
        for(int j = 0 ; j < (int)t_buho.size() ; j++){
            if(cur_buho == t_buho[j]){ // 우선순위를 맞게 찾았다면 계산 해주자
                //
                if(cur_buho == 0){
                    t_numbers[j] = t_numbers[j] * t_numbers[j+1];
                }else if(cur_buho == 1){
                    t_numbers[j] = t_numbers[j] - t_numbers[j+1];
                }else if(cur_buho == 2){
                    t_numbers[j] = t_numbers[j] + t_numbers[j+1];
                }
                //
                t_numbers.erase(t_numbers.begin() + j + 1);
                t_buho.erase(t_buho.begin() + j);
                j--;
            }
        }
    }
    if(abs(t_numbers[0]) > answer) answer = abs(t_numbers[0]);
}
void select_buho_rank(int depth){
    if(depth == buho_use_cnt){
        calculate();
        return;
    }
    for(int i = 0 ; i < 3 ; i++){
        if(buho_use_check[i]){
            buho_use_check[i] = false;
            s_buho.push_back(i);
            select_buho_rank(depth+1);
            s_buho.pop_back();
            buho_use_check[i] = true;
        }
    }
}
long long solution(string expression) {
    int _len = (int)expression.size();
    
    int start = 0;
    int cnt = 0;
    for(int i = 0 ; i <  _len ; i++){
        if(expression[i] >= 48){ // 숫자라면
            cnt++;
        }
        else{ // 부호라면
            numbers.push_back(stoi(expression.substr(start,cnt)));
            start = i + 1;
            cnt = 0;
            
            if(expression[i] == '*'){
                g_buho.push_back(0);
                buho_use_check[0] = true;
            }
            else if(expression[i] == '-'){
                g_buho.push_back(1);
                buho_use_check[1] = true;
            }
            else if(expression[i] == '+'){
                g_buho.push_back(2);
                buho_use_check[2] = true;
            }
        }
    }
    numbers.push_back(stoi(expression.substr(start,cnt)));
    total_number_cnt = (int)numbers.size();
    total_buho_cnt = total_number_cnt - 1;
    
    for(bool it : buho_use_check) if(it) buho_use_cnt++;
    select_buho_rank(0);
    return answer;
}
int main(){
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}
