#include <bits/stdc++.h>
using namespace std;

double dp[101][51]; //i일 뒤 j마을에 있을 확률
vector<int> adj[51];
int main() {
    int t; cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        for (int i=0; i < 50; i++) adj[i].clear();
        //get input
        int n, d, p;
        cin >> n >> d >> p;
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                int v; cin >> v;
                if (v) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        dp[0][p] = 1.0;
        for (int i=1; i <= d; i++) { //i번째날
            for (int j=0; j < n; j++) { //j마을에 있을 확률 계산
                for (auto k : adj[j]) {
                    dp[i][j] += dp[i-1][k] / adj[k].size();
                }
            }
        }
        
        
        int T; cin >> T;
        while(T--) {
            int Q; cin >> Q;
            printf("%.9lf ", dp[d][Q]);
        }
        putchar('\n');
        
    }
	return 0;
}

