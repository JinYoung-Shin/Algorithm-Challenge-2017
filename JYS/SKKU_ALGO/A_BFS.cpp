#include <iostream>
#include <cstdio>

using namespace std;

int N;
int arrr[110][110];
int sum[110][110];

int sol;
int Min = 999999;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int rp, wp;

struct point {
	int x, y;
};

struct point Que[100 * 100 * 100];

int bfs(void) {
	int r, c, rr, cc, cur_sum;
	sum[1][1] = arrr[1][1];

	Que[wp].x = 0;
	Que[wp].y = 0;
	wp++;
	while(rp < wp) {
		if(rp == wp) {
			return sum[N][N];	
		}
		r = Que[rp].x;
		c = Que[rp].y;
		rp++;
		for(int i = 0; i < 4; i++) {
			rr = r + dx[i];
			cc = c + dy[i];
			if(rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
			if(sum[r][c] + arrr[rr][cc] < sum[rr][cc]) {
				sum[rr][cc] = sum[r][c] + arrr[rr][cc];
			}
			Que[wp].x = rr;
			Que[wp].y = cc;
			wp++;
		}
	}
}

int main() {
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%1d", &arrr[i][j]);
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			sum[i][j] = Min;
		}
	}
	
	sol = bfs();
	
	cout << sol << endl;
	
    return 0;
}
