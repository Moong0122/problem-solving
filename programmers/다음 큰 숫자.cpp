// 피드백 후 코드 수정
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    vector<int> v;
    int num = n;
    int answer, sum, size, multiple;

    while (num != 0) {
        v.push_back(num & 1);
        num >>= 1;
    }

    // 15(1111)처럼 1만 있는 케이스가 있는 경우 벡터 v에 0을 추가해줍니다
    v.push_back(0);

    size = v.size();

    reverse(v.begin(), v.end());

    do{
        multiple = 1;
        v[size-1] == 0 ? sum = 0 : sum = 1;
        for (int i = size - 2 ; i >= 0 ; i--) {
            multiple *= 2;
            if (v[i] == 1) {
                sum += multiple;
            }
        }
        if (sum > n) {
            answer = sum;
            break;
        }
    }while (next_permutation(v.begin(), v.end()));

    return answer;
}

// bitset 사용해서 문제 풀기
#include <bitset>
using namespace std;

int solution(int n){
    int countOne = bitset<20>(n).count();

    while (countOne != bitset<20>(++n).count());

    return n;
}
