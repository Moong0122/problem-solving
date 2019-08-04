#include<stdio.h>

int graph[1001][1001];
int check_visit[1001];
int queue[1001];
void BFS(int start, int size, int count);
void Enqueue(int num);
int Dequeue();

int front = 0, rear = 0;
int main(){
	int n,m,cnt = 1;
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for(int i=1;i<=n;i++){
		if(check_visit[i] != 0)
			continue;
		else{
			BFS(i,n,cnt);
			cnt++;
		}
	}
	printf("%d\n", cnt-1);
}
void BFS(int start, int size, int count){
	int tmp;
	Enqueue(start);
	while(front<rear){
		tmp = Dequeue();
		check_visit[tmp] = count;
		for(int i=1;i<=size;i++){
			if(graph[tmp][i] == 1 && check_visit[i] == 0){
				Enqueue(i);
			}
		}
	}
}
void Enqueue(int num){
	queue[rear] = num;
	rear++;
}
int Dequeue(){
	int temp;
	temp = queue[front];
	front++;
	return temp;
}