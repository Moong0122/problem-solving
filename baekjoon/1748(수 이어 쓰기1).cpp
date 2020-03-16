#include<iostream>
#include<cmath>
using namespace std;

int changeToLen(int num){
    int cnt = 0;
    while(num != 0){
        cnt++;
        num /= 10;
    }
    return cnt;
}
long long beforeSum(int num){
    long long sum = 0;
    for(int i=1;i<num;i++){
        sum += i * 9 * pow(10, i-1);
    }
    return sum;
}
int main(){
    int n;
    long long answer = 0;
    cin >> n;
    int len = changeToLen(n);
    answer += beforeSum(len);
    
    int minus = n - pow(10, len-1) + 1;
    answer += minus * len;
    cout << answer << '\n';
    return 0;
}
