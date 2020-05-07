#include<string>
#include<vector>
#include<iostream>
using namespace std;

int block[101][101][2];
int N;

int insert(int x, int y, int type){
    // 기둥
    if(type == 0){
        // 기둥이 바닥 위에 있거나
        if(y == 0){
            return 1;
        }
        // 보의 한쪽 끝 부분 위에 있거나
        else if((x-1 >= 0 && block[x-1][y][1] == 1) || block[x][y][1] == 1)
        {
            return 1;
        }
        // 또는 다른 기둥 위에 있어야 한다
        else if(y-1 >= 0 && block[x][y-1][0] == 1){
            return 1;
        }
        return 0;
    }
    // 보
    else
    {   // 보는 한쪽 끝이 기둥 위에 있거나
        if((y-1 >= 0 && block[x][y-1][0] == 1) || (x+1 <= N && y-1 >= 0 && block[x+1][y-1][0] == 1))
        {
            return 1;
        }
        // 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야 한다
        else if(x-1 >= 0 && x+1 <= N && block[x-1][y][1] == 1 && block[x+1][y][1] == 1)
        {
            return 1;
        }
        return 0;
    }
}
int erase()
{
    for(int i = 0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            for(int k=0;k<2;k++)
            {   // 어떻게 erase() 함수에서는 구조물이 조건을 만족하는지 확인할 수 있을까?
                // 먼저 설치된 구조물을
                if(block[i][j][k] == 1)
                {   // 삭제해본다
                    block[i][j][k] = 0;
                    // 그리고 insert조건을 만족하는지 확인해서
                    // 만약 만족하지 못한다면 -> 설치할 수 없는 구조물
                    if(insert(i, j, k) == 0)
                    {   // 다시 원상복구 해주고 거짓을 return 해준다
                        block[i][j][k] = 1;
                        return 0;
                    }
                    // 여기도 다시 원상복구 코드를 작성해준다
                    block[i][j][k] = 1;
                }
            }
        }
    }
    return 1;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
    vector<vector<int>> answer;
    N = n;
    
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        // 기둥
        if(build_frame[i][2] == 0)
        {
            // 설치
            if(build_frame[i][3] == 1)
            {   // 성공
                if(insert(x, y, 0) == 1)
                {
                    block[x][y][0] = 1;
                }
            }
            // 삭제
            else
            {
                // 먼저 삭제를 해주고 erase() 함수를 통해 지금 구조물이 조건을 만족하는지 확인해준다
                block[x][y][0] = 0;
                // 실패 -> 지금 구조물이 조건을 만족하지 않는다는 뜻이므로 다시 1로 바꿔서 설치해준다
                if(erase() == 0)
                {
                    block[x][y][0] = 1;
                }
            }
        }
        // 보
        else if(build_frame[i][2] == 1)
        {   // 설치
            if(build_frame[i][3] == 1)
            {   // 성공
                if(insert(x,y,1) == 1)
                {
                    block[x][y][1] = 1;
                }
            }
            // 삭제
            else
            {
                block[x][y][1] = 0;
                if(erase() == 0)
                {
                    block[x][y][1] =  1;
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(block[i][j][k] == 1)
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    tmp.push_back(k);
                    answer.push_back(tmp);
                }
            }
        }
    }
    return answer;
}

/*
 다시
 #include<string>
 #include<vector>
 using namespace std;

 int check[101][101][2];
 int N;
 int install(int x, int y, int what){
     // 기둥
     if(what == 0)
     {   // 바닥 위에 있거나
         if(y == 0) return 1;
         // 다른 기둥 위에 서 있거나
         if(y-1 >= 0 && check[x][y-1][0] == 1) return 1;
         // 보의 한쪽 끝 부분 위에 서 있다면
         if(x-1 >= 0 && check[x-1][y][1] == 1) return 1;
         if(check[x][y][1] == 1) return 1;
     }
     // 보
     else
     {   // 보 한쪽 끝 부분이 기둥 위에 있거나
         if(y-1 >= 0 && check[x][y-1][0] == 1) return 1;
         if((x+1 <= N && y-1>=0) && check[x+1][y-1][0] == 1) return 1;
         // 양쪽 끝 부분이 다른 보와 동시에 연결되어 있다면 -> 양쪽 끝 부분에 보가 존재한다면
         if((x-1 >= 0 && check[x-1][y][1] == 1) && (x+1 <= N && check[x+1][y][1] == 1)) return 1;
     }
     return 0;
 }
 int erase(){
     for(int i = 0 ; i<=N;i++){
         for(int j=0;j<=N;j++){
             for(int k=0;k<2;k++){
                 if(check[i][j][k] == 1){
                     check[i][j][k] = 0;
                     if(install(i, j, k) == 0){
                         check[i][j][k] = 1;
                         return 0;
                     }
                     check[i][j][k] = 1;
                 }
             }
         }
     }
     return 1;
 }
 vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
     vector<vector<int>> answer;
     N = n;
     int len = (int)build_frame.size();
     for(int i = 0 ; i < len ; i++){
         int x = build_frame[i][0];
         int y = build_frame[i][1];
         // 기둥
         if(build_frame[i][2] == 0)
         {   // 삭제
             if(build_frame[i][3] == 0)
             {
                 check[x][y][0] = 0;
                 if(erase() == 0)
                 {
                     check[x][y][0] = 1;
                 }
             }
             // 설치
             else
             {
                 if(install(x,y,0)){
                     check[x][y][0] = 1;
                 }
             }
         }
         // 보
         else
         {   // 삭제
             if(build_frame[i][3] == 0)
             {
                 check[x][y][1] = 0;
                 if(erase() == 0)
                 {
                     check[x][y][1] = 1;
                 }
             }
             // 설치
             else
             {
                 if(install(x, y, 1)){
                     check[x][y][1] = 1;
                 }
             }
         }
     }
     for(int i=0;i<=n;i++){
         for(int j=0;j<=n;j++){
             for(int k=0;k<2;k++){
                 if(check[i][j][k] == 1){
                     vector<int> tmp;
                     tmp.push_back(i);
                     tmp.push_back(j);
                     tmp.push_back(k);
                     answer.push_back(tmp);
                 }
             }
         }
     }
     return answer;
 }
 */
