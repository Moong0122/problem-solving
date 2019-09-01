#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	vector <int> v;
	int n,a;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int sum = 0;

	for(int i=0;i<n;i++){
		if(sum+1 < v[i]){
			break;
		}else{
			sum += v[i];
		}
	}
	cout << sum + 1 << endl;
	return 0;
}