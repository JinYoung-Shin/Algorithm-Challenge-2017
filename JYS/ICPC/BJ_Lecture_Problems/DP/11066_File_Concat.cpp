#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, K;
int arr[510];
int sum[510] = {0};
int dp[510][510] = {-1}; // i ~ j 까지의 합 
int temp;

int go(int i, int j) {
	if(i == j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	int &ans = dp[i][j]; // dp[i][j] 직접 수정 가능
	for(int k = i; k < j; k++) {
		temp = go(i, k) + go(k+1, j) + sum[j] - sum[i-1];
		// if temp < ans => ans = temp.
		if(ans > temp || ans == -1) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d", &K);
		memset(sum, 0, sizeof(sum));
		memset(dp, -1, sizeof(dp));
		dp[1][1] = 0;
		for(int i = 1; i <= K; i++) {
			scanf("%d", &arr[i]);
			sum[i] = sum[i-1] + arr[i];
		}
		
		int ans = go(1, K);
		printf("%d\n", ans);
	}	
	return 0;
}