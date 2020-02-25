#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 10000;

int arr[MAX][MAX];
int r,c,k,tiktok,max_col, max_row;
void funR();
void funC();
bool cmp(pair<int,int> p1, pair<int, int> p2);
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    cin >> r >> c >> k;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin >> arr[i][j];
    max_col = max_row = 3;
    bool notFound = false;
    while(arr[r][c] != k){
        if(tiktok > 100){
            notFound = true;
            break;
        }
        if(max_row >= max_col) funR();
        else funC();
        tiktok++;
    }
    if(notFound) cout << -1 << endl;
    else cout << tiktok << endl;
    return 0;
}
void funR(){
    int tmp = max_col;
    for(int i=1;i<=max_row;i++){
        // 가로 한줄씩 실행
        map<int,int> m;
        vector<pair<int,int>> v;
        for(int j=1;j<=max_col;j++){
            if(arr[i][j] == 0) continue;
            m[arr[i][j]]++;
            arr[i][j] = 0;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            v.push_back({it->first,it->second});
        }
        sort(v.begin(),v.end(),cmp);
        int index = 1;
        bool reachLimit = false;
        for(int j=0;j<v.size();j++){
            arr[i][index] = v[j].first;
            arr[i][index+1] = v[j].second;
            if(index+1 >= 100){
                reachLimit = true;
                break;
            }
            index+=2;
        }
        if(reachLimit) tmp = 100;
        else tmp = max(tmp, (int)v.size()*2);
        m.clear();
        v.clear();
        //
    }
    max_col = tmp;
}
void funC(){
    int tmp = max_row;
    for(int i=1;i<=max_col;i++){
        map<int,int> mm;
        vector<pair<int,int>> vv;
        for(int j=1;j<=max_row;j++){
            if(arr[j][i] == 0) continue;
            mm[arr[j][i]]++;
            arr[j][i] = 0;
        }
        for(auto it = mm.begin();it != mm.end();it++){
            vv.push_back({it->first, it->second});
        }
        sort(vv.begin(),vv.end(),cmp);
        int index = 1;
        bool reachLimit = false;
        for(int j=0;j<vv.size();j++){
            arr[index][i] = vv[j].first;
            arr[index+1][i] = vv[j].second;
            if(index+1 >= 100){
                reachLimit = true;
            }
            index += 2;
        }
        if(reachLimit) tmp = 100;
        else tmp = max(tmp, (int)vv.size() * 2);
        mm.clear();
        vv.clear();
    }
    max_row = tmp;
};
bool cmp(pair<int,int> p1, pair<int, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
