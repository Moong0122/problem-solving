#include<iostream>
using namespace std;

int main(){
	int t;
	int l,u,x;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> l >> u >> x;
		if(x < l)
			cout << "#" << i << " " << l-x << endl;
		else if(x >= l && x <= u)
			cout << "#" << i << " 0" << endl;
		else
			cout << "#" << i << " -1" << endl;
	}
	return 0;
}