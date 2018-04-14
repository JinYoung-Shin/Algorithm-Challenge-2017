#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e5+5;
int arr[sz];
ll accu[sz];
inline ll range(int s, int d) {
    return accu[d] - accu[s-1];
}
int main() {
    int n, p;
    ll S = 0;
    cin >> n >> p;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
        accu[i] = accu[i-1] + arr[i];
    }
    for (int k=1; k < n; k++) {
        ll lhs = range(1, k) % p;
        ll rhs = range(k+1, n) % p;
        S = max(S, lhs + rhs);
    }
    cout << S << endl;
	return 0;
}

