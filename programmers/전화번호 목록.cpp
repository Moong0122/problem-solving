#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2){
    return s1.size() < s2.size();
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(int i = 0 ; i < phone_book.size() ; i++){
        for(int j = i + 1 ; j < phone_book.size() ; j++){
            if(phone_book[j].find(phone_book[i]) == 0) return false;
        }
    }
    return answer;
}
