#include<iostream>
#include<vector>
using namespace std;

int dis[4] = {-2,-1,1,2};
int main(){
	vector<int> v;
	int n,a,max,sum;

	for(int i = 1;i<=10;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> a;
			v.push_back(a);
		}
		sum = 0;
		for(int j=2;j<n-2;j++){
			max = -1;
			for(int k=0;k<4;k++){
				int x = j + dis[k];
				if(v[x] > max)
					max = v[x];
			}
			if(max < v[j])
				sum += v[j] - max;
		}
		cout << "#"<< i << " " << sum << endl;
		v.clear();
	}
	return 0;
}