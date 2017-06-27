#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>

#define MAX 100000
using namespace std;

int main() {
	int N, K; //시작 위치, 목적지 위치
	vector<bool> visited;
	vector<int> path_len;
	vector<int> num_method;
	queue<int> q;
	cin >> N >> K;
	int no_more_queue = false;
	visited.resize(MAX+2, false);
	path_len.resize(MAX+2, 987654321);
	num_method.resize(MAX+2, 0);
	q.push(N);
	
	visited[N] = true;
	path_len[N] = 0;
	num_method[N] = 1;
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();

		
		int next_len = path_len[cur] + 1;
		int next = cur-1;
		if (next >= 0 && next <= MAX && next_len <= path_len[next]) {
			path_len[next] = next_len;
			num_method[next] += num_method[cur];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
		
		next = cur+1;
		if (next >= 0 && next <= MAX && next_len <= path_len[next]) {
			path_len[next] = next_len;
			num_method[next] += num_method[cur];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
		
		next = cur * 2;
		if (next >= 0 && next <= MAX && next_len <= path_len[next]) {
			path_len[next] = next_len;
			num_method[next] += num_method[cur];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
		
	}
	
	cout << path_len[K] << endl << num_method[K] << endl;
	
}