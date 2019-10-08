#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 1000000000

vector<pair<int,int> > vertex[20001];
int dis[20001];
int v,e,start;
void dijkstra();

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> v >> e;
	cin >> start;

	for(int i=0;i<e;i++){
		int a,b,w;
		cin >> a >> b >> w;
		vertex[a].push_back(make_pair(b,w));
	}
	dijkstra();

	return 0;
}
void dijkstra(){
	for(int i=1;i<=v;i++){
		dis[i] = INF;
	}
	dis[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

	pq.push(make_pair(0,start));

	while(!pq.empty()){
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(dis[node] < cost)
			continue;

		int len = vertex[node].size();
		for(int i=0;i<len;i++){
			int next_node = vertex[node][i].first;
			int next_cost = cost + vertex[node][i].second;

			if(dis[next_node] > next_cost){
				dis[next_node] = next_cost;
				pq.push(make_pair(next_cost,next_node));
			}
		}
	}
	for(int i=1;i<=v;i++){
		if(i == start)
			cout << 0 << endl;
		else if(dis[i] == INF)
			cout << "INF" << endl;
		else
			cout << dis[i] << endl;
	}
}
