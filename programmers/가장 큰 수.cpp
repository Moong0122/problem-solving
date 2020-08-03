#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int num1, int num2){
    string s1 = to_string(num1) + to_string(num2);
    string s2 = to_string(num2) + to_string(num1);
    return s1 > s2;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto i : numbers) answer += to_string(i);
    
    return answer[0] == '0' ? "0" : answer;
}
