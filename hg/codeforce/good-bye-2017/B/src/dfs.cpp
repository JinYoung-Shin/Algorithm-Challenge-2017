#include <bits/stdc++.h>
using namespace std;

char field[51][51];
int n, m;
const int dx[] = {+0, +0, +1, -1};
const int dy[] = {-1, +1, +0, +0};
int mapped[4];
int ans;
int sx, sy;
bool chk[4];
string cmd;
inline bool is_in(int x, int y) {
    return x>=0 && y>=0 && x<n && y<m;
}
void dump_map() {
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}
bool test() {
    int x = sx;
    int y = sy;
    for (size_t i =0; i < cmd.length(); i++) {
        int val = mapped[cmd[i] - '0'];
        int nx = x + dx[val];
        int ny = y + dy[val];
        if (is_in(nx, ny)) {
            if (field[nx][ny] == '#') return false;
            if (field[nx][ny] == 'E') return true;
            x = nx;
            y = ny;
        } else {
            return false;
        }
    }
    return false;
}
void dfs(int k) {
    if (k >= 4) {
        if (test()) ans++;
        // printf("{%d, %d, %d, %d}\n", mapped[0], mapped[1], mapped[2], mapped[3]);
        // printf("{%d, %d}\n", mapped[0], mapped[1]);
        return;
    }
    for (int i=0; i < 4; i++) {
        if (chk[i] == false) {
            chk[i] = true;
            mapped[k] = i;
            dfs(k+1);
            chk[i] = false;
        }
    }
}
int main() {
    scanf("%d %d\n", &n, &m);
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            scanf("%c", &field[i][j]);
            if (field[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
        scanf("\n");
    }
    cin >> cmd;
    // dump_map();
    dfs(0);
    cout << ans << '\n';
    return 0;
    
}