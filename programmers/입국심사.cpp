#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    // 한명이 가장 적게 걸리는 곳에 서 있는 경우
    long long tmin = (long long)*min_element(times.begin(), times.end());
    // 모든 사람들이 가장 오래 걸리는 곳에 다 서 있는 경우
    long long tmax = (long long)*max_element(times.begin(), times.end()) * n;
    long long answer = 0;
    
    while (tmin <= tmax) {
        long long tmid = (tmin + tmax) / 2;
        long long s = 0;
        
        // 주어진 시간(tmid)동안 심사한 사람들의 수를 체크
        for (auto n : times) {
            s += (tmid / n);
        }
        
        // 목표(n)보다 적은 사람을 심사했다면 tmin을 뒤로 이동시켜준다.
        if (s < n) {
            tmin = tmid + 1;
        // 보다 많은 사람들을 심사했다면 tmax를 앞으로 이동시켜준다.
        } else {
            answer = tmid;
            tmax = tmid - 1;
        }
    }
    
    return answer;
}
