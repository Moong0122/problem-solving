#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int s,g;
	int a,b,n,w;
	cin >> a >> b >> n >> w;
	bool find = false;
	bool doubleFind = false;
	for(int i=1;i<n;i++){
		if( (a*i + b*(n-i)) ==  w){
			if(find == false){
				s = i;
				g = (n-i);
				find = true;
			}else{
				doubleFind = true;
				break;
			}
		}
	}
	if(doubleFind == true || find == false)
		cout << -1 << endl;
	else
		cout << s << " " << g << endl;
	return 0;
}