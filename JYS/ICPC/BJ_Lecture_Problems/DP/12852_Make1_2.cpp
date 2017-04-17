#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int DP[1000000];
float temp[1000000];

int main() {
	scanf("%d", &N);
	DP[1] = 0;
	for(int i = 2; i <= N; i++) {
		DP[i] = DP[i-1] + 1;
		temp[i] = 1;
		if(i%2 == 0) {
			if(DP[i] > DP[i/2]+1) {
				DP[i] = DP[i/2]+1;
				temp[i] = 1/2;
			}
		}
		if(i%3 == 0) {
			if(DP[i] > DP[i/3]+1) {
				DP[i] = DP[i/3]+1;
				temp[i] = 1/3;
			}
		}
	}
	
	printf("%d\n", DP[N]);
	
	for(int i = 0; i < DP[N]; i++) {
		printf("%d ", N);
		if(temp[N] == 1) {
			N = N - 1;
		} else {
			N = N * temp[N];
		}
	}
	printf("%d\n", N);
	
	return 0;
}