#include<iostream>
#include<vector>
using namespace std;

int graph[101][101];
int m[4][2] = {
                {0,1},
                {1,0},
                {0,-1},
                {-1,0}
            };
vector<pair<int,int> > snack;
vector<pair<int,char> > moveNext;
int changeDirection(char al);
int t = 0, currentState = 0, n;
int length = 0;
int main(){
    cin >> n;

    int apple;
    int a,b;
    char c;
    cin >> apple;

    for(int i=0;i<apple;i++){
        cin >> a >> b;
        graph[a][b] = 2;
    }
    int rotate;
    cin >> rotate;
    for(int i=0;i<rotate;i++){
        cin >> a >> c;
        moveNext.push_back(make_pair(a,c));
    }
    graph[1][1] = 1;
    snack.push_back(make_pair(1,1));
    length++;

    while(1){
        t++;
        pair<int,int> tmp = snack.back();
        int x = tmp.first + m[currentState][0];
        int y = tmp.second + m[currentState][1];

        if(x>n || y>n || x <= 0 || y <= 0)
            break;
        if(graph[x][y] == 1)
            break;
        if(graph[x][y] == 2){
            snack.push_back(make_pair(x,y));
            graph[x][y] = 1;
            length++;
        }else{
            graph[snack[snack.size() - length].first][snack[snack.size() - length].second] = 0;
            snack.push_back(make_pair(x,y));
            graph[x][y] = 1;
        }

        int len = moveNext.size();
        for(int i=0;i<len;i++){
            if(t == moveNext[i].first){
                currentState = changeDirection(moveNext[i].second);
                break;
            }
        }
    }
    cout << t << endl;
}
int changeDirection(char al){
    int num;
    if(currentState == 0){
        if(al == 'L')
            num = 3;
        else
            num = 1;
    }else if(currentState == 1){
        if(al == 'L')
            num = 0;
        else
            num = 2;    
    }else if(currentState == 2){
        if(al == 'L')
            num = 1;
        else
            num = 3;    
    }else if(currentState == 3){
        if(al == 'L')
            num = 2;
        else
            num = 0;    
    }
    return num;
}
