#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> dp;
int main() {
	int n;
	cin >> n;
	arr.reserve(n);
	dp.reserve(n);
	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	dp[0] = arr[0];
	for (int i=1; i < n; i++) {
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	}
	int ans = -987654321;
	for (int i=0; i< n; i++) {
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}