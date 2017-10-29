#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

char str[100002];
pii dp[100002];
int main() {
	int n;
	scanf("%d\n%s\n", &n, &str[1]);
	int ans = 0;
	int num_0 = 0;
	int num_1 = 0;
	for (int i=1; i <= n; i++) {
		if (str[i] == '1') num_1++;
		else if (str[i] == '0') num_0++;
		dp[i].first = num_0;
		dp[i].second = num_1;
	}
	int total_num_0 = dp[n].first;
	int total_num_1 = dp[n].second;
	if (total_num_0 == total_num_1) {
		cout << n << endl;
		return 0;
	}
	int max_len = min(total_num_0, total_num_1) * 2;
	for (int i=1; i <= n-1; i++) {
		// for (int j=i+1; j <= n; j++) {
		for (int j = min(n, i+max_len); j > i; j--) {
			int current_num_0 = dp[j].first - dp[i-1].first;
			int current_num_1 = dp[j].second - dp[i-1].second;
			if (current_num_0 == current_num_1) {
				if (ans < j-i+1) {
					ans = j-i+1;
					break;
				}
				// ans = max(ans, j-i+1);
			}
		}
	}
	cout << ans << endl;
}