#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> one;
vector<int> two;
bool compare(int p1, int p2);
int main(){
	int n,a;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a>0)
			one.push_back(a);
		else
			two.push_back(a);
	}
	// 3 ≤ n ≤ 10,000
	sort(one.begin(),one.end());
	sort(two.begin(),two.end(),compare);
	if(two.size() == 0){ // 음수 제로 
		cout << one[one.size()-1]*one[one.size()-2]*one[one.size()-3] << endl;
	}else if(two.size() == 1){ // 음수 1개
		if(one.size() == 2)
			cout << one[one.size()-1]*one[one.size()-2] << endl;
		else
			cout << one[one.size()-1]*one[one.size()-2]*one[one.size()-3] << endl;
	}else{ // two.size() >=2 음수가 2개 이상 있다면 
		if(one.size() == 0)
			cout << two[two.size()-1]*two[two.size()-2] << endl;
		else if(one.size() == 1)
			cout << max(two[two.size()-1]*two[two.size()-2]*one[one.size()-1],two[two.size()-1]*two[two.size()-2]) << endl;
		else if(one.size() == 2){
			int num = max(two[two.size()-1]*two[two.size()-2]*one[one.size()-1],two[two.size()-1]*two[two.size()-2]);
			cout << max(num,one[one.size()-1]*one[one.size()-2]) << endl;
		}else{
			int num = max(two[two.size()-1]*two[two.size()-2]*one[one.size()-1],two[two.size()-1]*two[two.size()-2]);
			int nnum = max(num,one[one.size()-1]*one[one.size()-2]);
			cout << max(nnum,one[one.size()-1]*one[one.size()-2]*one[one.size()-3]) << endl;
		}
	}
	return 0;
}
bool compare(int p1, int p2){
	return abs(p1) < abs(p2);
}


// 또 다른 풀이
// int main() 
// { 
// 	int n; 
// 	cin >> n; 
// 	vector<int> v; 
// 	for (int i = 0; i < n; i++){ 
// 		int input; cin >> input; 
// 		v.push_back(input); 
// 	} 
// 	sort(v.begin(), v.end()); 
// 	int result = max(v[n - 1] * v[n - 2], v[n - 1] * v[n - 2] * v[n - 3]); 
// 	if (v[0] * v[1] > 0){ 
// 		result = max(v[0] * v[1], result); 
// 		result = max(v[0] * v[1] * v[n - 1], result); 
// 	} 
// 	cout << result; 
//	return 0;
// }
