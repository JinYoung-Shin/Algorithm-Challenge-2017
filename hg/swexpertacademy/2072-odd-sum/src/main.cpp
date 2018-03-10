#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t; tc++) {
        int ans = 0;
        for (int i=0; i < 10 ;i++) {
            int tmp;
            cin >> tmp;
            if (tmp & 1) {
                ans += tmp;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
	return 0;
}

