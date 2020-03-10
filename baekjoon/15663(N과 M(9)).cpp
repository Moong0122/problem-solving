#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n,m;
vector<int> v;
vector<int> choose_v;
map<int,int> numCnt;

void dfs(int depth){
    if(depth == m){
        for(int it : choose_v) cout << it << " ";
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(numCnt[v[i]]){
            numCnt[v[i]]--;
            choose_v.push_back(v[i]);
            dfs(depth+1);
            choose_v.pop_back();
            numCnt[v[i]]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(numCnt.count(num)){
            numCnt[num]++;
        }else{
            numCnt[num] = 1;
            v.push_back(num);
        }
    }
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}


/*
 #include<iostream>
 #include<vector>
 #include<set>
 #include<algorithm>
 using namespace std;


 int n,m;
 bool check[8];
 int arr[8];
 vector<int> v;
 set<vector<int>> s;
 void dfs(int depth){
     if(depth == m){
         s.insert(v);
         return;
     }
     for(int i=0;i<n;i++){
         if(!check[i]){
             check[i] = true;
             v.push_back(arr[i]);
             dfs(depth+1);
             v.pop_back();
             check[i] = false;
         }
     }
 }
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     cin >> n >> m;
     for(int i=0;i<n;i++) cin >> arr[i];
     sort(arr,arr+n);
     dfs(0);
     for(auto i:s){
         for(auto j:i) cout << j << " ";
         cout << '\n';
     }
     return 0;
 }
 */
