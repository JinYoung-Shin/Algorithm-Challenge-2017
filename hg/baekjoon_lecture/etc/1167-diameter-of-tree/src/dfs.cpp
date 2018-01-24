#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> adj[100001]; //adj[src][dst] = weight;
int len[100001];
void dfs(int pos) {
    for (auto& it : adj[pos]) {
        int dst = it.first;
        int weight = it.second;
        if (len[dst] == -1) {
            len[dst] = len[pos] + weight;
            dfs(dst);
        }
    }
}
int main() {
    cin >> n;
    for (int i=1; i <= n; i++) {
        int s, d, w;
        scanf("%d", &s);
        while(true) {
            scanf("%d", &d);
            if (d == -1) break;
            scanf("%d", &w);
            adj[s][d] = w;
        }
    }
    
    memset(len, -1, sizeof(int) * (n+1));
    len[1] = 0;
    dfs(1);
    int tmp = 1;
    int val = len[1];
    for (int i=2; i <= n; i++) {
        if (len[i] > val) {
            val = len[i];
            tmp = i;
        }
    }
    int u = tmp;
    memset(len, -1, sizeof(int) * (n+1));
    len[u] = 0;
    val = 0;
    // int v = u;
    
    dfs(u);
    for (int i=1; i<= n; i++) {
        if (len[i] > val) {
            val = len[i];
            // v = i;
        }
    }
    cout << val << '\n';
	return 0;
}

