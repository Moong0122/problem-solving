#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int iron[4][8];
int order[4];
void moveClock(int num, int direction);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<4;i++){
        string s;
        cin >> s;
        for(int j=0;j<8;j++){
            iron[i][j] = s[j] - 48;
        }
    }
    int k,ni,di;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> ni >> di;
        
        order[ni-1] = di;
        
        for(int s=ni-2;s>=0;s--){
            if(iron[s+1][6] == iron[s][2])
                order[s] = 0;
            else
                order[s] = order[s+1] * -1;
        }
        for(int b=ni;b<4;b++){
            if(iron[b-1][2] == iron[b][6])
                order[b] = 0;
            else
                order[b] = order[b-1] * -1;
        }
        for(int j=0;j<4;j++){
            if(order[j] == 0) continue;
            else
                moveClock(j, order[j]);
        }
        memset(order, 0, sizeof(order));
    }
    int total = 0;
    for(int i=0;i<4;i++){
        total += iron[i][0] * pow(2,i);
    }
    cout << total << endl;
    return 0;
}
void moveClock(int num, int direction){
    int temp = iron[num][0];
    
    if(direction == 1){
        for(int i=7;i>=1;i--){
            iron[num][(i+1)%8] = iron[num][i];
        }
        iron[num][1] = temp;
    }else if(direction == -1){
        for(int i=1;i<=7;i++){
            iron[num][i-1] = iron[num][i];
        }
        iron[num][7] = temp;
    }
}
