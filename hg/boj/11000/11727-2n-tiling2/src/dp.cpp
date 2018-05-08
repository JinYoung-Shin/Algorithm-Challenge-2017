#include <bits/stdc++.h>
using namespace std;

const int mod = 1e4 + 7;
int dp[1001];
int main() {
    dp[0] = 1;
    dp[1] = 2;
    
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i] * 2;
        dp[i+1] %= mod;
        dp[i+2] %= mod;
    }
    
    cout << dp[n-1] << endl;
	return 0;
}

