#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int MAX = 50;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> live;
int city[MAX][MAX];
int n,m, small = 100000000;
void DFS(int current, int level);
int compareDis(int length);
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> city[i][j];
            if(city[i][j] == 1)
                house.push_back({i,j});
            else if(city[i][j] == 2)
                chicken.push_back({i,j});
        }
    }
    DFS(0,0);
    cout << small << endl;
    return 0;
}
void DFS(int current, int level){
    if(level <= m && level >= 1){
        int ans = compareDis(level);
        if(ans < small){
            small = ans;
        }
        if(level == m)
            return;
    }
    int len = chicken.size();
    for(int i=current;i<len;i++){
            pair<int, int> tmp = chicken[i];
            live.push_back(tmp);
            DFS(i+1,level+1);
            live.pop_back();
    }
}
int compareDis(int length){
    int sum = 0;
    int temp = 100000000;
    for(int i=0;i<house.size();i++){
        int y = house[i].first;
        int x = house[i].second;
        temp = 100000000;
        for(int j=0;j<length;j++){
            temp = min(temp,abs(y-live[j].first)+abs(x-live[j].second));
        }
        sum += temp;
    }
    return sum;
}
