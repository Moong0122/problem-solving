#include<stdio.h>
#include<string.h>

int queue[20001];
int front = 10000, rear = 9999, size = 0;

void push_front(int num);
void push_back(int num);
int pop_front();
int pop_back();
int empty();
int first();
int back();

int main(){
    int n,num, ans;
    char order[20];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",order);
        if(strcmp(order,"push_back") == 0){
            scanf("%d",&num);
            push_back(num);
        }
        else if(strcmp(order,"push_front") == 0){
            scanf("%d",&num);
            push_front(num);
        }
        else if(strcmp(order,"pop_back") == 0){
            printf("%d\n", pop_back());
        }
        else if(strcmp(order,"pop_front") == 0){
            printf("%d\n", pop_front());
        }
        else if(strcmp(order,"size") == 0){
            printf("%d\n",size);
        }
        else if(strcmp(order,"empty") == 0){
            printf("%d\n", empty());
        }
        else if(strcmp(order,"front") == 0){
            printf("%d\n", first());
        }
        else if(strcmp(order,"back") == 0){
            printf("%d\n", back());
        }
        order[0] = '\0';
    }
    return 0;
}
void push_front(int num){
    front--;
    queue[front] = num;
    size++;
}
void push_back(int num){
    rear++;
    queue[rear] = num;
    size++;
}
int pop_front(){
    int tmp;
    if(size == 0)
        return -1;
    tmp = queue[front];
    front++;
    size--;
    return tmp;
}
int pop_back(){
    int tmp;
    if(size == 0)
        return -1;
    tmp = queue[rear];
    rear--;
    size--;
    return tmp;
}
int empty(){
    if(size == 0)
        return 1;
    return 0;
}
int first(){
    if(size == 0)
        return -1;
    return queue[front];
}
int back(){
    if(size == 0)
        return -1;
    return queue[rear];
}
