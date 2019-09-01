#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector <int> p;
	vector <int> o;
	int n,m,a,b;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
        // sort를 굳이 하지 않더라도 여기서 최소를 바로 구할 수 있다!!
        // pmin = min(pmin,a);
        // omin = min(omin,b);
		p.push_back(a);
		o.push_back(b);
	}
	sort(p.begin(),p.end());
	sort(o.begin(),o.end());
	int package = p[0];
	int one = o[0];

	if(package > one*6)
		cout << one*n << endl;
	else if(n % 6 == 0)
		cout << package * (n/6) << endl;
	else
		cout << min(package*(n/6+1), package*(n/6) + one*(n%6)) << endl;
	return 0;
}
