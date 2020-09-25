int solution(int K, vector<int> &A) {
    int answer = 0;
    int tmp = 0;
    
    for(auto& i : A){
        tmp += i;
        if(tmp >= K){
            answer++;
            tmp = 0;
        }
    }
    
    return answer;
}
