#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][101];
ll A[101];
ll B[101];
int n, m;
const ll NEGINF = numeric_limits<long long>::min();
#define ALL_INDEX 0
ll get(int a, int b) {
    ll& ret = dp[a][b];
    if (ret != -1) return ret;
    ret = 2LL;
    ll target = max(A[a], B[b]);
    for (int i=a+1; i <= n; i++) {
        if (A[i] > target) {
            ret = max(ret, get(i, b) + 1);
        }
    }
    for (int i=b+1; i <= m; i++) {
        if (B[i] > target) {
            ret = max(ret, get(a, i) + 1);
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    A[0] = B[0] = NEGINF;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        
        cin >> n >> m;
        for (int i=1; i <=n; i++) {
            cin >> A[i];
        }
        for (int i=1; i <=m; i++) {
            cin >> B[i];
        }
        cout << get(ALL_INDEX, ALL_INDEX)-2 << '\n';
    }
    
	return 0;
}

