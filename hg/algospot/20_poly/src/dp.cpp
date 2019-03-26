#include <bits/stdc++.h>
using namespace std;

#define MOD 10000000
typedef long long ll;
ll dp[101][101][101]; // [층수][총 놓은 블럭수][최근에 놓은 블럭수] -> 놓는 가짓 수
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        memset(dp, 0, sizeof(dp));
        for (int i=1; i <= n; i++) {
            dp[1][i][i] = 1LL;
        }
        
        for (int i=1; i <= n; i++) {
            for (int j=1; j <= n; j++) {
                for (int k=1; k <= j; k++) {
                    for (int l=1; l <= n - j; l++) {
                        dp[i][j+l][l] += 1LL * (k+l-1) * dp[i][j][k] % MOD;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i=1; i <= n; i++) {
            for (int j=1; j <= n; j++) {
                ans += dp[i][n][j];
                ans %= MOD;
            }
        }
        cout << ans << '\n';
        
    }
	return 0;
}

