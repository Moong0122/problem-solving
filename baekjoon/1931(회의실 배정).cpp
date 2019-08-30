#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef struct{
	long start;
	long finish;
}ti;

ti T[100001];
// new를 써서 동적할당해도 좋을 것 같다
bool compare(const ti &p1, const ti &p2);
int check(int s, int f, int size);
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> T[i].start >> T[i].finish;
	}
	sort(T,T+n,compare);
	cout << check(0,0,n)+1 << endl;
	return 0;
}
int check(int s, int f, int size){
	int i,cnt = 0;
	for(i = 1; i < size ; i++){
		if(T[i].start >= T[f].finish){
			cnt++;
			f = i;
		}
	}
	return cnt;
}
bool compare(const ti &p1, const ti &p2){
	if(p1.finish < p2.finish)
		return true;
	if(p1.finish == p2.finish)
		return p1.start < p2.start;
	return false;
}
