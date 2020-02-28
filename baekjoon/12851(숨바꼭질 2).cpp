#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int MAX = 100001;

int visit[MAX];
int main(){
    queue<pair<int, int>> q;
    map<int,int> m;
    int n,k;
    cin >> n >> k;
    
    q.push({n,0});
    int MIN = MAX;
    
    if(n == k){
        cout << 0 << endl;
        cout << 1 << endl;
    }else{
        while(!q.empty()){
            int pos = q.front().first;
            int t = q.front().second;
            q.pop();
            visit[pos] = 1;
            
            if(pos == k){
                m[t]++;
                MIN = min(MIN,t);
            }
            if(pos * 2 < MAX && visit[pos*2] == 0) q.push({pos*2,t+1});
            if(pos + 1 < MAX && visit[pos+1] == 0) q.push({pos+1,t+1});
            if(pos - 1 >= 0 && visit[pos-1] == 0) q.push({pos-1,t+1});
        }
        cout << m.begin()->first << endl;
        cout << m.begin()->second << endl;
    }
    return 0;
}
