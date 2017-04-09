#include <cstdio>

int N, M, t[10], s[10], map[40][10], max;

void dfs(int n, int b, int v) {
	if(n > M) {
		if(v > max) {
			for(int i=1; i<=M; i++)
				s[i] = t[i];
			max = v;
		}
		return;
	}
	for(int i=0; i<=b; i++) {
		t[n] = i;
		dfs(n+1, b-i, v+map[i][n]);
	}
};

int main() {
	int tmp;
	// input
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%d ", &tmp);
		for(int j=1; j<=M; j++)
			scanf("%d", &map[i][j]);
	}
	dfs(1, N, 0);
	printf("%d\n", max);
	for(int i=1; i<=M; i++)
		printf("%d ", s[i]);

	return 0;
}
