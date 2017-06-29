#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cost[10][10];
bool visited[10];
int arr[10];
int min_cost;
void dfs(int num) {
	if (num == N) {
		int cur_cost = 0;
		for (int i=0; i < N - 1; i++) {
			int src = arr[i];
			int dest = arr[i+1];
			int addition = cost[src][dest];
			if (addition == 0) return;
			cur_cost += addition;
			// cout << arr[i] << " ";
		}
		int addition = cost[arr[N-1]][arr[0]];
		if (addition == 0) return;
		cur_cost += addition;
		min_cost = min(min_cost, cur_cost);
		// cout << endl;
		return;
	}
	
	for (int i=0; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[num] = i;
			dfs(num+1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N;
	min_cost = 987654321;
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	dfs(0);
	cout << min_cost << endl;
}