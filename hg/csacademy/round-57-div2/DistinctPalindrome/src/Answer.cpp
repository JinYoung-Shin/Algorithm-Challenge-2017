#include <iostream>
#include <cstring>

using namespace std;

constexpr int kMod = 1e9 + 7, kMaxN = 1e3+5, kSigma = 26;

int dp[kMaxN][kMaxN][kSigma];
char foo[kMaxN];

void Compute(const int l, const int r, const int sigma) {
    if (l == r and foo[l] == sigma + 'a') {
        dp[l][r][sigma] = 1;
    } else if (foo[l] != sigma + 'a' or foo[r] != sigma + 'a') {
        dp[l][r][sigma] = dp[l + 1][r][sigma] + dp[l][r - 1][sigma];
        dp[l][r][sigma] %= kMod;
        dp[l][r][sigma] += kMod - dp[l + 1][r - 1][sigma];
        dp[l][r][sigma] %= kMod;
    } else if (foo[l] == sigma + 'a' and foo[r] == sigma + 'a') {
        dp[l][r][sigma] = 2;
        for (int alpha = 0; alpha < kSigma; alpha += 1) {
            dp[l][r][sigma] += dp[l + 1][r - 1][alpha];
            dp[l][r][sigma] %= kMod;
        }
    }   
}

int main() {
    cin >> (foo + 1);
    int n = strlen(foo + 1);
    
    for (int l = n; l > 0; l -= 1) {
        for (int r = l; r <= n; r += 1) {
            for (int sigma = 0; sigma < kSigma; sigma += 1) {
                Compute(l, r, sigma);
            }
        }
    }
    
    int ans = 0;
    for (int alpha = 0; alpha < kSigma; alpha += 1) {
        ans += dp[1][n][alpha];
        ans %= kMod;
    }
    cout << ans << endl;
}
