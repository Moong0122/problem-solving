#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#define INF 999999
using namespace std;

int n,m;
vector<int> broken;
int changeLen(int num){
    if(num == 0) return 1;
    
    int cnt = 0;
    while(num != 0){
        cnt++;
        num /= 10;
    }
    return cnt;
}
bool isOkay(int num){
    if(num < 0) return false;
    
    map<int,int> number;
    if(num == 0){
        number[0] = 1;
    }else{
        while(num != 0){
            int temp = num % 10;
            number[temp] = 1;
            num /= 10;
        }
    }
    for(int it : broken) if(number.count(it)) return false;
    return true;
}
int checkUp(int target){
    int tmp = target;
    while(!isOkay(tmp)){
        if(tmp == INF) break;
        tmp++;
    }
    return abs(tmp-n) + changeLen(tmp);
}
int checkDown(int target){
    int tmp = target;
    while(!isOkay(tmp)){
        tmp--;
        if(tmp < 0) return INF;
    }
    return abs(tmp-n) + changeLen(tmp);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> m;
    broken.resize(m);
    for(int i=0;i<m;i++) cin >> broken[i];
    
    int num1 = abs(n-100);
    int num2 = checkUp(n);
    int num3 = checkDown(n);
    int answer = min(num1, min(num2,num3));
    cout << answer << '\n';
    return 0;
}
