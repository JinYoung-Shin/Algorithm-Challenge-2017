#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int DP[1000000];

int main() {
	scanf("%d", &N);
	DP[1] = 0;
	for(int i = 2; i <= N; i++) {
		DP[i] = DP[i-1] + 1;
		if(i%2 == 0) {
			DP[i] = min(DP[i], DP[i/2] + 1);
		}
		if(i%3 == 0) {
			DP[i] = min(DP[i], DP[i/3] + 1);
		}
	}
	
	printf("%d", DP[N]);
	
	return 0;
}