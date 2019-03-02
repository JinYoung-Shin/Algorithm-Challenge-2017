#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii dp[101][101]; // dp[i][j]까지 가는데 최대값 - first / 그 개수 - second
int val[101][101];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0; i < n; i++) {
            for(int j=0; j <= i; j++) {
                cin >> val[i][j];
            }
        }
        

        dp[0][0].first = val[0][0];
        dp[0][0].second = 1;
        for (int i=1; i < n; i++) {
            for (int j=0; j <= i; j++) {
                if (j == 0) { //바로 위에서만 내려올 수 있다.
                    dp[i][j].first = dp[i-1][j].first + val[i][j];
                    dp[i][j].second = dp[i-1][j].second;
                } else {
                    auto& up = dp[i-1][j]; //바로 위
                    auto& left = dp[i-1][j-1]; //왼쪽 위
                    auto& here = dp[i][j];
                    if (up.first == left.first) {
                        here.first = up.first + val[i][j];
                        here.second = up.second + left.second;
                    } else if (up.first > left.first) {
                        here.first = up.first + val[i][j];
                        here.second = up.second;
                    } else { // up.first < left.first
                        here.first = left.first + val[i][j];
                        here.second = left.second;
                    }
                }
            }
        }
        
        int max_val = -987654321;
        for (int i=0; i < n; i++) {
            max_val = max(max_val, dp[n-1][i].first);
        }
        int ans = 0;
        for (int i=0; i < n; i++) {
            if (dp[n-1][i].first == max_val) {
                ans += dp[n-1][i].second;
            }
        }
        cout << ans << endl;
        // cout << max_val << endl;
        // for (int i=0; i < n; i++) {
        //     for (int j=0; j <= i ;j++) {
        //         cout << '(' << dp[i][j].first <<',' << dp[i][j].second << ')' << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << dp[n-1][n-1].second << '\n';
        
    }
	return 0;
}

