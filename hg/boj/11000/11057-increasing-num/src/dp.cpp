#include <bits/stdc++.h>
using namespace std;

#define MOD 10007
int dp[1001][10];//[길이][마지막수] 에 해당하는 오르막수 개수

int solve(int l, int fin) {
    if (l <= 0 or fin > 9 or fin < 0) return 0;
    if (l == 1) return 1;
    if (dp[l][fin] != -1) return dp[l][fin];
    
    int ans = 0;
    for (int ffin = fin; ffin >= 0; ffin--) {
        ans += solve(l-1, ffin);
    }
    ans %= MOD;
    return dp[l][fin] = ans;
}
int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i=0; i <=9; i++) {
        ans += solve(n, i);
    }
    ans %= MOD;
    cout << ans << '\n';
	return 0;
}

