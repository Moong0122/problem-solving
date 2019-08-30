#include<iostream>
#include<vector>
#include<cstdio>
#include<math.h>

using namespace std;

vector <int> v;
int main(){
	int n;
	cin >> n;
	printf("%lld\n", (long long)pow(pow(2,n)+1,2));
	return 0;
}