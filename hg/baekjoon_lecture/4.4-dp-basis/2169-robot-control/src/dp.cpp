#include <bits/stdc++.h>
using namespace std;

int field[1005][1005];
int dp[1005][1005];
bool chk[1005][1005];
int n, m;
int get(int i, int j) {
    static int cnt = 1;
    if (chk[i][j]) return dp[i][j];
    printf("(%d, %d) - %d\n", i, j, cnt++);
    auto& ret = dp[i][j];
    if (i != 0) { //맨윗줄이 아니면?
        ret = max(ret, get(i-1, j));
    }
    if (j != 0) { //맨 왼쪽이 아니면?
        ret = max(ret, get(i, j-1));
    }
    if (j != m-1) { //맨 오른쪽이 아니면?
        ret = max(ret, get(i, j+1));
    }
    chk[i][j] = true;
    ret += field[i][j];
    return ret;
}
int main() {
    
    cin >> n >> m;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    
    dp[0][0] = field[0][0];
    chk[0][0] = true;
    for (int i=0; i < m; i++) {
        dp[0][i+1] = dp[0][i] + field[0][i];
        chk[0][i+1] = true;
    }
    
    cout << get(n-1, m-1) << endl;
	return 0;
}

