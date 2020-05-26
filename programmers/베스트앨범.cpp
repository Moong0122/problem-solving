#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<pair<int,int>>> m; // <고유 번호, 재생 횟수>

bool cmp(pair<int,int> p1, pair<int,int> p2){ // <고유 번호, 재생 횟수>
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}
bool cmpcmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> each_genres_play; // 장르당 재생 횟수를 저장하는 벡터
    int len = (int)genres.size();

    // genres, plays 모두 m에 삽입 완료
    for(int i = 0 ; i < len ; i ++)
    {
        m[genres[i]].push_back({i, plays[i]});
    }

    // m을 돌면서 가장 많이 재생된 장르를 파악해보기
    for(auto it = m.begin() ; it != m.end() ; it++)
    {
        int sum = 0;
        sort(it->second.begin(), it->second.end(), cmp);
        // 정렬 완료

        int genre_len = (int)it->second.size();
        for(int i = 0 ; i < genre_len ; i++)
        {
            sum += it->second[i].second;
        }

        each_genres_play.push_back({it->first, sum});
    }
    // each_genres_play 정렬해주기
    sort(each_genres_play.begin(), each_genres_play.end(), cmpcmp);

    int final_len = (int)each_genres_play.size();
    for(int i = 0 ; i < final_len ; i++)
    {
        for(int j = 0 ; j < 2 ; j++)
        {
            if(j >= (int)m[each_genres_play[i].first].size()) break;
            answer.push_back(m[each_genres_play[i].first][j].first);
        }
    }

    return answer;
}
