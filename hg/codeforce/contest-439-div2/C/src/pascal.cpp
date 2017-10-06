#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long ll;

int dp[5001][5001];
int bicof[5001][5001];
int facto[5001];

ll get_facto(int n) {
	if (n <= 1) {
		return 1;
	}
	if (facto[n]) return facto[n];
	ll ret = 1;
	return facto[n] = (n * get_facto(n-1)) % MOD;
}

ll pascal(int n, int r) {
	if (n==r) return 1;
	if (n==0 || r==0) return 1;
	if (bicof[n][r]) return bicof[n][r];
	return bicof[n][r] = ((ll)pascal(n-1, r) + (ll)pascal(n-1, r-1)) % MOD;
}
ll get(int a, int b) {
	if (dp[a][b]) return dp[a][b];
	ll ret = 1;
	int limit = min(a, b);
	for (int i=1; i <= limit; i++) {
		ret += (((pascal(a, i) * pascal(b, i)) % MOD) * get_facto(i)) % MOD;
		ret %= MOD;
	}
	return dp[a][b] = ret;
}
int main() {
	int a, b, c;
	dp[1][1] = 2;
	cin >> a >> b >> c;
	ll ans = 1;
	ans *= get(a,b);
	ans %= MOD;
	ans *= get(b,c);
	ans %= MOD;
	ans *= get(c,a);
	ans %= MOD;
	cout << ans << endl;
}