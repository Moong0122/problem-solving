#include<iostream>
#include<queue>
using namespace std;
const int MAX = 2000;

bool check_visit[MAX][MAX];
struct emo{
    int cnt, clipboard, t_time;
};
int emoticon;
void BFS(){
    queue<emo> q;
    q.push({1,0,0});
    check_visit[1][0] = true;
    
    while(!q.empty()){
        int window = q.front().cnt;
        int copy = q.front().clipboard;
        int t = q.front().t_time;
        q.pop();
        
        if(window == emoticon){
            cout << t << '\n';
            break;
        }
        if(window > 0 && window < MAX){
            if(!check_visit[window][window]){
                check_visit[window][window] = true;
                q.push({window,window,t+1});
            }
            if(!check_visit[window-1][copy]){
                check_visit[window-1][copy] = true;
                q.push({window-1,copy,t+1});
            }
        }
        if(copy > 0 && window+copy < MAX && !check_visit[window+copy][copy]){
            check_visit[window+copy][copy] = true;
            q.push({window+copy,copy,t+1});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> emoticon;
    BFS();
    return 0;
}

