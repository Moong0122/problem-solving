#include<iostream>
#include<queue>
using namespace std;
const int MAX = 51;

int pan[MAX][MAX];
int n,m,t;
int left(int number){ // 1 , 2 , 3 , 4 반복
    if(number == 1) return m;
    return number - 1;
}
int right(int number){
    if(number == m) return 1;
    return number + 1;
}
void erase(){
    bool isErase = false; // 한번이라도 인접한 수를 지운 적이 있다면 true로 바뀐다
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j] == 0) continue;
            // 인접한 수 처리해주기
            int value = pan[i][j];
            queue<pair<int, int>> q;
            q.push({i,j});
            
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                if(y-1 >= 1 && pan[y-1][x] == value){
                    isErase = true;
                    pan[y-1][x] = 0;
                    q.push({y-1,x});
                }
                if(y+1 <= n && pan[y+1][x] == value){
                    isErase = true;
                    pan[y+1][x] = 0;
                    q.push({y+1,x});
                }
                if(pan[y][left(x)] == value){
                    isErase = true;
                    pan[y][left(x)] = 0;
                    q.push({y,left(x)});
                }
                if(pan[y][right(x)] == value){
                    isErase = true;
                    pan[y][right(x)] = 0;
                    q.push({y,right(x)});
                }
            }
            //
        }
    }
    int sum = 0, cnt = 0;
    if(!isErase){ // 지운적이 없다면
        //
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pan[i][j] != 0){
                    sum += pan[i][j];
                    cnt++;
                }
            }
        }
        //
        //
        if(cnt){
            double avg =  (double)sum / cnt;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(pan[i][j] != 0){
                        if(pan[i][j] > avg) pan[i][j]--;
                        else if(pan[i][j] < avg) pan[i][j]++;
                    }
                }
            }
        }
        //
    }
}
void spin(int panSize){
    int tmp = pan[panSize][m];
    for(int i = m; i>1;i--){
        pan[panSize][i] = pan[panSize][i-1];
    }
    pan[panSize][1] = tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> pan[i][j];
    
    for(int i=0;i<t;i++){
        int num, dir, move;
        cin >> num >> dir >> move; // 번호, 방향, 칸수
        // 번호가 num의 배수인 원판을 dir방향으로 move칸 회전시킨다 -> dir이 0이면 시계 방향, 1인 경우는 반시계 방향
        for(int j=1;j<=n;j++){
            if(j % num == 0){
                int howManySpin = move;
                if(dir == 1) howManySpin = m - move;
                for(int k=0;k<howManySpin;k++) spin(j);
            }
        }
        erase();
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j] == 0) continue;
            answer += pan[i][j];
        }
    }
    cout << answer << '\n';
    return 0;
}

