#include <cstdio>

int D, N, d[60], t[60], sol = 0x7fffffff;

void DFS(int n, int time, int dis) {
	if (time >= sol)	return;
	if (n > N) {
		if (sol > time) sol = time;
		return;
	}
	// 정비 받기
	DFS(n + 1, time + t[n], d[n]);
	// 그냥 가기
	if (dis + d[n] <= D)	DFS(n + 1, time, dis + d[n]);
};

int main() {
	scanf("%d %d", &D, &N);
	for (int i = 0; i <= N; i++)	scanf("%d", &d[i]);
	for (int i = 1; i <= N; i++)	scanf("%d", &t[i]);
	DFS(1, 0, d[0]);
	printf("%d", sol);

	return 0;
}
