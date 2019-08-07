#include<stdio.h>
#include<string.h>

int graph[101][101];
int check_visit[101];
int answer[101];
int queue[101];
int front = 0,rear = 0, sum = 0;

int Dequeue();
void Enqueue(int num);
void BFS(int start, int size);
void makeclear();

int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for(int i=1;i<=n;i++){ 
		BFS(i,n);
		for(int j=1;j<=n;j++){
			sum += check_visit[j];
		}
		answer[i] = sum;
		makeclear();
	}
	int min = answer[1];
	for(int i=2;i<=n;i++){
		if(answer[i] < min)
			min = answer[i];
	}
	for(int i=1;i<=n;i++){
		if(answer[i] == min){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
void makeclear(){
	front = 0;
	rear = 0;
	sum = 0;
	memset(check_visit,0,sizeof(check_visit));
}
int Dequeue(){
	int tmp;
	tmp = queue[front];
	front++;
	return tmp;
}
void Enqueue(int num){
	queue[rear] = num;
	rear++;
}
void BFS(int start, int size){
	int temp;
	Enqueue(start);
	check_visit[start] = 1;
	while(front < rear){
		temp = Dequeue();
		for(int i=1;i<=size;i++){
			if(graph[temp][i] == 1 && check_visit[i] == 0){
				Enqueue(i);
				check_visit[i] = check_visit[temp] + 1;
			}
		}
	}
}
