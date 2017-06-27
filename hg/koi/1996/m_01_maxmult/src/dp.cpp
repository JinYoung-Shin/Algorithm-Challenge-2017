#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef double vt;

int N;
vector<vt> arr;
vector<vt> dp;
void dump() {
	for (int i=0; i < N; i++) {
		printf("%5f ", arr[i]);
	}
	cout << endl;
	for (int i=0; i < N; i++) {
		printf("%5f ", dp[i]);
	}
	cout << endl;
}
int main() {
	cin >> N;
	
	arr.reserve(N);
	dp.reserve(N+1);
	for (int i=0; i < N; i++) {
		vt val;
		cin >> val;
		arr.push_back(val);
	}
	dp[0] = arr[0];
	for (int i=1; i <= N; i++) {
		if (dp[i-1] > 1) {
			dp[i] = dp[i-1] * arr[i];
		} else {
			dp[i] = arr[i];
		}
	}
	vt max_val = -987654321;
	for (int i=0; i < N; i++) {
		max_val = max(max_val, dp[i]);
	}
	printf("%.3lf\n", max_val);
	
}