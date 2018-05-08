#include <bits/stdc++.h>
using namespace std;

int dp[1001]; //dp[i] -> i번째 값을 마지막으로 하는 subsequence중 수열의 합의 최대값
int arr[1001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> arr[i];
        dp[i] = arr[i]; //길이가 1인 경우로 초기화
    }
    for (int i=0; i < n; i++) {
        int& last_val = arr[i];
        for (int j=0; j < i; j++) {
            int& target_val = arr[j];
            if (last_val > target_val) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
	return 0;
}

