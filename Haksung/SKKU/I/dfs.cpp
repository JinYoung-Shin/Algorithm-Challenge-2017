#include <cstdio>

int map[10][10], sol;

int check(int i, int j, int val) {
	int m, n;
	if(map[i][j] != 0)	return 1;
	for(int k=0; k<9; k++) {
		if(map[k][j] == val)	return 0;
		if(map[i][k] == val)	return 0;
	}
	m = (i/3) * 3; n = (j/3) * 3;
	for(int p=m; p<m+3; p++)
		for(int q=n; q<n+3; q++)
			if(map[p][q] == val)	return 0;
	map[i][j] = val;
	return 2;
}

void dfs(int i, int j) {
	int tmp;
	if(sol)	return;
	if(i > 8) {
		sol = 1; return;
	}
	if(j > 8)	dfs(i+1, 0);
	for(int k=1; k<10; k++) {
		tmp = check(i, j, k);
		if(tmp == 1) {
	 		dfs(i, j+1);	break;
		}
		else if(tmp == 2) {
			dfs(i, j+1);
			if(sol)	return;
			map[i][j] = 0;
		}
	}
}

int main() {
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			scanf("%d", &map[i][j]);
	dfs(0, 0);
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

	return 0;
}
