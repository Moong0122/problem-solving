int solution(vector<int> &A) {
    vector<bool> check(100001, false);
    int answer = 1;
    
    for(int i = 0 ; i < A.size() ; i++){
        check[A[i]] = true;
        if(check[answer]){
            answer++;
            while(check[answer]){
                answer++;
            }
        }
    }
    return answer;
}
