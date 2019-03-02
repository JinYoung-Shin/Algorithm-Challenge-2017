#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll x = n;
    if (k == 1) {
        cout << (a*(n-1)) << endl;
        return 0;
    } else {
        ll ans = 0;
        while (x != 1) {
            if (x >= k) {
                if (x % k == 0) { //divisible!
                    ll next = x/k;
                    ll decrement = x - next;
                    ll Acost = decrement * a;
                    if (Acost >= b) {
                        ans += b;
                    } else {
                        ans += Acost;
                    }
                    x = next;
                } else { //decrement until divisible
                    ll next = x / k * k;
                    ll decrement = x - next;
                    ll Acost = decrement * a;
                    x = next;
                    ans += Acost;
                }
            } else { //decrement until 1
                ans += a * (x-1);
                x = 1;
            }
        }
        cout << ans << endl;
    }
	return 0;
}

