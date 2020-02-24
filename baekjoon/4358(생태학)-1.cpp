#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> m;
int main(){
    string str;
    double total = 0;
    while(getline(cin, str)){
        total++;
        m[str]++;
    }
    cout << fixed;
    cout.precision(4);
    for(auto it=m.begin();it!=m.end();it++){
        cout << it->first << " " << (it->second / total) * 100 << endl;
    }
    return 0;
}
