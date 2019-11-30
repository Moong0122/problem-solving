#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<int> s;
vector<int> v;
vector<char> answer;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool findAnswer = true;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
    	int a;
    	cin >> a;
    	v.push_back(a);
    }
    int pos = 0;
    int num = 1;
    while(pos<n){
    	if(!s.empty()){
    		if(s.top() == v[pos]){
    			s.pop();
    			answer.push_back('-');
    			pos++;
    		}else if(s.top() < v[pos]){
	    		s.push(num);
	    		num++;
	    		answer.push_back('+');	
    		}else if(s.top() > v[pos]){
    			findAnswer = false;
    			break;
    		}
    	}else{
    		s.push(num);
    		num++;
    		answer.push_back('+');
    	}
    }
    if(findAnswer){
    	int len = answer.size();
    	for(int i=0;i<len;i++){
    		cout << answer[i] << '\n';
    	}
    }else
    	cout << "NO" << endl;
    return 0;
}
