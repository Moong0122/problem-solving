#include <vector>
long long sum(std::vector<int> &a) {
    long long ans = 0;
    int len = a.size();
    for(int i=0;i<len;i++){
        ans += a[i];
    }
    return ans;
}
