#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int D, N, d[60], t[60], sol = 0x7fff0000;

void dfs(int n, int time, int dist) {
	if(time >= sol) return;
	if (n > N) {
		if(sol > time) sol = time;
		return;
	}
	dfs(n+1, time+t[n], d[n]); //정비 받는 경우
	if(dist +d[n] <= D) dfs(n+1, time, dist + d[n]); //정비 받지 않는 경우 
}

int main() {
	scanf("%d %d", &D, &N);
	
	for(int i = 0; i <= N; i++) {
		scanf("%d", &d[i]);
	}	
	for(int i = 1; i <= N; i++) {
		scanf("%d", &t[i]);
	}
	
	dfs(1, 0, d[0]);
	
	printf("%d", sol);
	
	return 0;
}