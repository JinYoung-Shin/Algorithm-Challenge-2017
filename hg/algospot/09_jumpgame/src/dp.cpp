#include <bits/stdc++.h>
using namespace std;

int field[101][101];

bool dp[101][101];
int chk[101][101];
int n; 
inline bool is_in(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < n;
}
bool get(int x, int y, int tc) { // x, y 에서 목적지로 도달할 수 있는지를 확인하는 함수

    if (x == n-1 and y == n-1) return true;
    if (chk[x][y] == tc) return dp[x][y];
    
    bool ret = false; 
    int jmp = field[x][y];
    if (is_in(x+jmp, y)) {
        ret |= get(x+jmp, y, tc);    
    }
    if (is_in(x, y+jmp)) {
        ret |= get(x, y+jmp, tc);
    }
    
    chk[x][y] = tc;
    return (dp[x][y] = ret);
}
int main() {
    int t;
    cin >> t;
    memset(chk, -1, sizeof(chk));
    for (int k=0; k < t; k++) {
        
        cin >> n;
        for (int i=0; i <n; i++) {
            for (int j=0; j < n; j++) {
                cin >> field[i][j];
            }
        }
        cout << (get(0, 0, k) ? "YES" : "NO") << '\n';
    }
    return 0;
}