#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CircularQueue{
	int *key;
	int front;
	int rear;
	int qsize;
	int max_queue_size;
}CircularQueue;

CircularQueue* MakeQueue(int max);
void moveLeft(CircularQueue *Q);
void moveRight(CircularQueue *Q);
void Deqeueue(CircularQueue *Q);
void DeleteQueue(CircularQueue *Q);

int *arr;
int main(){
	CircularQueue *S = NULL;
	int n,m;

	scanf("%d%d",&n,&m);
	arr = (int*)malloc(sizeof(int)*m);
	S = MakeQueue(n);

	for(int i=0;i<m;i++){
		scanf("%d",&arr[i]);
	} //뽑아내야 할 수의 위치를 확인했다

	free(arr);
	DeleteQueue(S);
	return 0;
}
CircularQueue* MakeQueue(int max){
	CircularQueue* q;
	q = (CircularQueue*)malloc(sizeof(struct CircularQueue));
	q->key = (int*)malloc(sizeof(int)*max);
	for(int i=0;i<max;i++){
		q->key[i] = i;
	}
	q->front = 0;
	q->rear = max-1;
	q->qsize = max;
	q->max_queue_size = max;

	return q;
}
void moveLeft(CircularQueue *Q){
	if(Q->front-1 < 0)
		
}
void moveRight(CircularQueue *Q){
	Q->rear = (Q->rear+1) % Q->max_queue_size;
	Q->key[Q->rear] = Q->key[Q->front];
	Q->front = (Q->front+1) % Q->max_queue_size;
}
void Deqeueue(CircularQueue *Q){
	Q->front = (Q->front+1) % Q->max_queue_size;
	Q->qsize--;
}
void DeleteQueue(CircularQueue *Q){
	free(Q->key);
	free(Q);
}