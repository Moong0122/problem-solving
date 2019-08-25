#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[40001];
int main(){
	vector<int> line;
	int n,a,max = -1,pointer = 0;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a;
		line.push_back(a);
		if(dp[pointer] < line[i])
			dp[++pointer] = line[i];
		else if(line[i] < dp[pointer]){
			int l=0;
			int r = pointer;
			int mid;
			while(l<r){
				mid = (l+r)/2;
				if(dp[mid] < line[i])
					l = mid + 1;
				else
					r = mid;
			}
			dp[r] = line[i];
		}
	}
	cout << pointer << endl;
	return 0;
}

// 다른 풀이
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<vector>
//using namespace std;
//
//vector<int> line;
//int main(){
//    int n,a,b;
//    cin >> n;
//    for(int i=0;i<n;i++){
//        cin >> a;
//        b = lower_bound(line.begin(),line.end(),a) - line.begin();
//        // 왜 빼주는가?
//        // 이 함수의 리턴값은 찾고자 하는 값의 포인터(위치)이기 때문에 다시 배열의 주소값을 빼주면 해당 위치가 나옵니다
//        // 벡터는 .begin()값을 빼면 된
//        // 하지만 배열을 받을 때 0을 베이스로 했기 때문에 1을 추가해준다 밑에 처럼
//        // lower_bound(num, num+n, k) - num +1
//        if(b == line.size())
//            line.push_back(a);
//        else
//            line[b] = a;
//    }
//    cout << line.size() << endl;
//    return 0;
//}
//// 일반적으로 lower_bound(시작위치, 마지막 위치 +1, 찾고자하는 값)입니다.
