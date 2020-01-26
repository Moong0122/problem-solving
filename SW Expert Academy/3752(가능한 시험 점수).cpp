#include<iostream>
#include<string.h>
using namespace std;
int v[101];
int check[10001];
int n, ans;

int main(){
	int t;
	cin >> t;
	for(int aa = 1; aa<=t;aa++){
		//
		cin >> n;
		memset(v,0,sizeof(v));
		memset(check,0,sizeof(check));
		ans = 0;
		int big = 0;
		check[0] = 1;

		for(int i=0;i<n;i++){
			cin >> v[i];
			big += v[i];
			for(int j=big;j>=0;j--){
				if(check[j] > 0){
					check[j+v[i]]++;
				}
			}
			check[v[i]]++;
		}
		for(int i=0;i<10001;i++){
			if(check[i] > 0)
				ans++;
		}
		cout << "#" << aa << " " << ans << endl;
		//
	}
	return 0;
}
