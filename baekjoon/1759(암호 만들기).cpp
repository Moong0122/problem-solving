#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l,c;
int j,m;
vector<char> input;
string str;
void dfs(int pos,int start);
int main(){
	char a;

	cin >> l >> c;
	for(int i=0;i<c;i++){
		cin >> a;
		input.push_back(a);
	}
	sort(input.begin(),input.end());
	dfs(0,0);
	return 0;
}
void dfs(int pos,int start){
	if(pos == l){
		j = 0;
		m = 0;
		for(int i=0;i<l;i++){
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				m++;
			else
				j++;
		}
		if(m >= 1 && j >=2){
			cout << str << endl;
		}
		return;
	}
	for(int i=start;i<c;i++){
		str.push_back(input[i]);
		dfs(pos+1,i+1);
		str.pop_back();
	}
}