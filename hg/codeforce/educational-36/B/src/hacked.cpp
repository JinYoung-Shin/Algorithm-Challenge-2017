#include <bits/stdc++.h>
using namespace std;

inline int abs(int n) {
    if (n<0) return -n;
    return n;
}
int main() {
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    
    int ans = 0;
    if (l > 1) {
        ans += 1 + abs(pos-l);
        pos = l;
    }
    if (r < n) {
        ans += 1 + abs(r-pos);
    }

    cout << ans << endl;
	return 0;
}