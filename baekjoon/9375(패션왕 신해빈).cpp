#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<pair<int, string> > v;

void check(string s1, string s2);
int main(){
	string name,s;
	int n,t;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		for(int j=1;j<=t;j++){
			cin >> name >> s;
			check(name,s);
		}
		int result = 1;
		int len = v.size();
		for(int j=0;j<len;j++){
			result *= (v[j].first+2);
		}
		cout << result - 1 << endl;
		v.clear();
	}
	return 0;
}
void check(string s1, string s2){
	int len = v.size();
	bool flag = true;
	for(int i=0;i<len && flag;i++){
		if(v[i].second == s2){
			v[i].first++;
			flag = false;
		}
	}
	if(flag)
		v.push_back(make_pair(0,s2));
}
