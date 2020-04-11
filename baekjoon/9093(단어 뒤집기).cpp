#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    string str;
    getline(cin,str);
    
    for(int i=0;i<testCase;i++){
        
        string s;
        getline(cin,s);
        
        string tmp="";
        for(int j=0;j<s.size();j++){
            if(s[j] == 32){
                reverse(tmp.begin(), tmp.end());
                cout << tmp << ' ';
                tmp.clear();
            }else tmp += s[j];
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << '\n';
    }
    return 0;
}
