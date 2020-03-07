#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 10000;

int arr[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    if(prev_permutation(arr, arr+n)){
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        cout << '\n';
    }else cout << -1 << '\n';
    return 0;
}

/* 다른 방법!
 #include<iostream>
 #include<algorithm>
 using namespace std;
 const int MAX = 10001;

 int arr[MAX];
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     int n;
     cin >> n;
     for(int i=1;i<=n;i++) cin >> arr[i];
     
     int tmp_index = n;
     int tmp = arr[n];
     for(int i = n ; i >= 2 ; i--){
         if(arr[i-1] > arr[i]){
             tmp_index = i-1;
             tmp = arr[i-1];
             break;
         }
     }
     if(tmp_index == n){
         cout << -1 << '\n';
         return 0;
     }
     for(int i=n;i> tmp_index; i--){
         if(tmp > arr[i]){
             int temp = arr[tmp_index];
             arr[tmp_index] = arr[i];
             arr[i] = temp;
             break;
         }
     }
     for(int i=tmp_index+1;i<=n-1;i++){
         for(int j=i+1;j<=n;j++){
             if(arr[i] < arr[j]){
                 int tmp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = tmp;
             }
         }
     }
     for(int i=1;i<=n;i++) cout << arr[i] << " ";
     cout << '\n';
     return 0;
 }

 */
