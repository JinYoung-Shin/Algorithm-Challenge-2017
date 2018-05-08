#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

int dp[10][101][10]; //[왼쪽끝수][길이][오른쪽끝수] 만족하는 계단수 개수

int solve(int l, int sz, int r) {
    if (l <= 0 or l > 9 or r < 0 or r > 9 or sz <= 0) return 0;
    if (dp[l][sz][r] != -1) return dp[l][sz][r];
    if (sz == 1) {
        if (l == r) return 1;
        else return 0;
    } else if (sz > 1) {
        int val = 0;
        val += solve(l, sz-1, r+1);
        val %= MOD;
        val += solve(l, sz-1, r-1);
        val %= MOD;
        return dp[l][sz][r] = val;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int l=1; l <= 9; l++) {
        for (int r=0; r<=9; r++) {
            ans += solve(l, n, r);
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    
	return 0;
}

