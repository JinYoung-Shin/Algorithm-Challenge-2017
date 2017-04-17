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
	DP[2] = 2;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &num);
		for(int i = 3; i <= num; i++) {
			DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
		}
		temp[i] = DP[num];
	}
	for(int i = 1; i <= N; i++) {
		printf("%d\n", temp[i]);
	}
	return 0;
}