#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int arr[100010];
int DP[100010][100010];

int Max = 0;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		if(arr[i] > Max) Max = arr[i];
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N-i; j++) {
			DP[i][i+j] = DP[i][i+j-1] + arr[j];
			if(DP[i][i+j] > Max) Max = DP[i][i+j];
		}
	}
	
	printf("%d\n", Max);
	
	return 0;
}