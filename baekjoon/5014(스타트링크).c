#include<stdio.h>

int check_visit[1000001];
int queue[1000001];
int front = 0, rear = 0;

void Enqueue(int num);
int Dequeue();
void BFS(int total, int start, int end, int up, int down);

int main(){
	int f,s,g,u,d;
	scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
	/*
	f - total 
	s - now location
	g - target
	u - up
	dowm - down
	*/
	BFS(f,s,g,u,d);
	if(check_visit[g] == 0)
		printf("use the stairs\n");
	else
		printf("%d\n", check_visit[g]-1);
	//시작점이 0으로 시작하므로 -1을 해준다
	return 0;
}
void BFS(int total,int start, int end, int up, int down){
	int temp;
	Enqueue(start);
	check_visit[start] = 1;

	while(front < rear){
		temp = Dequeue();
		if(temp == end)
			break;
		if(temp-down>0 && check_visit[temp-down] == 0){
			Enqueue(temp-down);
			check_visit[temp-down] = check_visit[temp] + 1;
		}
		if(temp+up <= total && check_visit[temp+up] == 0){
			Enqueue(temp+up);
			check_visit[temp+up] = check_visit[temp] + 1;
		}
	}
}
void Enqueue(int num){
	queue[rear] = num;
	rear++;
}
int Dequeue(){
	int tmp;
	tmp = queue[front];
	front++;
	return tmp;
}