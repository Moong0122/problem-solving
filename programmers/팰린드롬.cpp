// 처음 풀었을 때
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m) {
    int answer = 0;
    
    for (int i = n ; i <= m ; i++) {
        vector<int> partial;
        int number = i;
            
        while (number != 0) {
            partial.push_back(number % 10);
            number /= 10;
        }
        
        int left = 0, right = partial.size() - 1;
        bool pass = true;
        
        while (left <= right) {
            if (partial[left] != partial[right]) {
                pass = false;
                break;
            }
            left++;
            right--;
        }
        
        if (pass) answer++;
    }

    return answer;
}

// 피드백
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m) {
    int answer = 0;
    
    for (int i = n ; i <= m ; i++) {
        int sum = 0;
        int partial = i;
        
        while (partial != 0) {
            sum *= 10;
            sum += partial % 10;
            partial /= 10;
        }
        
        if (i == sum) answer++;
    }

    return answer;
}
