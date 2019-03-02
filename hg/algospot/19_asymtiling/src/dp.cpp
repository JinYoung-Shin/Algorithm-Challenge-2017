#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;
ll dp[105]; //대칭 비대칭 구분안하는 타일링
int main() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ans = dp[n];
        ll sym;
        
        sym = dp[n/2];
        if (n & 1) {
            sym = dp[n/2]; //중간에 하나만 두고 양쪽이 갈린 경우
        } else {
            sym = dp[n/2] + dp[n/2 - 1]; //반띵한 경우와 가로2개 놔두고 반띵한 경우
        }
        ans -= sym;
        ans %= MOD;
        if (ans < 0) {
            ans += MOD;
        }
        cout << ans << endl;
    }
	return 0;
}

