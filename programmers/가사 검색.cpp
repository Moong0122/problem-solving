#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

const int NUM = 27;

// 각 알파벳에 해당하는 번호 지정해주는 함수 a = 0 ~ z = 25, ? = 26
int toNumber(char n) {
    if (n == '?')
    {
        return 26;
    }

    return n - 'a';
}
// 트라이 구조체 선언
struct TrieNode
{
    TrieNode* children[NUM];
    bool terminal;
    int cnt;

    // 모든 포인터 초기화
    TrieNode() :terminal(false), cnt(0)
    {
        for (int i = 0; i < NUM; ++i)
        {
            children[i] = NULL;
        }
    }

    ~TrieNode()
    {
        for (int i = 0; i < NUM; i++)
        {
            if (children[i])
            {
                delete children[i];
            }
        }
    }
    void insert(const char* key)
    {

        if (*key == 0)
        {
            terminal = true;
        }
        else
        {
            int next = toNumber(*key);
            if (children[next] == NULL)
            {
                children[next] = new TrieNode();
            }

            children[next]->insert(key + 1);
        }
    }

    void find(const char* key)
    {
        if (*key == 0)
        {
            cnt++;
            return;
        }

        int next = toNumber(*key);
        if (children[toNumber('?')] != NULL)
        {
            children[toNumber('?')]->find(key + 1);
        }

        if (children[next] != NULL)
        {
            children[next]->find(key + 1);
        }
    }

    int getCnt(const char* key)
    {
        if (*key == 0)
        {
            return cnt;
        }

        int next = toNumber(*key);
        if (children[next] == NULL)
        {
            return 0;
        }

        return children[next]->getCnt(key + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    TrieNode trie;
    
    for (int i = 0; i < queries.size(); ++i)
    {
        trie.insert(queries[i].c_str());
    }
    for (int i = 0; i < words.size(); ++i)
    {
        trie.find(words[i].c_str());
    }
    for (int i = 0; i < queries.size(); ++i)
    {
        answer.push_back(trie.getCnt(queries[i].c_str()));
    }

    return answer;
}

// 풀이보고 공부한 코드
#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;

const int NEXT_CNT = 26;

class Trie
{
    private:
        Trie* next[NEXT_CNT] = {nullptr, }; // 배열 이름이 next이다
        int cnt = 0;
        bool finish = false;
    
    public:
        Trie() = default;
        
        ~Trie()
        {
            for (int i = 0; i < NEXT_CNT; i++) {
                if (next[i] != nullptr) delete next[i];
            }
        }
    
        void insert(const string& str)
        {
            Trie* curr = this;
            
            for (char c : str) {
                curr->cnt++;
                
                if (curr->next[c - 'a'] == nullptr)
                    curr->next[c - 'a'] = new Trie();
                
                curr = curr->next[c - 'a'];
            }
            
            curr->finish = true;
        }
    
        Trie* find(const string& str)
        {
            Trie* curr = this;
            
            for (char c : str) {
                curr = curr->next[c - 'a'];
                
                if (curr == nullptr) break;
            }
            
            return curr;
        }
    
        int countStartWith(const string& str)
        {
            string pre = str.substr(0, str.find('?'));
            
            Trie* p = find(pre);
            return (p != nullptr) ? p->cnt : 0;
        }
    
};

vector<int> solution(vector<string> words, vector<string> queries) {
    unordered_map<int, Trie> trie_forward;
    unordered_map<int, Trie> trie_backward;
    
    for (string word : words) {
        trie_forward[word.length()].insert(word);
        trie_backward[word.length()].insert(string(word.rbegin(), word.rend()));
    }
    
    vector<int> answer;
    for (string query : queries) {
        int cnt = 0;
        
        if (query.front() == '?') {
            cnt = trie_backward[query.length()].countStartWith(string(query.rbegin(), query.rend()));
        } else {
            cnt = trie_forward[query.length()].countStartWith(query);
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
