#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool check_visit[10]; // 0~9까지 방문 여부를 체크해준다
int k;
long big = -1, small = 9876543210;
vector<char> buho;
vector<int> number;
vector<int> small_v;
vector<int> big_v;
long changeToNum(){
    long sum = 0;
    for(int i=0;i<k+1;i++){
        sum += number[i] * pow(10, k-i);
    }
    return sum;
}
void DFS(int depth){
    if(depth == k){
        long tmp = changeToNum();
        if(tmp < small){
            small = tmp;
            small_v = number;
        }
        if(tmp > big){
            big = tmp;
            big_v = number;
        }
        return;
    }
    for(int i=0;i<10;i++){
        if(!check_visit[i]){
            if(buho[depth] == '<' && number[depth] < i){
                number.push_back(i);
                check_visit[i] = true;
                DFS(depth+1);
                check_visit[i] = false;
                number.pop_back();
            }else if(buho[depth] == '>' && number[depth] > i){
                number.push_back(i);
                check_visit[i] = true;
                DFS(depth+1);
                check_visit[i] = false;
                number.pop_back();
            }
        }
    }
}
int main(){
    cin >> k;
    buho.resize(k);
    for(int i=0;i<k;i++) cin >> buho[i];
    for(int i=0;i<10;i++){
        number.push_back(i);
        check_visit[i] = true;
        DFS(0);
        check_visit[i] = false;
        number.pop_back();
    }
    for(auto it : big_v) cout << it;
    cout << '\n';
    for(auto it : small_v) cout << it;
    cout << '\n';
    return 0;
}
