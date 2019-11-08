#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t <= 10){
        int n,cnt;
        cin >> n >> cnt;
        long result = 1;
        for(int i=0;i<cnt;i++){
            result *= n;
        }
        cout << '#' << t << " " <<  result << endl;
        if(t == 10)
            break;
        cin >> t;
    }
    return 0;
}