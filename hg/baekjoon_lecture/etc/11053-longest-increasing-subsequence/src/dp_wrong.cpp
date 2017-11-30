#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001][1001]; //dp[i][j] ->i번째까지 마지막 수열이 j값일때 최장 길이
int n;
int main() {
    cin >> n;
    for (int i=1; i <=n ;i++) {
        cin >> arr[i];
    }
    dp[1][arr[1]] = 1;
    for (int i=1; i <= n; i++) {
        int val = arr[i];
        for (int j=1; j < val; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][val] = max(dp[i][val], dp[i-1][j] + 1);
        }
        for (int j=val; j <= 1000; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    /*
    for (int i=2; i <= n; i++) {
        for (int j=1; j < arr[i]; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][arr[i]] = max(dp[i][arr[i]], dp[i-1][j]+1);
        }
        for (int j=arr[i] + 1; j <= 1000; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            // dp[i][j] = dp[i-1][j];
        }
    }
    */
    
    int ans = 0;
    
    // for (int i=1; i <=n; i++) {
    //     for (int j=1; j <= 10; j++) {
    //         printf("dp[%d][%d] = %d ", i, j, dp[i][j]);
    //     }
    //     cout << '\n';
    // }
    for (int i=1; i <= 1000; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
    return 0;
}