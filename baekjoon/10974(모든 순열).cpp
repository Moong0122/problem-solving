#include<iostream>
#include<vector>
using namespace std;
const int MAX = 9;

int n;
bool check[MAX];
vector<int> v;
void back(int depth){
    if(depth == n){
        for(int i : v) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            v.push_back(i);
            check[i] = true;
            back(depth+1);
            check[i] = false;
            v.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    back(0);
    return 0;
}
