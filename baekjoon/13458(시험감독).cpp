#include<iostream>
#include<vector>
using namespace std;

vector<int> number;
long long total = 0;
int main(){
    int n,b,c,a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        number.push_back(a);
    }
    cin >> b >> c;
    for(int i=0;i<n;i++){
        if(number[i] <= b)
            total++;
        else{
            total++;
            int tmp = number[i] - b;
            if(tmp % c == 0)
                total += (tmp/c);
            else
                total += (tmp/c) + 1;
        }
    }
    cout << total << endl;
    return 0;
}