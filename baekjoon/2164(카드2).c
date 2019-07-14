#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct CircularQueue{
    ElementType *key;
    int front;
    int rear;
    int qsize;
    int max_queue_size;
}CircularQueue;

CircularQueue* MakeEmpty( int max );
int IsEmpty( CircularQueue* Q );
int IsFull( CircularQueue* Q );
void Enqueue( CircularQueue* Q);
void Dequeue( CircularQueue* Q );
void DeleteQueue (CircularQueue* Q );

int main(int argc, char *argv[]){
    
    CircularQueue *S = NULL;
    int n;
    scanf("%d", &n); //이 숫자를 입력한다면 큐 배열안에는 1~n까지 숫자들이 있어야 한다
    
    S = MakeEmpty(n);
    
    while(1){
        if(S->qsize == 1)
        break;
        
        Dequeue(S);
        Enqueue(S);
    }
    printf("%d\n",S->key[S->front]);
    DeleteQueue(S);
    return 0;
}

CircularQueue* MakeEmpty( int max ){
    CircularQueue* s =(CircularQueue*)malloc(sizeof(CircularQueue));
    s->key = (ElementType *)malloc(sizeof(ElementType)*max);
    
    for(int i=0;i<max;i++){
        s->key[i] = i+1;
    }
    s->front = 0;
    s->rear = max-1;
    s->qsize = max;
    s->max_queue_size = max;
    return s;
}
void Enqueue( CircularQueue* Q ){
    Q->rear = (Q->rear+1) % Q->max_queue_size;
    Q->key[Q->rear] = Q->key[Q->front];
    Q->front = (Q->front+1) % Q->max_queue_size;
}
void Dequeue( CircularQueue* Q ){
    Q->front = (Q->front+1) % Q->max_queue_size;
    Q->qsize--;
}
void DeleteQueue (CircularQueue* Q ){
    free(Q->key);
    free(Q);
}
