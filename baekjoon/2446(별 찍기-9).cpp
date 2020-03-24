#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, len, start = 0;
    cin >> n;
    
    len = 2*n - 1;
    for(int i=0;i<n;i++){
        for(int j = 0 ; j < start ; j++) cout << " ";
        for(int j = start ; j < len ; j++) cout << "*";
        cout << '\n';
        start++;
        len--;
    }
    start = n- 1;
    len = n;
    for(int i=0;i<n;i++){
    if(i!=0){
        for(int j=0;j<start;j++) cout << " ";
        for(int j=start;j<len;j++) cout << "*";
        cout << '\n';
    }
        start--;
        len++;
    }
    return 0;
}
