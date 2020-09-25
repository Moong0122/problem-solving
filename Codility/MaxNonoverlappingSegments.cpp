int solution(vector<int> &A, vector<int> &B) {
    int answer = 1;
    int finish = B[0], size = A.size();
    
    if(size == 0) return 0; // 만약 주어진 값이 없다면
    
    for(int i = 1 ; i < size ; i++){
        if(A[i] > finish){
            answer++;
            finish = B[i];
        }
    }
    return answer;
}
// 답은 최소 1개가 나올 수 있다 집합의 개수가 1개
// 0 ~ N-1번까지의 인덱스로 구성
