#include<iostream>
using namespace std;

int arr[100002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int front = 0, back = 0, sum = 0, small = 100001;
    while(1){
        if(sum < s) sum += arr[back++];
        if(sum >= s){
            if(small > back-front) small = back-front;
            sum -= arr[front++];
        }
        if(back == n+1) break;
    }
    if(small == 100001) cout << 0 << '\n';
    else cout << small << '\n';
    return 0;
}
