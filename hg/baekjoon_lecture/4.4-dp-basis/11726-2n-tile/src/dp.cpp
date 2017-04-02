#include <cstdio>
#include <iostream>

using namespace std;

long long n;

long long dp[1001];

long long get(long long n) {
	long long ret = 0;
	if (n==0) {
		return 1;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	
	ret = (get(n-1) + get(n-2)) % 10007;
	dp[n] = ret;
	return ret;
}
int main() {

	dp[1] = 1;
	dp[2] = 2;
	scanf("%lld\n", &n);
	
	cout << get(n) << endl;
	
}