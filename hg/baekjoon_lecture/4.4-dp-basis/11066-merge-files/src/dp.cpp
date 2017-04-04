#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int dp[505][505];
vector<int> arr;
vector<int> sum;

int get(int from, int to) {
	if (dp[from][to] != -1) {
		return dp[from][to];
	}
	if (from == to) {
		dp[from][to] = 0;
		return dp[from][to];
	}
	if (to - from == 1) {
		dp[from][to] = arr[from] + arr[to];
		return dp[from][to];
	}
	
	int val = 987654321;
	
	for (int i= from; i < to; i++) {
		int tmp = get(from,i) + get(i+1, to);
		val = min(val, tmp);
	}
	val += (sum[to] - sum[from - 1]);
	dp[from][to] = val;
	return val;
}
int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		int summation = 0;
		cin >> n;
		arr.reserve(n+1);
		sum.reserve(n+1);
		arr.push_back(0);
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=n;j++) {
				dp[i][j] = -1;
			}
		}
		
		for(int i=0; i < n;i++) {
			int temp;
			sum.push_back(summation);
			cin >> temp;
			summation += temp;
			arr.push_back(temp);
		}
		sum.push_back(summation);
		cout << get(1, n) << endl;
		
		arr.clear();
		sum.clear();
		
	}
}