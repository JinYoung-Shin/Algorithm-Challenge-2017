#include <bits/stdc++.h>
using namespace std;

int price[1001];
int dp[1001]; //dp[i] - i개 붕어빵을 팔 때 최대 수익

int solve(int n) {
    if (n <= 0) return 0;
    if (dp[n]) return dp[n];
    int ret = 0;
    for (int size = 1; size <= n; size++) {
        ret = max(ret, solve(n-size) + price[size]);
    }
    return dp[n] = ret;
    
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<= n; i++) {
        cin >> price[i];
    }
    cout << solve(n) << '\n';
	return 0;
}

