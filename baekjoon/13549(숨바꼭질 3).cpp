#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int check_visit[100001];
int Q[100001];
int front = 0, rear = 0;
void BFS(int start, int target);
void Enqueue(int num);
int Dequeue();

int main(){
	int n,k;
	cin >> n >> k;
	BFS(n,k);
	cout << check_visit[k]-1 << endl;
	return 0;
}
void BFS(int start, int target){
	int pop;
	check_visit[start] = 1;
	Enqueue(start);

	while(front < rear){
		pop = Dequeue();
		if(pop == target)
			return;
		if(pop*2 <= 100000){
			if(check_visit[pop*2] == 0){
			Enqueue(pop*2);
			check_visit[pop*2] = check_visit[pop];
			}
		}
		if(pop - 1 >= 0){
			if(check_visit[pop-1] == 0){
			Enqueue(pop-1);
			check_visit[pop-1] = check_visit[pop] + 1;
			}
		}
		if(pop + 1 <= 100000){
			if(check_visit[pop+1] == 0){
			Enqueue(pop+1);
			check_visit[pop+1] = check_visit[pop] + 1;
			}
		}
	}
}
void Enqueue(int num){
	Q[rear] = num;
	rear++;
}
int Dequeue(){
	int tmp;
	tmp = Q[front];
	front++;
	return tmp;
}