#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<string> input;
vector<pair<int,long long>> v;
long long alpha[10];
bool digit[10], isFind;
int n, check[10];
bool isSatisfy(){
    for(int i=0;i<n;i++){
        if(check[input[i][0]-'A'] == 0) return false;
    }
    return true;
}
void searchMax(int index){
    if(isFind) return;
    if(index == v.size()){
        if(isSatisfy()){
            long long sum = 0;
            for(int i=0;i<v.size();i++){
                sum += check[v[i].first]* v[i].second;
            }
            cout << sum << '\n';
            isFind = true;
        }
        return;
    }
    for(int i=9;i>=0;i--){
        if(!digit[i]){
            digit[i] = true;
            check[v[index].first] = i;
            searchMax(index+1);
            check[v[index].first] = 0;
            digit[i] = false;
        }
    }
}
bool cmp(pair<int, long long> t1, pair<int, long long>t2){
    return t1.second > t2.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        input.push_back(str);
        for(int i=0;i<str.size();i++){
            alpha[str[i] - 'A'] += pow(10, str.size()-1-i);
        }
    }
    for(int i=0;i<10;i++) if(alpha[i] != 0) v.push_back({i,alpha[i]});
    // i 번째 번지에 속하는 알파벳이 가지는 가치를 pair로 같이 저장해준다
    sort(v.begin(),v.end(),cmp);
    searchMax(0);
    return 0;
}

