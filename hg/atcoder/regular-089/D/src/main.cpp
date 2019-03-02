#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll white_map[2001][2001];
ll black_map[2001][2001];
ll n, k;
ll k2;

inline ll get_white(int x, int y) {
    if (x < 0 or y < 0 or x >= k2 or y >= k2) return 0LL;
    return white_map[x][y];
}
inline ll get_black(int x, int y) {
    if (x < 0 or y < 0 or x >= k2 or y >= k2) return 0LL;
    return black_map[x][y];
}
inline ll get_white_range(int sx, int sy, int dx, int dy) {
    if (dx < sx or dy < sy) return 0LL;
    return get_white(dx, dy) - get_white(dx, sy-1) - get_white(sx-1, dy) + get_white(sx-1, sy-1);
}
inline ll get_black_range(int sx, int sy, int dx, int dy) {
    if (dx < sx or dy < sy) return 0LL;
    return get_black(dx, dy) - get_black(dx, sy-1) - get_black(sx-1, dy) + get_black(sx-1, sy-1);
}
int main() {
    

    cin >> n >> k;
    k2 = k*2;
    for (int i=0; i<n; i++) {
        ll x, y;
        char color;
        scanf("%lld %lld %c\n", &x, &y, &color);
        x %= k2;
        y %= k2;
        // printf("(%d, %d)\n", x, y);
        if (color == 'W') {
            white_map[x][y]++;
        } else {
            black_map[x][y]++;
        }
    }
    for (ll i=0; i<k2-1; i++) {
        for (ll j=0; j <k2; j++) {
            white_map[i+1][j] += white_map[i][j];
            black_map[i+1][j] += black_map[i][j];
        }
    }
    for (ll i=0; i<k2; i++) {
        for (ll j=0; j <k2-1; j++) {
            white_map[i][j+1] += white_map[i][j];
            black_map[i][j+1] += black_map[i][j];
        }
    }
    
    ll ans = 0;
    for (ll i=0; i < k; i++) {
        for (ll j=0; j < k; j++) {
            ll local_ans = get_white_range(0,0, i-1, j-1);
            local_ans += get_white_range(i, j, i+k-1, j+k-1);
            local_ans += get_white_range(i+k, j+k, k2-1, k2-1);
            local_ans += get_white_range(0, j+k, i-1, k2-1);
            local_ans += get_white_range(i+k, 0, k2-1, j-1);
            local_ans += get_black_range(i, j+k, i+k-1, k2-1);
            local_ans += get_black_range(0, j, i-1, j+k-1);
            local_ans += get_black_range(i+k, j, k2-1, j+k-1);
            local_ans += get_black_range(i, 0, i+k-1, j-1);
            ans = max(ans, local_ans);
        }
    }
    for (ll i=0; i < k; i++) {
        for (ll j=0; j < k; j++) {
            ll local_ans = get_black_range(0,0, i-1, j-1);
            local_ans += get_black_range(i, j, i+k-1, j+k-1);
            local_ans += get_black_range(i+k, j+k, k2-1, k2-1);
            local_ans += get_black_range(0, j+k, i-1, k2-1);
            local_ans += get_black_range(i+k, 0, k2-1, j-1);
            local_ans += get_white_range(i, j+k, i+k-1, k2-1);
            local_ans += get_white_range(0, j, i-1, j+k-1);
            local_ans += get_white_range(i+k, j, k2-1, j+k-1);
            local_ans += get_white_range(i, 0, i+k-1, j-1);
            ans = max(ans, local_ans);
        }
    }
    
    cout << ans << '\n';
    return 0;
}

