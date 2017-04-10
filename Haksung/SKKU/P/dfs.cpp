#include <cstdio>

int N, M, V, sol, W[15];

void dfs(int n, int wei) {
	if(sol)	return;
	if(n > N) {
		if(wei == V)	sol = 1;
		return;
	}
	dfs(n+1, wei);
	dfs(n+1, wei+W[n]);
	dfs(n+1, wei-W[n]);
};

int main() {
	// set weights of choo!
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &W[i]);
	// insert value to check & dfs
	scanf("%d", &M);
	for(int i=1; i<=M; i++) {
		scanf("%d", &V);
		sol = 0;
		dfs(1, 0);
		if(sol)	printf("Y ");
		else	printf("N ");
	}

	return 0;
}
