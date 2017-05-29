#include <iostream>
#include <vector>
#include <queue>


using namespace std;

queue<int> Q;
vector<vector<int> > relation;
vector<int> cost;
vector<bool> visited;
int N, M;
int src, dest;
int main() {
	cin >> N; //사람 수
	cin >> src >> dest;
	cin >> M; //관계수
	
	cost.resize(N+1, 0);
	visited.resize(N+1, false);
	relation.reserve(N+1);
	
	Q.push(src);
	visited[src] = true;
	for (int i=0; i <M; i++) {
		int dad, son;
		cin >> dad >> son;
		relation[dad].push_back(son);
		relation[son].push_back(dad);
	}
	while (!Q.empty()) {
		int current = Q.front(); Q.pop();
		for (int i = 0; i < relation[current].size(); i++) {
			int next = relation[current][i];
			if (visited[next]) continue;
			cost[next] = cost[current] + 1;
			 //printf("지금은 %d, 다음은 %d, 촌수는 %d\n", current, next, cost[next]);
			visited[next] = true;
			if (next == dest) {
				cout << cost[next] << endl;
				return 0;
			}
			Q.push(next);
		}
	}
	cout << -1 << endl;
}