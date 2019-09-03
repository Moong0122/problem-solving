#include<iostream>
#include<queue>
using namespace std;

int graph[50][50];
int check_visit[50];
int cnt = 0;

void BFS(int start, int erase, int size);
int main(){
	int n,a,root,t;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a == -1)
			root = i;
		else{
			graph[a][i] = 1;
		}
	}
	cin >> t;
	BFS(root,t,n);
	cout << cnt << endl;
    return 0;
}
void BFS(int start, int erase, int size){
	int tmp;
	queue <int> q;

	if(start == erase)
		return;

	check_visit[start] = 1;
	q.push(start);

	while(!q.empty()){
		int check = false;
		tmp = q.front();
		q.pop();

		for(int i=0;i<size;i++){
			if(i == erase)
				continue;
			if(graph[tmp][i] == 1 && check_visit[i] == 0){
				check = true;
				q.push(i);
				check_visit[i] = 1;
			}
		}
		if(!check)
			cnt++;
	}
}
