#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i <= n/2; i++) {
        int rest = n - i;
        if (rest >= i and rest % i == 0) ans++;
    }
    cout << ans << '\n';
	return 0;
}

