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

// 새로 푼거
// 피드백

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int left = 0, right = people.size() - 1;
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;
        }
        right--;
        answer++;
    }
    
    return answer;
}
