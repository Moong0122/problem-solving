#include<iostream>
using namespace std;
const int MAX = 11;

int n;
int big = -1000000001;
int small = 1000000001;
int number[MAX];
int Plus, Minus, Multiple, Divide;
void dfs(int pl, int mi, int mu, int di, int sum, int next){
    if(next == n){
        if(sum > big) big = sum;
        if(sum < small) small = sum;
        return;
    }
    if(pl < Plus) dfs(pl+1,mi,mu,di,sum+number[next], next+1);
    if(mi < Minus) dfs(pl,mi+1,mu,di,sum-number[next], next+1);
    if(mu < Multiple) dfs(pl,mi,mu+1,di,sum*number[next], next+1);
    if(di < Divide) dfs(pl,mi,mu,di+1,sum/number[next], next+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> number[i];
    cin >> Plus >> Minus >> Multiple >> Divide;
    dfs(0,0,0,0,number[0],1);
    cout << big << '\n';
    cout << small << '\n';
    return 0;
}
