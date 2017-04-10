#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

// const int INF = 987654321;
const int INF = 98765432;

int N, E;
vector<vector<P> > weight; // weight[src] = (dest, cost);

int cost[802];
bool visited[802];
void init() {
	for (int i=0; i < N+1; i++) {
		cost[i] = INF;
		visited[i] = false;
	}
}
void getsp(int src) {
	priority_queue<P, vector<P>, greater<P> > open; // (여기까지 cost, vertex No.)
	
	cost[src] = 0;
	open.push(make_pair(0, src)); //start node넣기
		
	while(!open.empty()) {
		int cur_cost = open.top().first;
		int cur_city = open.top().second;
		open.pop();
		
		if (visited[cur_city]) {
			continue;
		}

		visited[cur_city] = true;
		for (int i=0; i < weight[cur_city].size(); i++) {
			int next_city = weight[cur_city][i].first;
			int next_cost = weight[cur_city][i].second;
			if (cur_cost + next_cost < cost[next_city]) {
				cost[next_city] = cur_cost + next_cost;
				open.push(make_pair(cost[next_city], next_city));
			}
		}
	}
}
int main() {
	cin >> N >> E;
	weight.reserve(N+1);
	
	for (int i=0; i < E;i++) {
		int src, dest, cost;
		cin >> src >> dest >> cost;
		weight[src].push_back(make_pair(dest, cost));
		weight[dest].push_back(make_pair(src, cost));
	}
	
	// 1 ~> N
	int a, b;
	cin >> a >> b;
	
	init();
	getsp(1);
	int start2a = cost[a];
	int start2b = cost[b];
	
	init();
	getsp(a);
	int a2n = cost[N];
	int a2b = cost[b];
	
	init();
	getsp(b);
	int b2n = cost[N];
	int b2a = cost[a];
	
	int route1 = start2a + a2b + b2n;
	int route2 = start2b + b2a + a2n;
	
	if (route1 >= INF && route2 >= INF) {
		cout << -1 << endl;
	} else if (route1 > INF) {
		cout << route2 << endl;
	} else if (route2 > INF) {
		cout << route1 << endl;
	} else {
		cout << min(route1, route2) << endl;
	}
	
}