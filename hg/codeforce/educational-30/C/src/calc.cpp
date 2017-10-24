#include <iostream>
#include <cstdio>
using namespace std;

int mat[101][101];
int dp[101][101];
int main() {
	int n, m ,k;
	int max_val = 0, min_switch = 0;
	cin >> n >> m >> k;
	
	for (int i=1; i <= n; i++) {
		for (int j=1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int col = 1; col <= m; col++) {
		for (int i=1; i <= n; i++) {
			if (mat[i][col] == 1) {
				dp[i][col] = dp[i-1][col] + 1;
			} else if (mat[i][col] == 0) {
				dp[i][col] = dp[i-1][col];
			}
		}
	}

	for (int col = 1; col <= m; col++) {
		if (dp[n][col] == 0) continue;
		int min_switch_val = 0;
		int num_switch = -1;
		int num_val = 0;
		// for (int i=0; i < n; i++) {
		int i=1;
		while( i <= n ) {
			if (mat[i][col] == 1) {
				num_switch++;
				int current_val = dp[min(n,i+k-1)][col] - dp[i-1][col];
				if (num_val < current_val) {
					// printf("dp[%d][%d]~dp[%d][%d] val : %d\n", min(n,i+k-1), col, i, col, current_val);
					min_switch_val = num_switch;
					num_val = current_val;
				}
				// i += current_val;
				i++;
			} else {
				i++;
			}
		}
		// printf("column number %d, max_val %d, min_switch %d\n", col, max_val, min_switch);
		min_switch += max(0, min_switch_val);
		max_val += max(0, num_val);
	}
	cout << max_val << ' ' << min_switch << endl;
}