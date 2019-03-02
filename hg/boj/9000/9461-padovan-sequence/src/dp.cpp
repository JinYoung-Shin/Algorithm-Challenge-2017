#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[106];
int main() {
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    for (int i=5; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp-1] << endl;
    }
	return 0;
}

