#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct{
	int a;
	int b;
}position;

int dp[101];
position p[101];
bool compare(const position &p1, const position &p2){
	if(p1.a < p2.a)
		return true;
	if(p1.a == p2.a)
		return p1.b < p2.b;
	else
		return false;
}
int main(){
	int n,max = -1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p[i].a >> p[i].b;
	}
	sort(p,p+n,compare);
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(p[i].b > p[j].b && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if(dp[i] > max)
			max = dp[i];
	}
	cout << n-max << endl;
	return 0;
}