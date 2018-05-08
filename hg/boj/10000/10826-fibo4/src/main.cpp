#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n;
    ll a, b;
    a=0; b=1;
    cin >> n;
    for (int i=2; i<=n; i++) {
        ll next = a+b;
        a=b;
        b=next;
    }
    if (n == 0) cout << a;
    else if (n == 1) cout << b;
    else cout << b;
	return 0;
}

