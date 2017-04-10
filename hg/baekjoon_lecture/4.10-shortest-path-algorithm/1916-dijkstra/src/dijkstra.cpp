#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

const int INF = 987654321;

using namespace std;


int n; //number of city
int m; //number of bus
vector<vector<pair<int, int> > > adj; //인접리스트. adj[i] = (first, second) i번 도시에서 first도시로 가는데 second 코스트가 든다.
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > open; //open에 (cost, 도시명)으로 들어간다.
vector<int> cost_table;
int main() {
	int src, dest;
	cin >> n;
	cin >> m;
	adj.reserve(n+1);
	// visited.resize(n+1, false);
	visited.reserve(n+1);
	cost_table.reserve(n+1);
	for(int i=1; i<=n;i++) {
		cost_table[i] = INF;
		visited[i] = false;
	}
	
	for (int i=0; i<m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(to, cost));
	}
	cin >> src >> dest;
	
	open.push(make_pair(0, src));
	
	while(!open.empty()) {
		int cur_cost = open.top().first; //현재 도시까지 오는데 걸린 코스트
		int city = open.top().second; //현재 도시 번호
		open.pop();
		if (visited[city] == true) {
			continue;
		} 
		visited[city] = true;
		// printf("방문 노드 - %d (cost: %d) \n", city, cur_cost);
		if (city == dest) {
			cout << cur_cost << endl;
			break;
		}
		
		for (int i=0; i < adj[city].size(); i++) {
			int dest_city = adj[city][i].first;
			int final_cost = adj[city][i].second;
			// printf("방문 할 노드 - %d (cost: %d) | 그래서 토탈 %d < %d인가?\n", dest_city, final_cost, cur_cost + final_cost, cost_table[dest_city]);
			// if (visited[dest_city] == false && cur_cost + final_cost < cost_table[dest_city]) {
			if (cur_cost + final_cost < cost_table[dest_city]) {
				// visited[dest_city] = true;
				cost_table[dest_city] = cur_cost + final_cost;
				open.push(make_pair(cost_table[dest_city], dest_city));
				// printf("큐에 쳐넣음 - %d (cost: %d)\n", dest_city, cost_table[dest_city]);
			}
		}
	}
}