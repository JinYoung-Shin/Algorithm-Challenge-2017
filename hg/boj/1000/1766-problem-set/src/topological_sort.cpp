#include <bits/stdc++.h>
using namespace std;

int indegree[32005];
vector<int> adj[32005];

int main() {
    int n, m;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    
    for (int i=1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    while(!pq.empty()) {
        int v = pq.top(); pq.pop();
        cout << v << ' ';
        for (size_t i=0; i < adj[v].size(); i++) {
            int nx = adj[v][i];
            indegree[nx]--;
            if (indegree[nx] == 0) {
                pq.push(nx);
            }
        }
    }
	return 0;
}

