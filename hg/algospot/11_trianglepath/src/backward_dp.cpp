#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tri[101][101];
ll dp[101][101]; // (0,0) ~ (i, j) 까지 합 중 최대값 - backward 방식
ll get(int x, int y) {
    if (x == 0) return tri[0][0]; // 기저사례
    if (dp[x][y] != -1) return dp[x][y];
    if (y != 0)
        return dp[x][y] = tri[x][y] + max(get(x-1, y), get(x-1, y-1));
    else
        return dp[x][y] = tri[x][y] + get(x-1, y);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0; i < n; i++) {
            for (int j=0; j <= i; j++) {
                cin >> tri[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        for (int i=0; i < n; i++) {
            ans = max(ans, get(n-1, i));
        }

        cout << ans << endl;
    }
	return 0;
}

