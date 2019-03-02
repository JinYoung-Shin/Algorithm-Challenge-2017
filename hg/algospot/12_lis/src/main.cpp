#include <bits/stdc++.h>
using namespace std;

int arr[500];
int dp[500]; // dp[x] : x번째 수를 마지막 원소로 가지는 lis의 길이 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0; i < n; i++) {
            cin >> arr[i];
        }
        
        for (int i=0; i < n; i++) {
            dp[i] = 1; //자체가 길이가 1인 sequence이므로
        }
        for (int i=1; i < n; i++) {
            int ith_val = arr[i];
            for (int j=0; j < i; j++) {
                int jth_val = arr[j];
                if (ith_val > jth_val) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int ans = 0;
        for (int i=0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
	return 0;
}

