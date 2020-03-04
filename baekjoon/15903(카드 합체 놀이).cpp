#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int cardNum, combineNum;
    cin >> cardNum >> combineNum;
    for(int i=0;i<cardNum;i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    for(int i=0;i<combineNum;i++){
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        pq.push(first+second);
        pq.push(first+second);
    }
    long long answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    cout << answer << '\n';
    return 0;
}

