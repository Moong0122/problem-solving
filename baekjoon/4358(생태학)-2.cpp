#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int NUM = 95;
vector<string> v;

struct Trie{
    Trie* children[NUM];
    bool finish;
    bool isRead;
    double cnt;
    
    // 생성자
    Trie(): finish(false),isRead(false),cnt(0){
        for(int i=0;i<NUM;i++){
            children[i] = NULL;
        }
    }
    // 소멸자
    ~Trie(){
        for(int i=0;i<NUM;i++){
            if(children[i]) delete children[i];
        }
    }
    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
            cnt++;
        }else{
            int num = *key -  32;
            if(children[num] == NULL){
                children[num] = new Trie();
            }
            children[num]->insert(key+1);
        }
    }
    int getCnt(const char* key){
        if(*key == '\0'){
            if(!isRead){
                isRead = true;
                return cnt;
            }else return -1;
        }
        int number = *key - 32;
        if(children[number] == NULL) return 0;
        return children[number]->getCnt(key+1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int total = 0;
    string str;
    Trie trieNode;
    while(getline(cin, str)) {
        v.push_back(str);
        total++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<total;i++){
        trieNode.insert(v[i].c_str());
    }
    for(int i=0;i<total;i++){
        double tmp = trieNode.getCnt(v[i].c_str());
        if(tmp == -1) continue;
        cout << fixed;
        cout.precision(4);
        cout << v[i] << " " << (tmp / total) * 100 << endl;
    }
    return 0;
}
