#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

#define NUM_CHAR 26
#define MOD 1000000007

ll dp[1002][1002][NUM_CHAR];
char str[1010];


int main() {

	cin >> (str);
	int n = strlen(str);
    for (int dist=0; dist < n; dist++) {
        for (int l=0; l <= n - dist-1; l++) {
            int r = l + dist;
			for (int sigma=0; sigma < NUM_CHAR; sigma++) {
			    if (l == r) {
			        if (str[l] == sigma+'a')
		                dp[l][r][sigma] = 1;
			    } else if (str[l] != sigma + 'a' or str[r] != sigma + 'a') {
			        dp[l][r][sigma] = dp[l+1][r][sigma] + dp[l][r-1][sigma] - dp[l+1][r-1][sigma];
					dp[l][r][sigma] %= MOD;
			    } else if (str[l] == sigma + 'a' and str[r] == sigma + 'a') {
			        dp[l][r][sigma] = 2;
			        for (int alpha=0; alpha < NUM_CHAR; alpha++) {
			            dp[l][r][sigma] += dp[l+1][r-1][alpha];
						dp[l][r][sigma] %= MOD;
			        }
			    }
			}
		}
	}
	ll ans = 0;
	for(int i=0; i < NUM_CHAR; i++) {
		ans += dp[0][n-1][i];
		ans %= MOD;
	}
	cout << ans << '\n';
	

	return 0;
}
