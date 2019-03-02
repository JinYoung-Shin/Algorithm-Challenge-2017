#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
bool sieve[MAXN];

bool is_prime(int n) {
	if (n <= 1) return false;
	for (int i=2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void make_sieve(int n) {
    sieve[0] = sieve[1] = true;
	for (int i=2; i <= n; i++) {
		if (is_prime(i)) {
			int val = i<<1;
			int base = i;
			while (val < MAXN) {
				sieve[val] = true;
				val += base;
			}
		}
	}
}
int main() {
	make_sieve(MAXN);
	int tc;
	cin >> tc;
	
	while (tc--) {
	    int n; cin >> n;
	    int diff = n;
	    int l, r;
	    for (int i=n-1; i >= 2; i--) {
	        if (!sieve[i] && !sieve[n-i]) {
	            int a = min(n-i, i);
	            int b = max(n-i, i);
	            if (b - a < diff) {
	                diff = b - a;
	                l = a;
	                r = b;
	            }
	        }
	    }
	    cout << l << ' ' << r << '\n';
	}
	return 0;
}

