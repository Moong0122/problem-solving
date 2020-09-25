#include <string>
#include <vector>

using namespace std;
int solution(vector<int> money) {
    int size = money.size();
    vector<int> arr1(size,0);
    vector<int> arr2(size,0);
    
    // 양끝의 수를 모두 포함할 수도 있기 때문에 두가지 경우로 나누어서 풀어준다
    
    // 0번부터 size-2번 인덱스까지
    arr1[0] = money[0];
    int yupyup, yup;
    for(int i = 1; i < size-1 ; i++){
        yup = arr1[i-1];
        i-2 < 0 ? yupyup = 0 : yupyup = arr1[i-2];
        
        arr1[i] = max(yup, money[i] + yupyup);
    }
        
    // 1번부터 size-1번 인덱스까지
    arr2[1] = money[1];
    for(int i = 2; i < size ; i++){
        yup = arr2[i-1];
        i-2 < 1 ? yupyup = 0 : yupyup = arr2[i-2];
        
        arr2[i] = max(yup, money[i] + yupyup);
    }
        
    return max(arr1[size-2], arr2[size-1]);
}
// max(자기자신을 포기 + 옆에 집, 자기꺼 + 옆옆집)
