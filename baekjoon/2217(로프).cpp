#include<iostream>
#include<algorithm>
using namespace std;

int lope[100001];
int main(){
    int n, max = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> lope[i];
    }
    sort(lope,lope+n);
    for(int i=0;i<n;i++){
        if(lope[i] * (n-i) > max)
            max = lope[i] * (n-i);
    }
    cout << max << endl;
    return 0;
}
