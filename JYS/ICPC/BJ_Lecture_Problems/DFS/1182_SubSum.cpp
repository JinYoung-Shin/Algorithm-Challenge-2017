#include <cstdio>
#include <iostream>

using namespace std;

int N, S;
int arr[25];
int ans = 0;

void go(int i, int sum) {
	//End case
	if(i == N) {
		if(sum == S) ans++;
		return;
	}
	go(i+1, sum+arr[i]);	
	go(i+1, sum);
}

int main() {
	scanf("%d %d", &N, &S);
	for(int i = 0;  i < N; i++) {
		scanf("%d", &arr[i]);
	}
	go(0, 0);
	if(S == 0) ans--;
	printf("%d\n", ans);
	return 0;
}