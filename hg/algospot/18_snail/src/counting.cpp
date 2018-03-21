#include <bits/stdc++.h>
using namespace std;

int bicof[1001][1001];

int ncr(int n, int r) { // nCr - bicofficient(이항계수)
    if (n == r) return 1;
    if (r == 0) return 1;
    if (n <= 0 or r < 0) return 0;
    if (n < r) return 0;
    auto &ref = bicof[n][r];
    if (ref == 0) {
        ref = ncr(n-1, r) + ncr(n-1, r-1);
    }
    return ref;
}
long double get_prob(int n, int k) {//n일 중 k일 동안 비가 올 확률
    long double ans = 1L;
    int i;
    for (i=0; i < k; i++) {
        ans *= 0.75L;
    }
    for (;i < n; i++) {
        ans *= 0.25L;
    }
    ans *= ncr(n, k);
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long double ans;
        if (n <= m) {
            ans = 1;
        } else if (n > 2 * m) {
            ans = 0;
        } else {
            ans = 0;
            for (int i = n-m; i <= m; i++) {
                ans += get_prob(m, i);    
            }
        }
        printf("%.10Lf\n", ans);
    }
	return 0;
}

