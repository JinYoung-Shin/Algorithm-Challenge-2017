#include <iostream>
#include <vector>
#include <queue>

#define NUM_VERTEX 20002
#define INF 987654321
#define mk make_pair
using namespace std;

typedef pair<int, int> P;
int dist[NUM_VERTEX];
bool visited[NUM_VERTEX];
vector<vector<P> > adj;
priority_queue<P, vector<P>, greater<P> > open;
int V, E, K; // num of vertex , num of edge, starting vertex number
int main() {
	cin >> V >> E >> K;
	adj.reserve(V+1);
	
	//set the initial point
	open.push(mk(0, K));
	for (int i=0; i <= V;i++) {
		dist[i] = INF;
	}
	dist[K] = 0;
	for (int i=0; i < E;i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back(mk(to, cost));
	}
	
	while(!open.empty()) {
		int cur_cost = open.top().first;
		int cur_city = open.top().second;
		open.pop();
		
		if (visited[cur_city] == true) {
			continue;
		}
		visited[cur_city] = true;
		for(int i=0; i < adj[cur_city].size(); i++) {
			int next_city = adj[cur_city][i].first;
			int next_cost = adj[cur_city][i].second;
			if (cur_cost + next_cost < dist[next_city]) {
				dist[next_city] = cur_cost + next_cost;
				open.push(mk(dist[next_city], next_city));
			}
		}
	}
	
	for (int i=1; i<= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		} else {
			cout << dist[i] << endl;
		}
	}
	
	
}