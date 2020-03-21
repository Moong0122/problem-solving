#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool check[201][201][201];
vector<int> result;
int aSize, bSize, cSize;
struct bottle {
    int a,b,c;
};
vector<int> v;
void bfs(){
    
    queue<bottle> q;
    q.push({0,0,cSize});
    check[0][0][cSize] = true;
    result.push_back(cSize);
    
    while(!q.empty()){
        int aa = q.front().a;
        int bb = q.front().b;
        int cc = q.front().c;
        q.pop();
        
        if(aa == 0) v.push_back(cc);
            
        if(cc > 0){ // a가 0이 되지 않는다
            // c에서 a에 부어준다
            if(aa + cc > aSize){
                if(!check[aSize][bb][aa+cc-aSize]){
                    q.push({aSize,bb,aa+cc-aSize});
                    check[aSize][bb][aa+cc-aSize] = true;
                }
            }else{
                if(!check[aa+cc][bb][0]){
                    q.push({aa+cc,bb,0});
                    check[aa+cc][bb][0] = true;
                }
            }
            // c에서 b에 부어준다
            if(bb + cc > bSize){
                if(!check[aa][bSize][bb+cc-bSize]){
                    q.push({aa,bSize,bb+cc-bSize});
                    check[aa][bSize][bb+cc-bSize] = true;
                }
            }else{
                if(!check[aa][bb+cc][0]){
                    q.push({aa,bb+cc,0});
                    check[aa][bb+cc][0] = true;
                }
            }
        }
        if(aa > 0){
            // a에서 c에
            if(aa + cc > cSize){
                if(!check[aa+cc-cSize][bb][cSize]){
                    q.push({aa+cc-cSize,bb,cSize});
                    check[aa+cc-cSize][bb][cSize] = true;
                }
            }else{
                if(!check[0][bb][aa+cc]){
                    q.push({0,bb,aa+cc});
                    check[0][bb][aa+cc] = true;
                }
            }
            // a에서 b에
            if(aa + bb > bSize){
                if(!check[aa+bb-bSize][bSize][cc]){
                    q.push({aa+bb-bSize,bSize,cc});
                    check[aa+bb-bSize][bSize][cc] = true;
                }
            }else{
                if(!check[0][aa+bb][cc]){
                    q.push({0,aa+bb,cc});
                    check[0][aa+bb][cc] = true;
                }
            }
        }
        if(bb > 0){
            // b에서 a에
            if(bb+aa > aSize){
                if(!check[aSize][aa+bb-aSize][cc]){
                    q.push({aSize,aa+bb-aSize,cc});
                    check[aSize][aa+bb-aSize][cc] = true;
                }
            }else{
                if(!check[aa+bb][0][cc]){
                    q.push({aa+bb,0,cc});
                    check[aa+bb][0][cc] = true;
                }
            }
            // b에서 c에
            if(bb+cc > cSize){
                if(!check[aa][bb+cc-cSize][cSize]){
                    q.push({aa,bb+cc-cSize,cSize});
                    check[aa][bb+cc-cSize][cSize] = true;
                }
            }else{
                if(!check[aa][0][bb+cc]){
                    q.push({aa,0,bb+cc});
                    check[aa][0][bb+cc] = true;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> aSize >> bSize >> cSize;
    bfs();
    sort(v.begin(), v.end());
    for(auto it : v) cout << it << " ";
    cout << '\n';
    return 0;
}
