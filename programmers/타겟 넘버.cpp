#include<iostream>
#include<vector>
using namespace std;
vector<int> copyNumbers;
int len, answer, sum;

void dfs(int index, int sum, int targetSum){
    if(index == len){
        if(sum == targetSum) answer++;
        return;
    }
    dfs(index+1, sum + copyNumbers[index], targetSum);
    dfs(index+1, sum - copyNumbers[index], targetSum);
}
int solution(vector<int> numbers, int target){
    copyNumbers = numbers;
    len = (int)numbers.size();
    dfs(0, 0, target);
    return answer;
}

// 다시 풀어보기
#include <string>
#include <vector>
using namespace std;

int answer = 0;
void dfs(int sum , int index, vector<int>& numbers, int target){
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    dfs(-numbers[index] + sum, index + 1, numbers, target);
    dfs(numbers[index] + sum, index + 1, numbers, target);
}
int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    return answer;
}
