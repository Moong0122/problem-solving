#include<iostream>
using namespace std;

int person[2][4];
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cin >> person[i][j];
        }
    }
    int big = -1;
    int sum = 0;
    for(int i=0;i<4;i++){
        sum += (person[i][1] - person[i][0]);
        if(sum > big)
            big = sum;
    }
    cout << big << endl;
    return 0;
}