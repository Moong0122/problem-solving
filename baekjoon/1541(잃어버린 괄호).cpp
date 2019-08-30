#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

vector <int> v;
vector <int> total;
int change();
int main(){
	string s;
	cin >> s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i] >= 48 && s[i] <= 57){
			v.push_back(s[i] - 48);
		}else{
			total.push_back(change());
			if(s[i] == '-')
				total.push_back(-1);
			else if(s[i] == '+')
				total.push_back(-2);
		}
	}
	total.push_back(change());
    
	int ll = total.size();
	int answer = 0, check = 0;
	for(int i=0;i<ll;i++){
		if(total[i] == -1){
			check = 1;
		}else if(total[i] == -2){
			continue;
		}else{
			if(check == 0)
				answer += total[i];
			else if(check == 1)
				answer += (total[i] * -1);
		}
	}
	cout << answer << endl;
	return 0;
}
int change(){
	int sum = 0;
	int llen = v.size();
	for(int i=0;i<llen;i++){
		sum += v[i] * pow(10,llen-1-i);
	}
	v.clear();
	return sum;
}


//다른 방법
//#include<cstdio> 추가해주기
//
//int main(){
//    int i=0,n,a;
//    char c;
//    
//    for(scanf("%d",&n);scanf("%c",&c),c!=10;){
//        if(c == '-')
//            i = 1;
//        scanf("%d",&a);
//        if(i)
//            n -= a;
//        else
//            n += a;
//    }
//    printf("%d\n",n);
//    return 0;
//}
