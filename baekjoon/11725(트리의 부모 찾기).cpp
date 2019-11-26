#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int answer[100001];
bool check[100001];
int n;
void dfs(int start);
vector<int> graph[100001];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	answer[1] = 0;
	check[1] = true;
	q.push(1);

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int j:graph[tmp]){
			if(!check[j]){
				check[j] = true;
				answer[j] = tmp;
				q.push(j);
			}
		}
	}
	for(int i=2;i<=n;i++){
		cout << answer[i] << "\n";
	}
	return 0;
}
