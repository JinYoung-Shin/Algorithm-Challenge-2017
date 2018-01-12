#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tri[101][101];
ll dp[101][101]; // (i, j) ~ (n-1, ?) 의 합 최대값 - forward 방식
int n;
ll get(int x, int y) { //
    if (x == n-1) return tri[x][y]; //기저사례
    
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = tri[x][y] + max(get(x+1, y), get(x+1, y+1));
}
int main() {
    int t;
    cin >> t;
    while(t--) {

        cin >> n;
        for (int i=0; i < n; i++) {
            for (int j=0; j <= i; j++) {
                cin >> tri[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << get(0, 0) << endl;
    }
	return 0;
}

