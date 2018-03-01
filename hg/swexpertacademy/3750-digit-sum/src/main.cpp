#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll process(ll n) {
    if (n < 10) return n;
    ll next = 0;
    while (n > 0) {
        next += n % 10;
        n /= 10;
    }
    while (next >= 10) {
        next = process(next);
    }
    return next;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int c=1; c <= t; c++) {
        printf("#%d ", c);
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", process(n));
    }
	return 0;
}

