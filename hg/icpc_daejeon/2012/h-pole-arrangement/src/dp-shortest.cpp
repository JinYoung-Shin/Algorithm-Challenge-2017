#include <iostream>

using namespace std;

long long dp[25][25][25];

long long get(int n, int l, int r) {
	if (n <0 || l < 0 || r < 0) {
		return 0;
	}
	if (n==0 && l==0 && r==0) {
		return 1;
	}
	if (n==1 && l==1 && r==1) {
		return 1;
	}
	if (n == r && l == 1) {
		return 1;
	}
	if (n == l && r == 1) {
		return 1;
	}
	
	return dp[n][l][r];
}
int main() {
	
	for (int n = 1; n <= 20; n++) {
		for (int l = 1; l <= 20; l++) {
			for (int r = 1; r <= 20; r++) {
				dp[n+1][l+1][r] += get(n, l, r);
				dp[n+1][l][r+1] += get(n, l, r);
				dp[n+1][l][r] += get(n,l,r) * (n-1);
			}
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		int n, l , r;
		cin >> n >> l >> r;
		
		cout << get(n, l, r) << endl;
	}
}