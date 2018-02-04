#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[101];

int get(int i) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = get(i-2) + get(i-1);
    return dp[i] = (ans % MOD);
}
int main() {
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    while(t--) {
        int n;
        cin >> n;
        cout << get(n) << '\n';
    }
	return 0;
}

