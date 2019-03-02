#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, +0, +0, +1 };
const int dy[] = { +0, -1, +1, +0 };

int dp[1001][1001][2]; //len
// bool chk[1001][1001][2]; //visited
bool mm[1001][1001]; //map
int n, m;

bool is_in(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

void dump() {
    for (int i=0; i < n; i++) {
        for (int j=0; j< m; j++) {
            cout << mm[i][j];
        }
        cout << '\n';
    }
}

typedef struct _State {
    int x, y, b;
} State;

int main() {
    queue<State> q;
    cin >> n >> m;
    for (int i=0; i < n; i++) {
        string str;
        cin >> str;
        for (int j=0; j < m; j++) {
            char ch = str[j];
            if (ch == '1') {
                mm[i][j] = true;
            }
        }
    }
    // dump();
    State state;
    state.x = state.y = state.b = 0;
    q.push(state);
    // chk[0][0][0] = true;
    dp[0][0][0] = 1;
    
    while(!q.empty()) {
        State cur = q.front(); q.pop();
        // printf("poped state(%d, %d, %d, %d)\n", cur.x, cur.y, cur.b, cur.len);

        for (int dir=0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            

            if (!is_in(nx, ny)) continue; //out of map
            
            if (mm[nx][ny]) { //wall case
                if (cur.b == 1) continue;
                else if (cur.b == 0) {
                    // if (chk[nx][ny][1] == false) {
                    if (dp[nx][ny][1] == 0) {
                        // chk[nx][ny][1] = true;
                        State next;
                        next.x = nx;
                        next.y = ny;
                        next.b = 1;
                        // next.len = dp[cur.x][cur.y][cur.b] + 1;//cur.len + 1;
                        dp[nx][ny][1] = dp[cur.x][cur.y][cur.b] + 1;
                        q.push(next);
                    }
                }
            } else { //not wall case
                // if (chk[nx][ny][cur.b] == false) {
                if (dp[nx][ny][cur.b] == 0) {
                    // chk[nx][ny][1] = true;
                    State next;
                    next.x = nx;
                    next.y = ny;
                    next.b = cur.b;
                    //next.len = dp[cur.x][cur.y][cur.b] + 1;
                    dp[nx][ny][next.b] = dp[cur.x][cur.y][cur.b] + 1;//next.len;
                    q.push(next);
                }
            }

        }
    }
    
    // if (chk[n-1][m-1][0] and chk[n-1][m-1][1]) {
    if (dp[n-1][m-1][0] and dp[n-1][m-1][1]) {
        cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]);
    // } else if (chk[n-1][m-1][0]) {
    } else if (dp[n-1][m-1][0]) {
        cout << dp[n-1][m-1][0];
    // } else if (chk[n-1][m-1][1]) {
    } else if (dp[n-1][m-1][1]) {
        cout << dp[n-1][m-1][1];
    } else {
        cout << -1;
    }
    cout << '\n';
    
    
    
    return 0;
}