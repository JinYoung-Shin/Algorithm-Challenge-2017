#include <cstdio>
#include <algorithm>

typedef struct {
    int i, j, d;
}Q_T;

Q_T Q[100 * 100 + 10];
int Rp, Wp, map[110][110], N, M, sol, si, sj, count;
int flag[110][110];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1};
 
int BFS() {
    int ti, tj, td, ni, nj;
    Q[Wp].i = si; Q[Wp].j = sj; Q[Wp++].d = 3; flag[si][sj] = 1; count--;
    while (Rp < Wp) {
        ti = Q[Rp].i; tj = Q[Rp].j; td = Q[Rp++].d;
        for (int i = 0; i < 4; i++) {
            ni = ti + dx[i]; nj = tj + dy[i];
            if (ni<1 || ni>N || nj<1 || nj>M) continue;
            if (map[ni][nj] != 1 || flag[ni][nj] ==1) continue;
            Q[Wp].i = ni; Q[Wp].j = nj; Q[Wp++].d = td+1; flag[ni][nj] = 1; count--;
        }
    }
    return td;
};
 
int main() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) count++;
        }
    }
    scanf("%d %d", &sj, &si);
	sol = BFS();
    printf("%d\n%d", sol, count);
 
    return 0;
}
