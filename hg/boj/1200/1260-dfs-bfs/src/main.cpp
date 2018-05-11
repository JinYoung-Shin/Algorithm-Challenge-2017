#include <bits/stdc++.h>
using namespace std;

bool chk[1005];
vector<int> adj[1005];
set<pair<int, int> > ss;

void dfs(int x) {
    cout << x << ' ';
    for (size_t i=0; i < adj[x].size(); i++) {
        int n = adj[x][i];
        if (chk[n] == false) {
            chk[n] = true;
            dfs(n);
        }
    }
}
int main() {
    int n, m, sv;
    cin >> n >> m >> sv;
    for (int i=0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        if (ss.insert(make_pair(a, b)).second == true) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    for (int i=1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    chk[sv] = true;
    dfs(sv);
    
    memset(chk, 0, sizeof(chk));
    
    queue<int> q;
    
    cout << '\n';
    chk[sv] = true;
    q.push(sv);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << ' ';
        for (size_t i=0; i < adj[v].size(); i++) {
            int nx = adj[v][i];
            if (chk[nx] == false) {
                chk[nx] = true;
                q.push(nx);
            }
        }
    }
	return 0;
}

