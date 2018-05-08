#include <bits/stdc++.h>

using namespace std;

#define R 0
#define G 1
#define B 2
int cost[1001][3];
int dp[1001][3]; // dp[i][j] i개의 집을 칠하고 마지막 집 색이 j일 때 최소 비용
int n;
int main() {
    cin >> n;
    for (int i=0; i<n ;i++){
        for (int j=0; j < 3;j++) {
            cin >> cost[i][j];
        }
    }
    
    for (int i=0; i < 3; i++)
        dp[0][i] = cost[0][i];
    for (int i=1; i < n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    int ans = dp[n-1][0];
    ans = min(dp[n-1][1], ans);
    ans = min(dp[n-1][2], ans);
    cout << ans << '\n';
    return 0;
}