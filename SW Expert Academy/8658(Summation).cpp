#include<iostream>
#include<vector>
using namespace std;

vector <int> v;
void changeNumber(int num);
int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            int a;
            cin >> a;
            changeNumber(a);
        }
        int big = v[0];
        int small = v[0];
        for(int j=1;j<10;j++){
            if(v[j] > big)
                big = v[j];
            if(v[j] < small)
                small = v[j];
        }
        cout << '#' << i << " " << big << " " << small << endl;
        v.clear();
    }
    return 0;
}
void changeNumber(int num){
    int sum = 0;

    while(num > 0){
        sum += (num%10);
        num /= 10;
    }
    v.push_back(sum);
}