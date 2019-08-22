#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string str1, str2;
int dp[1001][1001];

int getDP(int x, int y){
	if(x<0 || y<0)
		return 0;
	return dp[x][y];
}
int MAX(int x, int y){
	return x>y?x:y;
}
int main(){
	string tmp1, tmp2;
	cin >> str1 >> str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(str1[i] == str2[j])
				dp[i][j] = getDP(i-1,j-1)+1;
			else
				dp[i][j] = MAX(getDP(i-1,j),getDP(i,j-1));
		}
	}
	cout << dp[len1-1][len2-1] << endl;
	return 0;
}
