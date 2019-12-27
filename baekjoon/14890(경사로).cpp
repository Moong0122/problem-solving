#include<iostream>
#include<string.h>
using namespace std;

int a[101][101], b[101][101];
int n,l,result;
void check(int row, int a[101][101]);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        check(i,a);
        check(i,b);
    }
    cout << result << endl;
    
}
void check(int row, int a[101][101]){
    bool c[101] = {false,};
    int temp = a[row][0];
    for(int i=0;i<n;i++){
        if(a[row][i] != temp){
            if(abs(a[row][i]-temp) > 1) return;
            if(a[row][i] < temp){
                int num = -1;
                for(int j=i;j<=i+l-1;j++){
                    if(j>=n || c[j]) return;
                    c[j] = true;
                    if(num == -1) {
                        num = a[row][j];
                        continue;
                    }
                    if(num != -1 && a[row][j] != num) return;
                }
                i = i+l-1;
                if(i>=n) break;
            }else{
                int num = -1;
                for(int j=i-1;j>=i-l;j--){
                    if(j<0 || c[j]) return;
                    c[j] = true;
                    if(num == -1){
                        num = a[row][j];
                        continue;
                    }
                    if(num != -1 && a[row][j] != num) return;
                }
            }
            temp = a[row][i];
        }
    }
    result++;
}
