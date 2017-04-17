#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int DP[1000000];
int temp[1000000];
int num;

int main() {
	scanf("%d", &N);
	DP[0] = 1;
	DP[1] = 1;
	for(int i = 2; i <= N; i++) {
		DP[i] = DP[i-1] + DP[i-2];
		DP[i] %= 10007;
	}
	printf("%d\n", DP[N]);
	return 0;
}