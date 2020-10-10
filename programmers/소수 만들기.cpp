// 처음 풀었을 때
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    
    int size = nums.size();
    int sum = 0;
    for(auto& i : nums){
        sum += i;
    }
    
    vector<bool> numbers(sum+1,false); // false여야 소수이다.
    
    numbers[1] = true;
    
    for(int i = 2 ; i*i <= sum ; i++){
        if(numbers[i]) continue;
        for(int j = i + i; j <= sum ; j += i){
            numbers[j] = true;
        }
    }
    int answer = 0;
    for(int i = 0 ; i < size; i++){
        for(int j = i+1 ; j < size; j++){
            for(int k = j+1 ; k < size ; k++){
                if(!numbers[nums[i]+nums[j]+nums[k]]) answer++;
            }
        }
    }
    return answer;
}

// 테스트 케이스는 모두 통과하는데 왜 제출하면 많이 틀리는지 모르겠다
// 피드백 후

// 방법 1 : 숫자 3개 조합하기 + 에라토스테네스의 체
for(int i = 2 ; i*i <= sum ; i++){
    if(numbers[i]) continue;
    for(int j = i + i; j <= sum ; j += i){ // 여기서 j는 i+i 부터 시작한다.
        numbers[j] = true;
    }
}

for(int i = 0 ; i < size; i++){ // size-2,-1을 써줄 필요가 없다 그냥 size만 적어주면 된다.
    for(int j = i+1 ; j < size; j++){
        for(int k = j+1 ; k < size ; k++){
            if(!numbers[nums[i]+nums[j]+nums[k]]) answer++;
        }
    }
}

// 방법 2 : 조합 구하기
// 삼중포문을 사용하지 않고 구하는 방법이다.
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    
    int size = nums.size();
    int sum = 0;
    for(auto& i : nums){
        sum += i;
    }
    
    vector<bool> numbers(sum+1,false); // false여야 소수이다.
    
    numbers[1] = true;
    
    for(int i = 2 ; i*i <= sum ; i++){
        if(numbers[i]) continue;
        for(int j = i + i; j <= sum ; j += i){
            numbers[j] = true;
        }
    }
    int answer = 0;
    
    vector<int> tmp(size,0);
    tmp[0] = tmp[1] = tmp[2] = 1;
    sort(tmp.begin(), tmp.end());
    
    do{
        int sub_sum = 0;
        for(int i = 0 ; i < size ; i++){
            if(tmp[i] == 1){
                sub_sum += nums[i];
            }
        }
        if(!numbers[sub_sum]) answer++;
    }while(next_permutation(tmp.begin(), tmp.end()));
    return answer;
}
