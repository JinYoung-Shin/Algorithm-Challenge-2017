#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
// typedef long long ld;

int n, m;
ld dp[1001][2001]; //i일동안 j미터 왔을 경우, n일 이내에 m미터 갈 수 있는 확률
ld get(int day, int meter) {
    if (day <= m and meter >= n) {
        return 1;
    } else if (day > m or (m-day)*2 < (n-meter)) {
        return 0;
    }
    ld& ret = dp[day][meter];
    
    if (dp[day][meter] != 0) {
        return ret;
    }
    return ret = 0.25 * get(day+1, meter+1) + 0.75 * get(day+1, meter+2);
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        
        cin >> n >> m; //depth, day
        memset(dp, 0, sizeof(dp));
        ld ans = get(0, 0);
        printf("%.10Lf\n", ans);
    }
	return 0;
}

