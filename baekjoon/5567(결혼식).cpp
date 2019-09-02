#include<iostream>
#include<queue>
using namespace std;

int graph[501][501];
int check_visit[501];

void BFS(int start, int size);
int main(){
	int n,m,a,b,total = 0;
	cin >> n;
	cin >> m;

	for(int i=1;i<=m;i++){
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	BFS(1,n);
	for(int i=1;i<=n;i++){
		if(check_visit[i] == 2 || check_visit[i] == 3)
			total++;
	}
	cout << total << endl;
	return 0;
}
void BFS(int start, int size){
	int tmp;

	queue <int> q;
	q.push(start);
	check_visit[start] = 1;

	while(!q.empty()){
		tmp = q.front();
		q.pop();

		if(check_visit[tmp] == 3)
			break;
		for(int i=1;i<=size;i++){
			if(graph[tmp][i] == 1 && check_visit[i] == 0){
				check_visit[i] = check_visit[tmp] + 1;
				q.push(i);
			}
		}
	}
}
