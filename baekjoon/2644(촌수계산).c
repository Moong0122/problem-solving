#include<stdio.h>

int graph[101][101];
int check_visit[101];
int queue[101];
int front = 0, rear = 0;

void BFS(int st, int en, int size);
void Enqueue(int x);
int Dequeue();

int main(){
	int n,start,end,total,a,b;
	scanf("%d",&n); //-> 전체 사람의 수
	scanf("%d%d",&start,&end); //-> 촌수 계산에 필요한 사람
	scanf("%d",&total); //-> 반복횟수
	for(int i=1;i<=total;i++){
		scanf("%d%d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	BFS(start,end,n);

	if(check_visit[end] == 0)
		printf("-1\n");
	else
		printf("%d\n", check_visit[end]-1);
	//시작할 때 0이므로 -1을 해준다
	return 0;
}
void BFS(int st, int en, int size){
	int pop;
	Enqueue(st);
	check_visit[st] = 1;
	while(front < rear){
		pop = Dequeue();
		if(pop == en)
			break;
		for(int i=1;i<=size;i++){
			if(graph[pop][i] == 1 && check_visit[i] == 0){
				Enqueue(i);
				check_visit[i] = check_visit[pop] + 1;
			}
		}
	}
}
void Enqueue(int x){
	queue[rear] = x;
	rear++;
}
int Dequeue(){
	int tmp;
	tmp = queue[front];
	front++;
	return tmp;
}
