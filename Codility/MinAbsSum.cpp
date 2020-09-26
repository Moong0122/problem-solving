#include <algorithm>
#include <cmath>

int solution(vector<int> &A) {
    int n = A.size();
    int m = 0, s = 0;
    
    for(int i = 0 ; i < n ; i++){
        A[i] = abs(A[i]); // 모든 수를 양수로 바꾸고
        s += A[i]; // 그 합을 구해주기
        m = max(A[i], m); // 그 중에서 최대값 구해주기
    }
    
    vector<int> count(m+1); // 0부터 m(최대값)까지의 범위를 가진 벡터
    
    for(int i = 0 ; i < n ; i++){
        count[A[i]]++; // A의 양의 원소들을 인덱스로 하여 그 곳에 +1을 해준다
    }
    
    vector<int> dp(s+1, -1); // A의 총합만큼의 범위를 가진 벡터를 만들어주고 -1로 초기화 시켜준다
    dp[0] = 0;
    
    for(int i = 1 ; i < m+1 ; i++){
        if(count[i] > 0){ // 만약 A의 원소가 있다면,
            for(int j = 0 ; j < s ; j++){ // 0부터 s(총합)까지 순회하면서
                if(dp[j] >= 0) dp[j] = count[i];
                else if(j >= i && dp[j-i] > 0){
                    dp[j] = dp[j-i] - 1;
                }
            }
        }
    }
    int result = s;
    for(int i = 0 ; i < s/2 + 1 ; i++){
        if(dp[i] >= 0){
            result = min(result, s - 2 * i);
        }
    }
    return result;
}
