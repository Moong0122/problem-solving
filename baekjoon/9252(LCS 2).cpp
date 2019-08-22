#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string str1,str2;
int dp[1001][1001];
int MAX(int x, int y){
	return x>y?x:y;
}
int main(){
	string tmp1, tmp2, ans = "";
	cin >> tmp1 >> tmp2;
	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size(); 
	int len2 = str2.size();
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout << dp[len1-1][len2-1] << endl;
	int cnt = dp[len1-1][len2-1],check = 0;
	for(int i = len1-1;i>=0;i--){
		for(int j = len2-1;j>=0;j--){
			if(cnt == 0){
				check = 1;
				break;
			}
			if(dp[i][j] == cnt && str1[i] == str2[j]){
				ans.push_back(str1[i]);
				cnt--;
				break;
			}
		}
		if(check == 1)
			break;
	}
	int finish = ans.size();
	for(int i = finish-1;i>=0;i--){
		cout << ans[i];
	}

	return 0;
}