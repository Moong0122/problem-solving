#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<pair<int,int> > v;
int dp[16];
int getDP(int x);
int find(int x);
int main(){
	int n,a,b;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	int big = -1;
	for(int i=0;i<n;i++){
		if(i + v[i].first > n){
			dp[i] = find(i);
		}else{
			dp[i] = v[i].second + find(i);
		}
		if(dp[i] > big)
			big = dp[i];
	}
	cout << big << endl;
	return 0;
}
int getDP(int x){
	if(x < 0)
		return 0;
	return dp[x];
}
int find(int x){
	int answer = 0;
	for(int i=x-1;i>=0;i--){
		if(i + v[i].first <= x && dp[i] > answer){
			answer = dp[i];
		}
	}
	return answer;
}