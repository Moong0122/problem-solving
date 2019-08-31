#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;


int main(){
	int sum = 0;
	string s;
	vector <int> v;
	cin >> s;
	int len = s.size();

	for(int i=0;i<len;i++){
		v.push_back(s[i] - 48);
		sum += (s[i] - 48); 
	}
	sort(v.begin(),v.end(),greater<int>());
	if(v[len-1] != 0 || sum % 3 != 0)
		cout << "-1" << endl;
	else{
		for(int i=0;i<len;i++){
			cout << v[i];
		}
	}
	return 0;
}