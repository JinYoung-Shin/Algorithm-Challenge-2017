#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;

int arr[100010];
int DP[100010];

int _Max = 0;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	
	DP[1] = arr[1];
	for(int i = 2; i <= N; i++) {
		DP[i] = max(DP[i-1] + arr[i], arr[i]);
		if(DP[i] > _Max){
			_Max = DP[i];
		}
	}
	printf("%d\n", _Max);
	return 0;
}