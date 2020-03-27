#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<pair<int, int>> appear_alpha;
vector<int> check_alpha;
bool check_num[10], isfind; // 1~9까지 중에서 어떤 것을 사용해줬는지 체크해준다
int alpha[26], n;
bool cmp(pair<int, int>t1, pair<int, int>t2){
    return t1.second > t2.second;
}
void searchMax(int depth){
    if(isfind) return;
    if(depth == appear_alpha.size()){
        int sum = 0;
        for(int i=0;i<appear_alpha.size();i++){
            sum += check_alpha[i] * appear_alpha[i].second;
        }
        cout << sum << '\n';
        isfind = true;
        return;
    }
    for(int i = 9 ; i >= 0 ; i--){
        if(!check_num[i]){
            check_alpha[depth] = i;
            check_num[i] = true;
            searchMax(depth+1);
            check_num[i] = false;
            check_alpha[depth] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        int len = (int)str.size();
        for(int j=0;j<len;j++){
            alpha[str[j] - 65] += pow(10, len-1-j);
        }
    }
    for(int i=0;i<26;i++){
        if(alpha[i] != 0) appear_alpha.push_back({i,alpha[i]});
        // 아스키코드로 i번째에 해당하는 알파벳의 중요도는 alpha[i]이다
    }
    sort(appear_alpha.begin(), appear_alpha.end(), cmp);
    check_alpha.resize(appear_alpha.size());
    searchMax(0);
    return 0;
}
