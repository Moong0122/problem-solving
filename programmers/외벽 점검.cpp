#include <bits/stdc++.h>

using namespace std;

int N;

int test(int st, vector<int> &weak, vector<int> &dist) {
    int p = 0;
    for (int i = 0; i < dist.size(); i++) {
        int a = weak[st+p];
        while(p < N and weak[st+p] <= a+dist[i]) p++;
        if (p == N) return i+1;
    }
    return 1000;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = weak.size();

    for (int i = 0, _i = N; i < _i; i++) {
        weak.push_back(weak[i]+n);
    }

    sort(dist.begin(), dist.end());
    int result = 1000;
    for (int i = 0; i < N; i++) {
        do {
            result = min(result, test(i, weak, dist));
        } while(next_permutation(dist.begin(), dist.end()));
    }

    if (result == 1000) return -1;
    else return result;
}
