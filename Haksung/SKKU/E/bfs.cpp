#include <cstdio>
#include <algorithm>

typedef struct {
	int i, j, v;	
}Q_T;
Q_T Q[50*50 +10];
int N, M, max, wp, rp;
char map[51][51];
int flag[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void flag_init() {
	for(int i=0; i<51; i++)
		for(int j=0; j<51; j++)
			flag[i][j] = 0;
};

void BFS(int a, int b) {
	int si, sj, sv, ni, nj;
	wp = 0; rp = 0; flag_init();
	Q[wp].i = a; Q[wp].j = b, Q[wp++].v = 0; flag[a][b] = 1;
	while(rp < wp) {
		si = Q[rp].i; sj = Q[rp].j; sv = Q[rp++].v;
		for(int i=0; i<4; i++) {
			ni = si + dx[i]; nj = sj + dy[i];
			if(ni<1 || ni>N || nj<1 || nj>M)	continue;
			if(map[ni][nj] != 'L' || flag[ni][nj] == 1)	continue;
			Q[wp].i = ni; Q[wp].j = nj; Q[wp++].v = sv+1; flag[ni][nj] = 1;
		}
	}
	if(Q[wp-1].v > max)	max = Q[wp-1].v;
};

int main() {
	char tmp;
	// input
	scanf("%d %d ", &N, &M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++)
			scanf("%c", &map[i][j]);
		scanf("%c", &tmp);
	}
	// execute bfs
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(map[i][j] == 'L')
				BFS(i, j);
	printf("%d", max);

	return 0;
}
