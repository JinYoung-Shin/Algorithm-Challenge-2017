#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc_damage(string& p) {
    ll ans = 0;
    ll weight = 1;
    for (size_t i=0; i< p.length(); i++) {
        char c = p[i];
        if (c == 'S') ans += weight;
        else weight <<= 1;
    }
    return ans;
}

ll get_min_damage(string& p) {
    ll ret = 0;
    for (size_t i=0; i < p.length(); i++) {
        char ch  = p[i];
        if (ch == 'S') ret++;
    }
    return ret;
}
void reduce(string& s) {
    for(size_t i=s.length() - 1; i >= 1; i--) {
        char& a = s[i-1];
        char& b = s[i];
        if (a == 'C' and b == 'S') {
            a = 'S';
            b = 'C';
            return;
        }
    }
}
int main() {
    int t;
    cin >> t;
    for(int tc=1; tc <= t; tc++) {
        ll d;
        string p;
        cin >> d >> p;
        int ans = 0;
        if (get_min_damage(p) > d) {
            cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
        } else {
            while(calc_damage(p) > d) {
                // //debug
                // cout << p << endl;
                // //debug
                reduce(p);
                ans++;
            }
            cout << "Case #" << tc << ": " << ans << endl;
        }
    }
	return 0;
}

