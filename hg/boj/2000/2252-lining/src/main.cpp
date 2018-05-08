#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
int indegree[100005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    
    for (int i=1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << ' ';
        for (size_t i=0; i < edge[v].size(); i++) {
            int n = edge[v][i];
            indegree[n]--;
            if (indegree[n] == 0) {
                q.push(n);
            }
        }
    }
    cout << endl;
	return 0;
}

