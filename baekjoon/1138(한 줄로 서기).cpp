#include<iostream>
#include<vector>
using namespace std;

int h[11];
int total[20];
void move(int target, int where, int size);
int main(){
	int n,a,j=1;
	cin >> n; // 4
	for(int i=1;i<=n;i++){
		cin >> h[i]; // 2 1 1 0
	}
	for(int i=n;i>=1;i--){
		move(i,h[i],n);
	}
	for(int i=0;i<n;i++){
		cout << total[i] << " ";
	}
}
void move(int target, int where, int size){
	if(total[where] == 0)
		total[where] = target;
	else{
		for(int i=size-1;i>=where;i--){
			total[i+1] = total[i];
		}
		total[where] = target;
	}
}

//다른 방법!
//#include<iostream>
//using namespace std;
//
//int person[11];
//int main(){
//    int n,a;
//    cin >> n;
//    for(int i=1;i<=n;i++){
//        cin >> a;
//        for(int j=0;j<n;j++){
//            if(person[j] == 0 && a == 0){
//                person[j] = i;
//                break;
//            }
//            else if(person[j] == 0)
//                a--;
//        }
//    }
//    for(int i=0;i<n;i++){
//        cout << person[i] << " ";
//    }
//    return 0;
//}
