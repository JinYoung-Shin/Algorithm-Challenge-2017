#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

//양팔 저울 
int N, arr[20], T, t[15], sol, n;

void dfs(int n, int left, int right) {
	if(n > N) {
		if(left == right) sol = 1;
		return;
	}
	if(sol) {
		return;
	}
	
	dfs(n+1, left + arr[n], right); // l
	dfs(n+1, left, right + arr[n]); // R
	dfs(n+1, left, right); // X
}

int main(void) {
	scanf("%d", &N);
	for(int i = 1; i <=N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &T);
	n = 0; 
	while (T--) {
		scanf("%d", &t[n]);
		sol = 0;
		dfs(1, 0, t[n++]);
		if (sol == 1) printf("Y ");
		else printf("N ");
	}
	
	return 0;
}