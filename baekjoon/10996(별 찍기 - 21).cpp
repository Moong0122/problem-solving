#include<iostream>
using namespace std;

int main(){
    int n, number;
    cin >> n;
    
    if(n % 2 == 0) number = n / 2;
    else number = n / 2 + 1;
    
    if(n == 1) cout << "*" << '\n';
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<number;j++){
                cout << "* ";
            }
            cout << '\n';
            for(int j=0;j<n-number;j++){
                cout << " *";
            }
            cout << '\n';
        }
    }
    return 0;
}
