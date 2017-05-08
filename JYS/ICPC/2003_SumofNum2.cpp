#include <cstdio>
#include <iostream>

using namespace std;

int N, M;
int arr[10010];
int lp = 0;
int rp = 0;
int ans = 0;

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int sum = arr[0];	
	while(lp <= rp && rp < N) {
		if(sum < M) {
			rp++;
			sum += arr[rp];
		} else if (sum == M) {
			ans++;
			rp++;
			sum += arr[rp];
		} else if (sum > M) {
			sum -= arr[lp];
			lp++;
		}
	}
	printf("%d", ans);
	return 0;
}

// 투 포인터 lp, rp를 이용하여 푸는 문제 !!!