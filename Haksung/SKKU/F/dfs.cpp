#include <cstdio>
#include <cstdlib>

int N, M, map[11][11], money[15], sol[15], flag_s[15], flag_m[15], fin;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
};

bool check() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(map[i][j] && flag_s[i] && flag_s[j])
				if(sol[i] <= sol[j])	return false;
		}
	}
	return true;
};

void dfs(int n) {
	if(fin) return;
	if(n > N) {
		fin = 1;
		return;
	}
	for(int i=2; i<=N; i++) {
		if(flag_m[i])	continue;
		sol[n] = money[i];
		flag_m[i] = 1;
		flag_s[n] = 1;
		if(check()) {
			dfs(n+1);
			if(fin)	return;
		}
		flag_m[i] = 0;
		flag_s[n] = 0;
	}
};

int main() {
	int t1, t2;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++) {
		scanf("%d %d", &t1, &t2);
		map[t1][t2] = 1;
	}
	for(int i=1; i<=N; i++)
		scanf("%d", &money[i]);
	qsort (money+1, N, sizeof(int), compare);	
	sol[1] = money[1]; flag_s[1] = 1; flag_m[1] = 1;
	dfs(2);
	for(int i=1; i<=N; i++)
		printf("%d ", sol[i]);

	return 0;
}
