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

