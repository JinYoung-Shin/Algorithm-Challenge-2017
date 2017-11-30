#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001]; //dp[i][j] ->i번째 수를 포함한 수열의 최장 길이
int n;
int main() {
    cin >> n;
    for (int i=1; i <=n ;i++) {
        cin >> arr[i];
    }
    dp[1] = 1;
    for (int i=1; i <= n; i++) {
        int next = 0;
       for (int j=1; j < i; j++) {
           if (arr[j] < arr[i]) {
               next = max(next, dp[j]);
           }
       }
       dp[i] = next + 1;
    }
    int ans=0;
    for (int i=1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}