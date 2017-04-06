#include <stdio.h>

int map[12][12], col[12], N, M;

int check(int num, int color) {
	for(int i=0; i<=num; i++) {
		if(map[i][num] && col[i] == color)
			return 0;
	}
	return 1;
};

int dfs(int num) {
	if(num == N) return 1;
	for(int i=1; i<=M; i++) {
		if(check(num, i)) {
			col[num] = i;
			if(dfs(num+1)) return 1;
		}
	}
	return 0;
};

int main(void) {
	// assigning
	scanf("%d %d ", &N, &M);
	for(int i=0; i<N; i++) {
		for(int j=0; j<=i; j++) {
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
	}
	
	if(dfs(0) != 1)
		printf("-1\n");
	else {
		for(int i=0; i<N; i++)
			printf("%d ", col[i]);
		printf("\n");
	}

	return 0;
}
