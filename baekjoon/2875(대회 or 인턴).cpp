#include<iostream>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;

	while(k>0){
		if(n > m*2){
			k -= (n-m*2);
			n = m*2;
		}else if(n/2 < m){
			k -= (m-n/2);
			m = n/2;
		}else{
			n -= 2;
			k -= 2;
		}
	}
	if(n/2 == m)
		cout << m << endl;
	else
		cout << n/2 << endl;
	return 0;
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main(void)
//{
//    int N, M, K;
//    cin >> N >> M >> K;
//
//    //K가 없을 경우 두 가지
//    //K가 있을 경우
//    cout << min(min(N/2, M), (N+M-K)/3) << "\n";
//    return 0;
//}
//1. 대회에 보낼 인원이 없을 경우
//    i) 여자 인원 / 2
//    ii) 남자 인원
//2. 대회에 보낼 인원이 있을 경우
//    (여자 인원 + 남자 인원 - 대회에 보낼 인원) / 3
