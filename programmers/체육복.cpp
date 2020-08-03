#include <vector>

using namespace std;

// 알고리즘 복잡도 O(n) 선형 복잡도 n에 비례한다
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n+2,1);
    for(auto& i : reserve) check[i]++;
    for(auto& i : lost) check[i]--;
    for(int i = 1 ; i <= n ; i++){
        if(check[i] == 2){
            if(check[i-1] == 0) check[i-1] = check[i] = 1;
            else if(check[i+1] == 0) check[i+1] = check[i] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i++) if(check[i] > 0) answer++;
    return answer;
}

// 학생수는 굉장히 많고 여벌로 체육복 가져온 사람의 수는 적을 때 알고리즘 복잡도 : O(nlogn)
/*
 #include <vector>
 #include <unordered_set>
 #include <set>
 using namespace std;
 
 int solution(int n, vector<int> lost, vector<int> reserve) {
     unordered_set<int> l(lost.begin(), lost.end());
     set<int> r;
     unordered_set<int> inter;
     
     for(auto& x : reserve){
         if(l.find(x) != l.end()) inter.insert(x);
         else r.insert(x); // klogk 정렬을 해야 하므로
     }
     for(auto& x : inter) l.erase(x);
     
     for(auto& x : r){
         if(l.find(x-1) != l.end()) l.erase(x-1);
         else if(l.find(x+1) != l.end()) l.erase(x+1);
     }
     
     return n - l.size();
 }
 */
