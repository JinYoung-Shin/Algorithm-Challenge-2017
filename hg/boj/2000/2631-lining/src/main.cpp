#include <bits/stdc++.h>
using namespace std;

int a[205];
int dp[205];
int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    
    for (int i=1; i < n; i++) {
        for(int j=0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int x = 0;
    for (int i=0; i < n; i++) {
        x = max(x, dp[i]);
    }
    
    cout << (n-x) << endl;
	return 0;
}

