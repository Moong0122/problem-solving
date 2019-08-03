#include<stdio.h>
#define Max 100001

void Enqueue(int num);
int Dequeue(int num);
void BFS(int start, int end);

int check_visit[Max];
int queue[Max];
int front = 0, rear = 0;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	BFS(n,k);
	printf("%d\n", check_visit[k]-1);
	return 0;
}
void Enqueue(int num){
	queue[rear] = num;
	rear++;
}
int Dequeue(int num){
	int tmp = queue[front];
	front++;
	return tmp;
}
void BFS(int start, int end){
	int temp;
	Enqueue(start);
	check_visit[start] = 1;

	while(front<rear){
		temp = Dequeue(1);
		if(temp == end)
			break;
		if(temp-1 >= 0 && check_visit[temp-1] == 0){
			Enqueue(temp-1);
			check_visit[temp-1] = check_visit[temp] + 1;
		}if(temp+1 <= Max && check_visit[temp+1] == 0){
			Enqueue(temp+1);
			check_visit[temp+1] = check_visit[temp] + 1;
		}if(temp*2 <= Max && check_visit[temp*2] == 0){
			Enqueue(temp*2);
			check_visit[temp*2] = check_visit[temp] + 1;
		}
	}
}
