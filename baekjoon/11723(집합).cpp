#include<iostream>
#include<map>
using namespace std;

bool arr[21];
void empty(){
    for(int i=1;i<=20;i++) arr[i] = false;
}
void all(){
    for(int i=1;i<=20;i++) arr[i] = true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int num;
        string str;
        cin >> str;
        //
        if(str == "add"){
            cin >> num;
            if(!arr[num]) arr[num] = true;
        }else if(str == "remove"){
            cin >> num;
            if(arr[num]) arr[num] = false;
        }else if(str == "toggle"){
            cin >> num;
            if(arr[num]) arr[num] = false;
            else arr[num] = true;
        }else if(str == "check"){
            cin >> num;
            if(arr[num]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "all") all();
        else if(str == "empty") empty();
        //
    }
    return 0;
}
