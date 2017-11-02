#include <bits/stdc++.h>

using namespace std;

int field[1001][1001];
int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i <= n; i++) {
		for (int j=1; j <= m; j++) {
			cin >> field[i][j];
		}
	}
	
	dp[1][1] = field[1][1];
	for (int i=2; i <= n; i++) {
		dp[i][1] = dp[i-1][1] + field[i][1];
	}
	for (int i=2; i <= m; i++) {
		dp[1][i] = dp[1][i-1] + field[1][i];
	}
	for (int i=2; i <= n; i++) {
		for (int j=2; j <= m ;j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + field[i][j];
		}
	}
	
	cout << dp[n][m] << endl;
	////dump
	// for (int i=1; i <= n; i++) {
	// 	for (int j=1; j <= m; j++) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	////dump
}