#include <vector>
#include <string>
using namespace std;

int cnt, n, m;
vector<vector<int> > k,l;

void spin(){
	// 벡터로 이루어진 이차원 배열 초기화 방법!
	vector<vector<int> > tmp(m,vector<int>(m,0));
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			tmp[j][m-i-1] = k[i][j];
	k = tmp;
}	

bool solution(vector<vector<int> > key, vector<vector<int> > lock)
{
	k = key; l = lock;
	m = k.size(); n = l.size();

	// lock배열에서 빈공간 개수 파악
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(l[i][j] == 0) cnt++;

	for(int r=0;r<4;r++){
		// 회전
		for(int i=-20;i<=20;i++){
			for(int j=-20;j<=20;j++){
				int count = 0, fail = 0;
				for(int y=0;y<m;y++){
					for(int x=0;x<m;x++){
						int dy = i+y, dx = j+x;
						if(dy >= 0 && dx >= 0 && dy < n && dx < n){
							if(l[dy][dx] == 1 && k[y][x] == 1) fail = 1;
							else if(l[dy][dx] == 0 && k[y][x] == 1) count++;
						}
					}
				}
				if(count == cnt && fail == 0) return true;
			}
		}
		spin();
		//
	}
	return false;
}

// 다시 풀었을 때
#include <string>
#include <vector>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> layout(2 * key.size() + lock.size(), vector<int>(2 * key.size() + lock.size(), 0));
    vector<pair<int, int>> keyPoint;
    
    for (int i = 0 ; i < key.size() ; i++) {
        for (int j = 0 ; j < key.size(); j++) {
            if (key[i][j] == 1) {
                keyPoint.push_back({i,j});
            }
        }
    }
    
    bool answer = true;
    int cnt = 0;
    
    while (cnt++ < 4) {
        
        for (int i = 0 ; i < keyPoint.size() ; i++) {
            int y = keyPoint[i].first;
            int x = keyPoint[i].second;
            keyPoint[i].first = x;
            keyPoint[i].second = key.size() - 1 - y;
        }
        
        for (int i = 0 ; i < key.size() + lock.size() ; i++) {
            for (int j = 0 ; j < key.size() + lock.size() ; j++) {
                
                for (auto& k : keyPoint) {
                    layout[k.first + i][k.second + j] += 1;
                }
                
                for (int k = 0 ; k < lock.size() ; k++) {
                    for (int l = 0 ; l < lock.size() ; l++) {
                        layout[k + key.size()][l + key.size()] += lock[k][l];
                    }
                }
                
                answer = true;
                for (int k = key.size() ; k < key.size() + lock.size() ; k++) {
                    for (int l = key.size() ; l < key.size() + lock.size() ; l++) {
                        if (layout[k][l] > 1 || layout[k][l] == 0) {
                            answer = false;
                        }
                    }
                }
                
                if (answer) return true;
                
                for (int k = 0 ; k < layout.size() ; k++) {
                    for (int l = 0 ; l < layout.size() ; l++) {
                        layout[k][l] = 0;
                    }
                }
            }
        }
    }
    
    return false;
}

// 피드백
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void rotateKey(vector<pair<int, int>> &keyPoint, int M) {
    for (int i = 0 ; i < keyPoint.size() ; i++) {
        int y = keyPoint[i].first;
        int x = keyPoint[i].second;
        keyPoint[i].first = x;
        keyPoint[i].second = M - 1 - y;
    }
}

bool checkUnlock(vector<vector<int>> &layout, int M, int N) {
    bool answer = true;
    for (int i = M ; i < M + N ; i++) {
        for (int j = M ; j < M + N ; j++) {
            if (layout[i][j] > 1 || layout[i][j] == 0) {
                answer = false;
            }
        }
    }
    
    return answer;
}

void moveKeyAndUpdate(vector<pair<int, int>> &keyPoint, vector<vector<int>> &layout, vector<vector<int>> &lock, int y, int x, int M, int N) {
    for (auto& i : keyPoint) {
        layout[i.first + y][i.second + x] += 1;
    }
    
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            layout[i + M][j + M] += lock[i][j];
        }
    }
}

void clearLayout(vector<vector<int>> &layout) {
    for (int i = 0 ; i < layout.size() ; i++) {
        for (int j = 0 ; j < layout.size() ; j++) {
            layout[i][j] = 0;
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = (int)key.size(), N = (int)lock.size();
    vector<vector<int>> layout(2 * M + N, vector<int>(2 * N + N, 0));
    vector<pair<int, int>> keyPoint;
    
    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (key[i][j] == 1) {
                keyPoint.push_back({i,j});
            }
        }
    }
    
    int cnt = 0;
    while (cnt++ < 4) {
        
        rotateKey(keyPoint, M);
        
        for (int i = 0 ; i < M + N ; i++) {
            for (int j = 0 ; j < M + N ; j++) {
                
                moveKeyAndUpdate(keyPoint, layout, lock, i, j, M, N);
                
                if (checkUnlock(layout, M, N)) return true;
                
                clearLayout(layout);
            }
        }
    }
    
    return false;
}

// 풀이
#include <string>
#include <vector>
using namespace std;

void rotate_key(vector<vector<int>>& key) {
    // 여기 파라미터는 &을 사용했다. 회전하면서 원본값도 바껴야 하기 때문에
    const int M = (int)key.size();
    vector<vector<int>> tmp = key;

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
            key[x][M - 1 - y] = tmp[y][x];
        }
    }
}

bool check_key(vector<vector<int>> board, vector<vector<int>> key, int sx, int sy) {
    // 파라미터로 &을 사용하지 않는다!
    // 원본 board와 key값이 바뀌지 않는다 -> 그냥 이 함수에서 확인만 할 수 있다.
    // 다음에 문제 풀 때는 이렇게 풀어봐야겠다
    
    const int M = (int)key.size();
    const int BOARD_SIZE = (int)board.size();

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
            // XOR 연산 (열에서 한 개 비트만 1이면 해당 열에 대한 결과는 1이다.)
            board[y + sy][x + sx] ^= key[y][x];
        }
    }

    // lock이 있는 위치에 1이 없다면 비어있거나 겹쳐있다는 뜻이므로 false 반환
    for (int y = M - 1; y <= BOARD_SIZE - M; y++) {
        for (int x = M - 1; x <= BOARD_SIZE - M; x++) {
            if (board[y][x] != 1)
                return false;
        }
    }

    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    const int M = (int)key.size();
    const int N = (int)lock.size();
    const int BOARD_SIZE = M * 2 + N - 2;

    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

    for (int y = M - 1; y <= BOARD_SIZE - M; y++) {
        for (int x = M - 1; x <= BOARD_SIZE - M; x++) {
            board[y][x] = lock[y - M + 1][x - M + 1];
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int sy = 0; sy <= BOARD_SIZE - M; sy++) {
            for (int sx = 0; sx <= BOARD_SIZE - M; sx++) {
                if (check_key(board, key, sx, sy))
                    return true;
            }
        }

        // 3번 회전하면 완료한 것이므로 break로 나가준다.
        if (r == 3) break;
        
        rotate_key(key);
    }

    return false;
}
