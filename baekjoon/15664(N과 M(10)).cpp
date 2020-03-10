// map을 이용해서 풀어보기
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> numCnt;
vector<int> v;
vector<int> choose_v;
int arr[8];
int n,m;
void dfs(int start, int depth){
    if(depth == m){
        for(int it : choose_v) cout << it << " ";
        cout << '\n';
        return;
    }
    for(int i=start;i<n;i++){
        if(numCnt[v[i]]){
            numCnt[v[i]]--;
            choose_v.push_back(v[i]);
            dfs(i, depth+1);
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
    dfs(0,0);
    return 0;
}

/*
 // set을 이용해서 풀어보기
 #include<iostream>
 #include<vector>
 #include<set>
 #include<algorithm>
 using namespace std;

 vector<int> v;
 set<vector<int>> s;
 int arr[8];
 int n,m;
 void dfs(int start, int depth){
     if(depth == m){
         s.insert(v);
         return;
     }
     for(int i=start;i<n;i++){
         v.push_back(arr[i]);
         dfs(i+1, depth+1);
         v.pop_back();
     }
 }
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     cin >> n >> m;
     for(int i=0;i<n;i++) cin >> arr[i];
     sort(arr,arr+n);
     dfs(0,0);
     for(auto i:s){
         for(auto j:i) cout << j << " ";
         cout << '\n';
     }
     return 0;
 }
 */
