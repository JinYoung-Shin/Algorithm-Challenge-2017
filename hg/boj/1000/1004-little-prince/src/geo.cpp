#include <bits/stdc++.h>
using namespace std;

int sx, sy, dx, dy;
bool is_in(int x, int y, int r, int sx, int sy) {
    int r2 = r*r;
    int d2 = (sx-x)*(sx-x) + (sy-y)*(sy-y);
    if (r2 > d2) {
        return true;
    } else {
        return false;
    }
}
int check(int x, int y, int r) {
    bool src = is_in(x, y, r, sx, sy);
    bool dst = is_in(x, y, r, dx, dy);
    return src == dst ? 0 : 1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> sx >> sy >> dx >> dy;
        int n;
        cin >> n;
        while(n--) {
            int x, y, r;
            cin >> x >> y >> r;
            ans += check(x, y, r);
        }
        cout << ans << '\n';
    }
    return 0;
}