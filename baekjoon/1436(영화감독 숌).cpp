#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector <int> v;
void change(int number);
bool compare();

int main(){
	int n,cnt = 0;
	cin >> n;

	int start = 666;
	while(n!=0){
		change(start);

		if(compare()){
			n--;
		}
		start++;
		v.clear();
	}
	cout << start-1 << endl;
	return 0;
}
void change(int number){
	while(number != 0){
		v.push_back(number%10);
		number /= 10;
	}
}
bool compare(){
	int len = v.size();
	int total;

	for(int i=0;i<=len-3;i++){
		total = 0;

		if(v[i] == 6)
			total++;
		if(v[i+1] == 6)
			total++;
		if(v[i+2] == 6)
			total++;

		if(total == 3)
			return true;
	}
	return false;
}