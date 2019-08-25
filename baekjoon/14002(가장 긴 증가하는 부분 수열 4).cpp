#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> total;
int dp[10001];
int main(){
	int n,a,max = -1, max_num;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		arr.push_back(a);
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if(dp[i] > max){
			max = dp[i];
			max_num = i;
		}
	}
	cout << max << endl;
	int check = arr[max_num];
	total.push_back(arr[max_num]);

	for(int i=(max_num - 1);i>=0;i--){
		if(dp[i] == max - 1 && check > arr[i]){
			total.push_back(arr[i]);
			max--;
			check = arr[i];
		}
	}
	for(int i=total.size()-1;i>=0;i--){
		cout << total[i] << " ";
	}
	return 0;
}
