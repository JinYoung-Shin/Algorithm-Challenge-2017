#include <iostream>

using namespace std;

long long int dp[201][201];
//dp[a][b] -> a개 수를 더해서 b를 만드는 방법

long long int get(int a, int b) {
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	long long int val = 0;
	for (int i=0;i<=b;i++) {
		val += get(a-1, i);
		val %= 1000000000;
	}
	dp[a][b] = val;
	return val;
}
int main() {
	int N, K;
	
	for (int i=0;i<201;i++) {
		for (int j=0;j<201;j++) {
			dp[i][j] = -1;
		}
	}
	
	cin >> N >> K;
	
	for (int i=0;i<=N; i++) {
		dp[0][i] = 0;
		dp[1][i] = 1;
	}
	dp[0][0] = 1;
	
	// cout << get(K, N) % 1000000000 << endl;
	cout << get(K,N) << endl;
}