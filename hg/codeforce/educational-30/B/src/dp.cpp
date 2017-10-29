#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int bias[200001];

int main() {
	int n;
	cin >> n;
	int cb = 0; //current bias
	int ans = 0;
	for (int i=1; i <= n; i++) {
		char ch;
		cin >> ch;
		if (ch == '0') {
			cb++;
		} else if (ch == '1') {
			cb--;
		}
		if (cb == 0) {
			ans = max(ans, i);
		} else {
			if (bias[n+cb] == 0) {
				bias[n+cb] = i;
			} else {
				ans = max(ans, i - bias[n+cb]);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}