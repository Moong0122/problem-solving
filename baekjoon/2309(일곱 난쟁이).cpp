#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int little[9];
bool isFound = false;
void back(int start, int depth){
    if(isFound) return;
    if(depth == 7){
        int sum = 0;
        for(int it : v){
            sum += it;
        }
        if(sum == 100){
            sort(v.begin(), v.end());
            for(int it : v) cout << it << '\n';
            isFound = false;
        }
        return;
    }
    for(int i=start;i<9;i++){
        v.push_back(little[i]);
        back(i+1, depth+1);
        v.pop_back();
    }
}
int main(){
    for(int i=0;i<9;i++) cin >> little[i];
    back(0,0);
    return 0;
}

/* 다른 방법!
 sum -> 모든 난쟁이들의 합
 for(int i=0;i<9;i++){
    for(int j=i+1;j<9;j++){
        if((sum - little[i] - little[j]) == 100)
            출력!
    }
 }
 */

