#include <bits/stdc++.h>
using namespace std;

#define IMPOSSIBLE -987654321
typedef long long ll;
int dp[101][100001]; //[range][minute left]
int walk_min[101];
int walk_get[101];
int bicy_min[101];
int bicy_get[101];
int n, k;
int get(int segment, int minute_left) {
    if (segment >= n) return 0;
    if (minute_left <= 0) return IMPOSSIBLE;
    int& ret = dp[segment][minute_left];
    if (ret != -1) {
        return ret;
    };
    
    ret = IMPOSSIBLE;
    if (minute_left >= walk_min[segment] and get(segment+1, minute_left - walk_min[segment]) != IMPOSSIBLE) {
        ret = max(ret, get(segment+1, minute_left - walk_min[segment]) + walk_get[segment]);
    }
    if (minute_left >= bicy_min[segment] and get(segment+1, minute_left - bicy_min[segment]) != IMPOSSIBLE) {
        ret = max(ret, get(segment+1, minute_left - bicy_min[segment]) + bicy_get[segment]);
    }
    return ret;
    
}

int main() {

    scanf("%d %d", &n, &k);
    for (int i=0; i < n; i++) {
        scanf("%d %d %d %d", &walk_min[i], &walk_get[i], &bicy_min[i], &bicy_get[i]);    
    }
    memset(dp, -1, sizeof(dp));
    
    cout << get(0, k) << '\n';
	return 0;
}

