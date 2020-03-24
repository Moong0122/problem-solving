#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int len = 0;
    for(int i=0;i<2*n-1;i++){
        if(i < n) len++;
        else len--;
        for(int i=0;i<len;i++){
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}
