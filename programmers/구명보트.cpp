#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0, right = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while(left < right){
        if(people[right] + people[left] <= limit){
            answer++, left++, right--;
        }
        else{
            answer++, right--;
        }
        if(left == right){
            answer++, left++;
        }
    }
    return answer;
}
