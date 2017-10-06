#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ll a, b, ans;
	cin >> a >> b;
	if (b-a >= 10) {
		cout << 0 << endl;
		return 0;
	}
	ans = 1;
	// b %= 10;
	// a %= 10;
	for (ll k = b; k > a; k--) {
		ans *= k;
		ans %= 10;
	}
	cout << ans << endl;
}