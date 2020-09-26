int solution(vector<int> &A) {
    vector<int> answer(A.size(),-999999999);
    answer[0] = A[0];
    
    for(int i = 0 ; i < A.size() ; i++){
        for(int j =1 ; j <= 6 ; j++){ // i위치에서 주사위를 던져 이동하려고 한다
            int next = i + j;
            if(next >= A.size()) break;

            if(answer[next] < answer[i] + A[next]) answer[next] = answer[i] + A[next];
            // 그냥 다음칸으로 이동하는 거, 현재 칸에서 다음칸으로 이동하는 거
        }
    }
    return answer[A.size() - 1];
}
