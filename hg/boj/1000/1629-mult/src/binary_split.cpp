#include <iostream>

using namespace std;

typedef long long ll;
ll c;
ll bin_split(ll a, ll b) {
	if (b <= 0) return 1;
	if (b == 1) return a;
	ll temp = bin_split(a, b/2);
	ll ret = 1LL * temp * temp % c;
	
	if (b % 2) {
		ret = 1LL * ret * a % c;
	}
	return ret;
}
int main() {
	ll a,b;
	cin >> a >> b >> c;
	// a %= c;
	cout << bin_split(a, b) << endl;
}