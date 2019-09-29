#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> v;
vector<int> result;
void dfs(int pos, int start, int size);
int main(){
    int t,a;
    cin >> t;
    
    while(t!=0){
        for(int i=0;i<t;i++){
            cin >> a;
            v.push_back(a);
        }
        dfs(0,0,t);
        cout << endl;
        v.clear();
        result.clear();
        cin >> t;
    }
    return 0;
}
void dfs(int pos, int start, int size){
    if(pos == 6){
        for(int i=0;i<6;i++){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=start;i<size;i++){
        result.push_back(v[i]);
        dfs(pos+1,i+1,size);
        result.pop_back();
    }
}
