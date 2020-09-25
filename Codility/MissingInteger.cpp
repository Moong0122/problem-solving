bool visit[1000001];
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1;
    for(int i = 0 ; i < A.size(); i++){
        if(A[i] < 0) continue;
        visit[A[i]] = true;
        if(visit[answer]){ // 방문했다면 다음 숫자를 가리킨다
            while(visit[answer]){ // 이미 배열에 나온 숫자라면
                answer += 1;
            }
        }
    }
    return answer;
}
