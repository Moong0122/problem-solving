// 1. 이중포문을 이용한 직관적인 풀이
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    for (int i = 0 ; i < phone_book.size() ; i++) {
        for (int j = i+1 ; j < phone_book.size() ; j++) {
            string str1 = phone_book[i];
            string str2 = phone_book[j];
            
            if (str1.size() > str2.size()) swap(str1, str2);
            
            if (str1.compare(str2.substr(0, str1.size())) == 0)
                return false;
        }
    }
    return true;
}

// 2. unordered_set과 prioirty_queue를 사용하는 방법 (정리하기)

// 3. 트라이 자료구조
#include <string>
#include <vector>
#include <iostream>
#include <string.h> // memset
using namespace std;

class Trie
{
private:
    Trie* next[10];
    int cnt = 0;
    bool finish = false;

public:
    Trie()
    {
        // next 배열 0으로 초기화
        memset(next, 0, sizeof(next));
    }

    ~Trie()
    {
        // 할당한 메모리 해제 - Trie() 삭제
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }

    bool insert(const string& str)
    {
        // this 포인터(객체 자신을 가리키는 포인터)
        Trie* curr = this;

        // 받은 문자열을 하나의 char씩 보면서 만약
        // nullptr(널포인터)라면 새로운 Trie를 만들어준다.
        for (char c : str) {
            if (curr->next[c - '0'] == nullptr) {
                curr->next[c - '0'] = new Trie();
            }

            // 다른 문자열이 str의 접두어인 경우
            if (curr->finish == true) {
                return false;
            }

            curr = curr->next[c - '0'];
        }

        // str이 다른 문자열의 접두어인 경우
        for (int i = 0; i < 10; i++) {
            // nullptr이 아니라면(내 뒤에 숫자들이 더 나온다면 = 접두어라면)
            if (curr->next[i] != nullptr)
                return false;
        }

        curr->finish = true;
        return true;
    }
};


bool solution(vector<string> phone_book) {
    Trie trie;
    for (auto& numbers : phone_book) {
        if (trie.insert(numbers) == false) {
            return false;
        }
    }

    return true;
}
