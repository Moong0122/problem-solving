#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> one;
vector<int> two;
int soccer[21][21];
bool check_visit[21];
int small = 10000000;
void dfs(int pos,int start,int size);
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> soccer[i][j];
        }
    }
    dfs(0,1,n/2);
    cout << small << endl;
    return 0;
}
void dfs(int pos,int start,int size){
    if(pos == size){
        int p = 0,one_sum = 0, two_sum = 0;
        for(int i=1;i<=size*2;i++){
            if(i == one[p])
                p++;
            else
                two.push_back(i);
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                one_sum += soccer[one[i]][one[j]];
                two_sum += soccer[two[i]][two[j]];
            }
        }
        if(abs(one_sum-two_sum)< small)
            small = abs(one_sum-two_sum);
        two.clear();
        return;
    }
    for(int i=start;i<=size*2;i++){
        if(!check_visit[i]){
            check_visit[i] = true;
            one.push_back(i);
            dfs(pos+1,i,size);
            one.pop_back();
            check_visit[i] = false;
        }
    }
}
