#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

char str[10];
queue<int> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(!strcmp(str,"push")){
            int n;
            cin >> n;
            q.push(n);
        }
        else if(!strcmp(str,"pop")){
            if(q.size() == 0) cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(!strcmp(str,"size")){
            cout << q.size() << '\n';
        }
        else if(!strcmp(str,"empty")){
            cout << q.empty() << '\n';
        }
        else if(!strcmp(str,"front")){
            if(q.size() == 0) cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
            }
        }
        else if(!strcmp(str,"back")){
            if(q.size() == 0) cout << -1 << '\n';
            else{
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
