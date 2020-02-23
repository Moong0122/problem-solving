#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int NUM = 10;

vector<string> v;
bool answer;
bool cmp(string s1, string s2){
    return s1.size() > s2.size();
}

struct Trie {
    Trie* children[NUM];
    bool finish;
    
    // 트라이 배열 포인터 초기화
    Trie() :finish(false){
        for(int a=0;a<NUM;a++){
            children[a] = NULL;
        }
    }
    ~Trie(){
        for(int a=0;a<NUM;a++){
            if(children[a]){
                delete children[a];
            }
        }
    }
    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
            for(int a=0;a<NUM;a++)
                if(children[a] != NULL) answer = false;
        }else{
            int num = *key - '0';
            if(children[num] == NULL){
                children[num] = new Trie();
            }
            children[num]->insert(key+1);
        }
    }
};

int main(){
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        //
        Trie trieNode;
        answer = true;
        cin >> n;
        for(int j=0;j<n;j++){
            //
            string str;
            cin >> str;
            v.push_back(str);
            //
        }
        sort(v.begin(),v.end(),cmp);
        for(int j=0;j<n;j++){
            trieNode.insert(v[j].c_str());
        }
        if(answer) cout << "YES" << endl;
        else cout << "NO" << endl;
        v.clear();
        //
    }
    return 0;
}

