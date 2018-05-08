#include <bits/stdc++.h>
using namespace std;

bool field[50][50];
int t, m, n, k;
const int dx[] = {+1, -1, +0, +0};
const int dy[] = {+0, +0, +1, -1};

void dump() {
    for(int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            cout << (field[i][j] ? "1" : "0") << ' ';
        }
        cout << '\n';
    }
}
pair<int, int> find() {
    for (int i=0;i < m; i++) {
        for (int j=0; j < n; j++) {
            if (field[i][j]) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
inline bool is_in(int x, int y) {
    return x>=0 && y>=0 && x<m && y<n;
}
void dfs(int x, int y) {
    if (field[x][y]) {
        field[x][y] = false;
        for (int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny)) {
                dfs(nx, ny);
            }
        }        
    }
}
int main() {
    
    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        memset(field, 0, sizeof(field));
        while(k--) {
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }
        int cnt = 0;
        while(true) {
            pair<int, int> pos = find();
            if (pos.first == -1) break;
            dfs(pos.first, pos.second);
            cnt++;
        }
        cout << cnt << '\n';
        
        // dump();
    }
}