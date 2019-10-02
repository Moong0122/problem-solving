#include<iostream>
#include<vector>
using namespace std;

int pizza[1001][1001];
vector<pair<int,int> > row;
void pushVector(int x, int y);
int main(){
	int n,m;
	long total = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int rmax = -1;
		int rx,ry;
		for(int j=0;j<m;j++){
			cin >> pizza[i][j];
			total += pizza[i][j];
			if(pizza[i][j] > rmax){
				rmax = pizza[i][j];
				rx = i;
				ry = j;
			}
		}
		row.push_back(make_pair(rx,ry));
	}
	for(int i=0;i<m;i++){
		int cmax = -1;
		int cx,cy;
		for(int j=0;j<n;j++){
			if(pizza[j][i] > cmax){
				cmax = pizza[j][i];
				cx = j;
				cy = i;
			}
		}
		pushVector(cx,cy);
	}
	int l = row.size();
	long sum = 0;
	for(int i=0;i<l;i++){
		sum += pizza[row[i].first][row[i].second];
	}
	cout << total - sum << endl;
	return 0;
}
void pushVector(int x, int y){
	bool find = false;
	int len = row.size();
	for(int i=0;i<len;i++){
		if(row[i].first == x && row[i].second == y){
			find = true;
			break;
		}
	}
	if(find)
		return;
	else
		row.push_back(make_pair(x,y));
}
