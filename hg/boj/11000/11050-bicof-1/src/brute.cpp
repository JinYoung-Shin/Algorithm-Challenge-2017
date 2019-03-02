#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    
    ll ans = 1;
    for (int i=n; i > n-k; i--) {
        ans *= i;
    }
    for (int i=2; i <= k; i++) {
        ans /= i;
    }
    cout << ans;
	return 0;
}

