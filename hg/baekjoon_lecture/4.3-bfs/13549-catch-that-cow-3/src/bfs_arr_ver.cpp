#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int me, cow;

vector<vector<int> > delta;
queue<int> open;
// vector<int> dist;

int main() {
	int temp;
	scanf("%d %d\n", &me, &cow);
	
	delta = vector<vector<int> >(me > cow ? (me+2) : (cow+2));
	
	
	//delta[i] => 현재 위치가 i일 때 갈 수 있는 좌표의 집합.
	
	for (int i = 0; i < delta.size(); i++) {
		if (i - 1 >= 0) {
			delta[i].push_back(i-1);
			temp = i - 1;
			temp <<= 1;
			while (temp != 0 && temp < delta.size()) {
				delta[i].push_back(temp);
				temp <<= 1;
			}
		}
		
		if (i + 1 <= delta.size()) {
			delta[i].push_back(i+1);
			temp = i + 1;
			temp <<= 1;
			while (temp < delta.size()) {
				delta[i].push_back(temp);
				temp <<= 1;
			}
		}
	}
	
	vector<int> dist(delta.size(), -1);
	//dist[i] => i 좌표까지 갈 때 드는 cost
	
	//시작 값 추가.
	open.push(me);
	dist[me] = 0;
	temp = me << 1;
	
	while (temp != 0 && temp < delta.size()) {
		dist[temp] = 0;
		open.push(temp);
		temp <<= 1;
	}
	
	while(!open.empty()) {
		int here = open.front();
		open.pop();
		for (int i=0; i < delta[here].size(); i++) {
			int there = delta[here][i];
			if (dist[there] == -1) {
				dist[there] = dist[here] + 1;
				open.push(there);
			}
		}
	}
	// cout << "answer : ";
	cout << dist[cow] << endl;
	
	// for(int i=0; i < delta.size() ;i++) {
	// 	if (dist[i] == 0) {
	// 		cout << i << endl;
	// 	}
	// }
}