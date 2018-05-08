#include <bits/stdc++.h>
using namespace std;

int dp[10001][3]; //dp[i][j] - i번째꺼까지 지났고, 최근 j개를 연속 마셨을 때, 마실 수 있는 최대 양
int arr[10001];
int n;

int get(int i, int j) {
    if (i < 0 or j < 0 or j > 2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int ret = 0;
    if (j == 0) { //이번 i번째꺼를 안먹어야한다.
        ret = max(get(i-1, 2), ret);
        ret = max(get(i-1, 1), ret);
        ret = max(get(i-1, 0), ret);
    } else if (j == 1) { //i-1번째꺼를 안먹었어야 한다. i번째꺼는 먹음
        ret = arr[i] + get(i-1, 0);
    } else if (j == 2) { // i-1번째꺼를 먹엇어야 하고, i-2번째꺼는 안먹엇어야함. i번째것도 먹음.
        ret = arr[i] + get(i-1, 1);
    }
    return dp[i][j] = ret;
}
int main() {
    
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    for (int i=0; i < 3; i++) {
        ans = max(ans, get(n-1, i));
    }
    cout << ans << '\n';
	return 0;
}

