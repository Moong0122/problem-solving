#include<iostream>
#include<vector>
using namespace std;

char cube[12][9];
char color[6] = {'o','g','y','b','r','w'};
int pos[6][2] = {{0,3},{3,0},{3,3},{3,6},{6,3},{9,3}};
int n;
void initialize();
void rotateCube(char face, char direction);
void rotateFace(int y, int x, char dir);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    //
    for(int test = 0 ; test < n ; test++){
        int num;
        cin >> num;
        // 큐브 회전
        initialize();
        for(int roN = 0 ; roN < num ; roN++){
            string str;
            cin >> str;
            rotateCube(str[0],str[1]);
        }
        //
        // 결과물 출력하기
        for(int i=11;i>=9;i--){
            for(int j=3;j<6;j++){
                cout << cube[i][j];
            }
            cout << endl;
        }
        //
    }
    //
    return 0;
}
void initialize(){
    for(int i=0;i<6;i++){
        for(int a = pos[i][0]; a < pos[i][0]+3; a++){
            for(int b = pos[i][1]; b < pos[i][1]+3; b++){
                cube[a][b] = color[i];
            }
        }
    }
}
void rotateCube(char face, char direction){
    vector<char> number;
    char tmp1, tmp2, tmp3;
    switch (face) {
        case 'U':
            if(direction == '-'){
                tmp1 = cube[0][3];
                tmp2 = cube[0][4];
                tmp3 = cube[0][5];
                
                cube[0][3] = cube[3][8];
                cube[0][4] = cube[4][8];
                cube[0][5] = cube[5][8];
                
                cube[3][8] = cube[8][5];
                cube[4][8] = cube[8][4];
                cube[5][8] = cube[8][3];
                
                cube[8][5] = cube[5][0];
                cube[8][4] = cube[4][0];
                cube[8][3] = cube[3][0];
                
                cube[5][0] = tmp1;
                cube[4][0] = tmp2;
                cube[3][0] = tmp3;
                
                rotateFace(9, 3, direction);
            }else if(direction == '+'){
                tmp1 = cube[0][3];
                tmp2 = cube[0][4];
                tmp3 = cube[0][5];
                
                cube[0][3] = cube[5][0];
                cube[0][4] = cube[4][0];
                cube[0][5] = cube[3][0];
                
                cube[5][0] = cube[8][5];
                cube[4][0] = cube[8][4];
                cube[3][0] = cube[8][3];
                
                cube[8][5] = cube[3][8];
                cube[8][4] = cube[4][8];
                cube[8][3] = cube[5][8];
                
                cube[3][8] = tmp1;
                cube[4][8] = tmp2;
                cube[5][8] = tmp3;
                
                rotateFace(9, 3, direction);
            }
            break;
        case 'D':
            if(direction == '-'){
                tmp1 = cube[2][3];
                tmp2 = cube[2][4];
                tmp3 = cube[2][5];
                
                cube[2][3] = cube[5][2];
                cube[2][4] = cube[4][2];
                cube[2][5] = cube[3][2];
                
                cube[5][2] = cube[6][5];
                cube[4][2] = cube[6][4];
                cube[3][2] = cube[6][3];
                
                cube[6][5] = cube[3][6];
                cube[6][4] = cube[4][6];
                cube[6][3] = cube[5][6];
                
                cube[3][6] = tmp1;
                cube[4][6] = tmp2;
                cube[5][6] = tmp3;
                
                rotateFace(3, 3, direction);
            }else if(direction == '+'){
                tmp1 = cube[2][3];
                tmp2 = cube[2][4];
                tmp3 = cube[2][5];
                
                cube[2][3] = cube[3][6];
                cube[2][4] = cube[4][6];
                cube[2][5] = cube[5][6];
                
                cube[3][6] = cube[6][5];
                cube[4][6] = cube[6][4];
                cube[5][6] = cube[6][3];
                
                cube[6][5] = cube[5][2];
                cube[6][4] = cube[4][2];
                cube[6][3] = cube[3][2];
                
                cube[5][2] = tmp1;
                cube[4][2] = tmp2;
                cube[3][2] = tmp3;
                
                rotateFace(3, 3, direction);
            }
            break;
        case 'F':
            if(direction == '-'){
                tmp1 = cube[5][0];
                tmp2 = cube[5][1];
                tmp3 = cube[5][2];
                
                cube[5][0] = cube[9][5];
                cube[5][1] = cube[9][4];
                cube[5][2] = cube[9][3];
                
                cube[9][5] = cube[5][6];
                cube[9][4] = cube[5][7];
                cube[9][3] = cube[5][8];
                
                cube[5][6] = cube[5][3];
                cube[5][7] = cube[5][4];
                cube[5][8] = cube[5][5];
                
                cube[5][3] = tmp1;
                cube[5][4] = tmp2;
                cube[5][5] = tmp3;
                
                rotateFace(6, 3, direction);
            }else if(direction == '+'){
                tmp1 = cube[5][0];
                tmp2 = cube[5][1];
                tmp3 = cube[5][2];
                
                cube[5][0] = cube[5][3];
                cube[5][1] = cube[5][4];
                cube[5][2] = cube[5][5];
                
                cube[5][3] = cube[5][6];
                cube[5][4] = cube[5][7];
                cube[5][5] = cube[5][8];
                
                cube[5][6] = cube[9][5];
                cube[5][7] = cube[9][4];
                cube[5][8] = cube[9][3];
                
                cube[9][5] = tmp1;
                cube[9][4] = tmp2;
                cube[9][3] = tmp3;
                
                rotateFace(6, 3, direction);
            }
            break;
        case 'B':
            if(direction == '-'){
                tmp1 = cube[3][0];
                tmp2 = cube[3][1];
                tmp3 = cube[3][2];
                
                cube[3][0] = cube[3][3];
                cube[3][1] = cube[3][4];
                cube[3][2] = cube[3][5];
                
                cube[3][3] = cube[3][6];
                cube[3][4] = cube[3][7];
                cube[3][5] = cube[3][8];
                
                cube[3][6] = cube[11][5];
                cube[3][7] = cube[11][4];
                cube[3][8] = cube[11][3];
                
                cube[11][5] = tmp1;
                cube[11][4] = tmp2;
                cube[11][3] = tmp3;
                
                rotateFace(0, 3, direction);
            }else if(direction == '+'){
                tmp1 = cube[3][0];
                tmp2 = cube[3][1];
                tmp3 = cube[3][2];
                
                cube[3][0] = cube[11][5];
                cube[3][1] = cube[11][4];
                cube[3][2] = cube[11][3];
                
                cube[11][5] = cube[3][6];
                cube[11][4] = cube[3][7];
                cube[11][3] = cube[3][8];
                
                cube[3][6] = cube[3][3];
                cube[3][7] = cube[3][4];
                cube[3][8] = cube[3][5];
                
                cube[3][3] = tmp1;
                cube[3][4] = tmp2;
                cube[3][5] = tmp3;
                
                rotateFace(0, 3, direction);
            }
            break;
        case 'L':
            if(direction == '-'){
                tmp1 = cube[0][3];
                tmp2 = cube[1][3];
                tmp3 = cube[2][3];
                
                cube[0][3] = cube[9][3];
                cube[1][3] = cube[10][3];
                cube[2][3] = cube[11][3];
                
                cube[9][3] = cube[6][3];
                cube[10][3] = cube[7][3];
                cube[11][3] = cube[8][3];
                
                cube[6][3] = cube[3][3];
                cube[7][3] = cube[4][3];
                cube[8][3] = cube[5][3];
                
                cube[3][3] = tmp1;
                cube[4][3] = tmp2;
                cube[5][3] = tmp3;
                
                rotateFace(3, 0, direction);
            }else if(direction == '+'){
                tmp1 = cube[0][3];
                tmp2 = cube[1][3];
                tmp3 = cube[2][3];
                
                cube[0][3] = cube[3][3];
                cube[1][3] = cube[4][3];
                cube[2][3] = cube[5][3];
                
                cube[3][3] = cube[6][3];
                cube[4][3] = cube[7][3];
                cube[5][3] = cube[8][3];
                
                cube[6][3] = cube[9][3];
                cube[7][3] = cube[10][3];
                cube[8][3] = cube[11][3];
                
                cube[9][3] = tmp1;
                cube[10][3] = tmp2;
                cube[11][3] = tmp3;
                
                rotateFace(3, 0, direction);
            }
            break;
        case 'R':
            if(direction == '-'){
                tmp1 = cube[0][5];
                tmp2 = cube[1][5];
                tmp3 = cube[2][5];
                
                cube[0][5] = cube[3][5];
                cube[1][5] = cube[4][5];
                cube[2][5] = cube[5][5];
                
                cube[3][5] = cube[6][5];
                cube[4][5] = cube[7][5];
                cube[5][5] = cube[8][5];
                
                cube[6][5] = cube[9][5];
                cube[7][5] = cube[10][5];
                cube[8][5] = cube[11][5];
                
                cube[9][5] = tmp1;
                cube[10][5] = tmp2;
                cube[11][5] = tmp3;
                
                rotateFace(3, 6, direction);
            }else if(direction == '+'){
                tmp1 = cube[0][5];
                tmp2 = cube[1][5];
                tmp3 = cube[2][5];
                
                cube[0][5] = cube[9][5];
                cube[1][5] = cube[10][5];
                cube[2][5] = cube[11][5];
                
                cube[9][5] = cube[6][5];
                cube[10][5] = cube[7][5];
                cube[11][5] = cube[8][5];
                
                cube[6][5] = cube[3][5];
                cube[7][5] = cube[4][5];
                cube[8][5] = cube[5][5];
                
                cube[3][5] = tmp1;
                cube[4][5] = tmp2;
                cube[5][5] = tmp3;
                
                rotateFace(3, 6, direction);
            }
            break;
    }
    number.clear();
}
void rotateFace(int y, int x, char dir){
    vector<int> number;
    
    if(dir == '-'){
        for(int i=y;i<y+3;i++){
            for(int j=x;j<x+3;j++){
                number.push_back(cube[i][j]);
            }
        }
        int cnt = 0;
        for(int i=x+2;i>=x;i--){
            for(int j=y;j<y+3;j++){
                cube[j][i] = number[cnt];
                cnt++;
            }
        }
    }else if(dir == '+'){
        for(int i=y;i<y+3;i++){
            for(int j=x;j<x+3;j++){
                number.push_back(cube[i][j]);
            }
        }
        int cnt = 0;
        for(int i=x;i<x+3;i++){
            for(int j=y+2;j>=y;j--){
                cube[j][i] = number[cnt];
                cnt++;
            }
        }
    }
    number.clear();
}
