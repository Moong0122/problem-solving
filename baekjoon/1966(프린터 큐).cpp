#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int point;
vector <pair<int,int> > v;
bool checkbig();
void move();
int main(){
	int t,n,m,num;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> m;
		for(int j=0;j<n;j++){
			cin >> num;
			v.push_back(make_pair(j,num));
		}
		int cnt = 0;
		point = 0;
		while(1){
			if(v[point].first == m && checkbig()) // 조건 1,2를 다 만족한다면
				break;

			if(checkbig()){
				cnt++;
				point++;
			}
			else
				move();
		}
		cout << cnt+1 << endl;
		v.clear();
	}
}
bool checkbig(){
	int len = v.size();
	int max = v[point].second;
	for(int i=point+1;i<len;i++){
		if(v[i].second > max)
			max = v[i].second;
	}
	if(max == v[point].second) // 0번지에 있는 값이 가장 크다
		return true;
	return false;
}
void move(){ // 제일 앞에 있는 값을 뒤로 옮겨준다 만약 제일 큰 값이라면 point++해준다
	pair <int,int> p;
	p = v[point];
	v.push_back(p);
	point++;
}
