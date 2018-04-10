#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int indegree[1001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i < m; i++) {
        int k;
        cin >> k;
        if (k > 0) {
            int prev;
            cin >> prev;
            for (int j=1; j < k; j++) {
                int target;
                cin >> target;
                adj[prev].push_back(target);
                indegree[target]++;
                prev = target;
            }    
        }
    }
    queue<int> arr;
    for (int i=1; i <= n; i++) {
        if (indegree[i] == 0) {
            arr.push(i);
        }
    }

    vector<int> ans;
    while(!arr.empty()) {
        int cur = arr.front(); arr.pop();
        ans.push_back(cur);
        for (size_t i=0; i < adj[cur].size(); i++) {
            int adj_node = adj[cur][i];
            indegree[adj_node]--;
            if (indegree[adj_node] == 0) {
                arr.push(adj_node);
            }
        }
    }
    if (ans.size() < n) {
        cout << "0\n"; return 0;
    }
    for (int i=0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
	return 0;
}

