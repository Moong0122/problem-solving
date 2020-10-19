// 처음 풀었을 때
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Loc{
    int oY, oX, tY, tX;
};

int changeToNum(char dir){
    int value;
    if (dir == 'U') {
        value = 0;
    }
    else if (dir == 'L') {
        value = 1;
    }
    else if (dir == 'R') {
        value = 3;
    }
    else {
        value = 2;
    }
    return value;
}
int solution(string dirs) {
    int answer = 0;
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};
    bool visit[11][11][11][11];
  
    queue<Loc> q;
    q.push({5, 5, 5, 5});
    visit[5][5][5][5] = true;
    
    for (auto i : dirs) {
        Loc l =  q.front();
        q.pop();
        
        int nextDir = changeToNum(i);
        int nextY = l.tY + dy[nextDir];
        int nextX = l.tX + dx[nextDir];
        if (nextY < 0 || nextX < 0 || nextY > 10 || nextX > 10) { // 범위 이탈
            q.push(l);
            continue;
        }
        else { // 이미 방문한 적이 있거나 새롭게 이동한 칸을 저장해줘야 한다.
            if (!visit[l.tY][l.tX][nextY][nextX] && !visit[nextY][nextX][l.tY][l.tX]) {
                visit[l.tY][l.tX][nextY][nextX] = true;
                visit[nextY][nextX][l.tY][l.tX] = true;
                answer++;
            }
            q.push({l.tY, l.tX, nextY, nextX});
        }
    }
    
    return answer;
}

// 피드백 후
#include <string>
#include <tuple>
#include <set>
using namespace std;

int solution(string dirs) {
    int y = 0, x = 0;
    int beforeY = y, beforeX = x;
    
    // 튜플안에 들어갈 데이터 타입을 정해주고 컨테이너 이름(edge)을 정해준다 (구조체를 만드는 것과 비슷하다)
    using edge = tuple<int, int, int, int>; // beforeY, beforeX, y, x
    // set안에는 edge를 저장해준다.
    set<edge> passed;
    
    for (char c : dirs) {
        switch (c) {
            case 'U':
                if (y < 5) {
                   y++;
                }
            break;
            case 'D':
                if (y > -5) {
                    y--;
                }
            break;
            case 'R':
                if (x < 5) {
                    x++;
                }
            break;
            case 'L':
                if (x > -5) {
                    x--;
                }
            break;
        }
        
        if (beforeY == y && beforeX == x) {
            continue;
        }
        
        passed.insert(make_tuple(beforeY, beforeX, y, x));
        passed.insert(make_tuple(y, x, beforeY, beforeX));
        beforeY = y;
        beforeX = x;
    }
    return passed.size() / 2;
}
