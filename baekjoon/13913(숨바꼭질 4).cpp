#include<iostream>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;

bool check[MAX];
int backToBack[MAX];
void bfs(int start, int finish){
    queue<int> q;
    q.push(start);
    check[start] = true;
    backToBack[start] = -1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur+1 <= 100000 && !check[cur+1]){
            q.push(cur+1);
            check[cur+1] = true;
            backToBack[cur+1] = cur;
            if(cur+1 == finish) break;
        }
        if(cur-1 >= 0 && !check[cur-1]){
            q.push(cur-1);
            check[cur-1] = true;
            backToBack[cur-1] = cur;
            if(cur-1 == finish) break;
        }
        if(cur*2 <= 100000 && !check[cur*2]){
            q.push(cur*2);
            check[cur*2] = true;
            backToBack[cur*2] = cur;
            if(cur*2 == finish) break;
        }
    }
    vector<int> v;
    while(backToBack[finish] != -1){
        v.push_back(finish);
        finish = backToBack[finish];
    }
    v.push_back(start);
    cout << v.size() - 1 << '\n';
    for(int i=v.size()-1; i>=0;i--) cout << v[i] << " ";
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    if(n == k) cout << 0 << '\n' << n << '\n';
    else bfs(n,k);
    return 0;
}
